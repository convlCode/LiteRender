#include "World.h"
#include <iostream>
#include <algorithm>
#include "Tracer/RayCast.h"
#include "Cameras/Pinhole.h"
#include "Sampler/MultiJittered.h"
#include "Sampler/Regular.h"
#include "Lights/Directional.h"
#include "Materials/Matte.h"
#include "Lights/Ambient.h"
#include "Materials/Phong.h"
#include "Lights/Arealight.h"
#include "Tracer/Arealighting.h"
#include "Materials/Emissive.h"
#include "GeometricObjects/Rectangle.h"
#include "GeometricObjects/Plane.h"
#include "Tracer/Pathtracer.h"
#include <QDebug>
World::World()
    :background_color(black),tracer_ptr{nullptr},camera_ptr{nullptr},
     ambient_ptr{new Ambient},image{nullptr},renderProgress{0.0f},stopRender{false}
{
}


World::~World()
{
	if (tracer_ptr) {
		delete tracer_ptr;
		tracer_ptr = nullptr;
	}
	if (camera_ptr) {
		delete camera_ptr;
		camera_ptr = nullptr;
	}
    if(ambient_ptr){
        delete ambient_ptr;
        ambient_ptr = nullptr;
    }
    if(image){
        delete  image;
    }
	delete_objectes();
	delete_lights();
}

void World::build()
{
	int num_samples = 25;
	vp.set_hres(400);
	vp.set_vres(400);
	vp.set_pixel_size(1.0f);
	vp.set_gamma(1.0);
	vp.set_samples(num_samples);
    vp.set_max_depth(10);
    background_color = gray;

    //tracer_ptr = new AreaLighting(this);
    tracer_ptr = new    PathTracer(this);
    MultiJittered* sampler_ptr = new MultiJittered(num_samples);

	Pinhole* pinhole_ptr = new Pinhole;
    pinhole_ptr->set_eye(0.0f, 0.0f, 100.0f);
	pinhole_ptr->set_lookat(Point3D(0.0, 0.0, 0.0));
	pinhole_ptr->set_view_distance(100.0f);
	pinhole_ptr->compute_uvw();
	set_camera(pinhole_ptr);

    Emissive* emissive_ptr = new Emissive;
    emissive_ptr->scale_radiance(80.0);
    emissive_ptr->set_ce(white);

    // define a rectangle for the rectangular light
    double width = 60.0;
    double height = 60.0;
    Point3D center(0.0, 100.0, 40.0);	// center of each area light (rectangular, disk, and spherical)
    Point3D p0(-0.5 * width, center.y - 0.5 * height, center.z);
    Vector3D a(width, 0.0, 0.0);
    Vector3D b(0.0, height, 0.0);
    Vector3D normal(0, -1, -0.8);

    Rectangle* rectangle_ptr = new Rectangle(p0, a, b, normal);
    rectangle_ptr->set_material(emissive_ptr);
    rectangle_ptr->set_sampler(sampler_ptr);
    //	rectangle_ptr->set_shadows(false);
    add_object(rectangle_ptr);

    AreaLight* area_light_ptr = new AreaLight;
    area_light_ptr->set_object(rectangle_ptr);

    //area_light_ptr->set_cast_shadow(true);
    add_light(area_light_ptr);

	RGBColor light_purple(0.65f, 0.3f, 1.0f);
    RGBColor yellow(1, 1, 0);
    float ka = 0.25f;
    float kd = 0.75f;

    // spheres
    Matte* matte_ptr1 = new Matte;
    matte_ptr1->set_ka(ka);
    matte_ptr1->set_kd(kd);
    matte_ptr1->set_cd(yellow);

    Sphere*	sphere_ptr1 = new Sphere(Vector3D(0, -30, 0), 40);
    sphere_ptr1->set_material(matte_ptr1);	   							// yellow

    add_object(sphere_ptr1);

    //down plane
    Matte* matte_ptr9 = new Matte;
    matte_ptr9->set_ka(0.2f);
    matte_ptr9->set_kd(0.1f);
    matte_ptr9->set_cd(green);
    Plane* plane_ptr9 = new Plane(Point3D(0, -60, 0), Vector3D(0, 1, 0));
    plane_ptr9->set_material(matte_ptr9);
    add_object(plane_ptr9);
}


ShadeRec World::hit_objects(const Ray & ray)
{
	ShadeRec	sr(*this);
	double		t;
	Vector3D	normal;
	Point3D		local_hit_point;
	double		tmin = kHugeValue;
    auto 		num_objects = objects.size();

    for (size_t j = 0; j < num_objects; j++)
		if (objects[j]->hit(ray, t, sr) && (t < tmin)) {
			sr.hit_an_object = true;
			tmin = t;
			sr.material_ptr = objects[j]->get_material();
			sr.hit_point = ray.o + ray.d * t;
			normal = sr.normal;
			local_hit_point = sr.local_hit_point;
		}

	if (sr.hit_an_object) {
        sr.t = tmin;
		sr.normal = normal;
		sr.local_hit_point = local_hit_point;
	}

	return sr;
}

RGBColor World::max_to_one(const RGBColor & c) const
{
	float max_value = std::max(c.r, std::max(c.g, c.b) );

    if (max_value > 1.0f)
		return (c / max_value);
	else
        return (c);
}

void World::clearScene(){

    /*
    for (auto it = lights.begin(); it != lights.end(); it++) {
        delete (*it);
    }
    lights.clear();*/

    for (auto it = objects.begin(); it != objects.end(); it++) {
        delete (*it);
    }
    objects.clear();
    if(tracer_ptr){
        delete tracer_ptr;
        tracer_ptr=nullptr;
    }
    if(camera_ptr){
        delete camera_ptr;
        camera_ptr=nullptr;
    }
}
void World::render_scene()
{
    if(image){
        delete image;
    }
    image=new QImage(vp.vres,vp.hres,QImage::Format_RGB888);
    Ray ray;
    RGBColor L;
    Point2D sp; //sample point in [0,1]*[0,1]
    Point2D pp; //sample point on a pixel
    int allPixelNum = vp.hres*vp.vres;
    int currentPixelNum = 0;

    for (int r = 0; r < vp.vres; ++r) {
        for (int c = 0; c < vp.hres; c++) {
            if(stopRender)
                break;
            L=background_color;
            for (int j = 0; j < vp.num_samples; ++j) {
                sp = vp.sampler_ptr->sample_unit_square();
                pp.x = vp.s*(c - 0.5f*vp.hres + sp.x);
                pp.y = vp.s*(r - 0.5f*vp.vres + sp.y);
                ray = camera_ptr->get_ray(pp);
                L += tracer_ptr->trace_ray(ray,0);
            }
            L /= static_cast<float>(vp.num_samples);
            L = max_to_one(L);
            QColor pixColor(int(255.99f*L.r), int(255.99f*L.g), int(255.99f*L.b));
            image->setPixelColor(c,vp.vres-r-1,pixColor);//r is y,c is x
            currentPixelNum++;
            renderProgress = currentPixelNum*100.0f/allPixelNum;
            emit updateProgeress();
        }
    }
    emit renderComolete();
    //clearScene();//没有这一步的话，像素值会增加一倍,因为在renderComplete中会再次调用build
}

void World::delete_objectes()
{
	size_t num_objects = objects.size();

	for (size_t j = 0; j < num_objects; j++) {
		delete objects[j];
		objects[j] = nullptr;
	}
	objects.erase(objects.begin(), objects.end());
}

void World::delete_lights()
{
	size_t num_lights = lights.size();

	for (size_t j = 0; j < num_lights; j++) {
		delete lights[j];
		lights[j] = nullptr;
	}

	lights.erase(lights.begin(), lights.end());
}
