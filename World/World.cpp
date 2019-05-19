#include "World.h"
#include <iostream>
#include <algorithm>
#include "Tracer/RayCast.h"
#include "Cameras/Pinhole.h"
#include "Sampler/MultiJittered.h"
#include "Sampler/Regular.h"
#include "Lights/Directional.h"
#include "Materials/Matte.h"
#include <QDebug>
World::World()
	:background_color(black),tracer_ptr{nullptr},
      camera_ptr{nullptr},image{nullptr},renderProgress{0.0f}
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
    background_color = gray;
	tracer_ptr = new RayCast(this);

	Pinhole* pinhole_ptr = new Pinhole;
    pinhole_ptr->set_eye(0.0f, 0.0f, 100.0f);
	pinhole_ptr->set_lookat(Point3D(0.0, 0.0, 0.0));
	pinhole_ptr->set_view_distance(100.0f);
	pinhole_ptr->compute_uvw();
	set_camera(pinhole_ptr);

	Directional* light_ptr1 = new Directional;
	light_ptr1->set_direction(50.0f, 50.0f, 50.0f);
	light_ptr1->scale_radiance(3.0f);
	add_light(light_ptr1);

	RGBColor light_purple(0.65f, 0.3f, 1.0f);

	Matte* matte_ptr = new Matte;
	matte_ptr->set_kd(0.75f);
	matte_ptr->set_cd(light_purple);
	
    Sphere*	sphere_ptr = new Sphere(Vector3D(0.0, 0.0, -50.0), 100.0);
	sphere_ptr->set_material(matte_ptr);							// light purple
	add_object(sphere_ptr);
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

    for (int r = 0; r < vp.vres; r++) {
        for (int c = 0; c < vp.hres; c++) {
            L=background_color;
            for (int j = 0; j < vp.num_samples; ++j) {
                sp = vp.sampler_ptr->sample_unit_square();
                pp.x = vp.s*(c - 0.5f*vp.hres + sp.x);
                pp.y = vp.s*(r - 0.5f*vp.vres + sp.y);
                ray = camera_ptr->get_ray(pp);
                L += tracer_ptr->trace_ray(ray);
            }
            L /= static_cast<float>(vp.num_samples);
            L = max_to_one(L);
            QColor pixColor(int(255.99f*L.r), int(255.99f*L.g), int(255.99f*L.b));
            image->setPixelColor(r,c,pixColor);
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
