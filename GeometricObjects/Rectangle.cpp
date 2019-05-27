#include "Rectangle.h"

const double Rectangle::kEpsilon = 0.001;

Rectangle::Rectangle()
    :GeometricObject(),p0{-1.0,0.0,-1.0},a{0.0,0.0,2.0},b{2.0,0.0,0.0},
      a_len_squared{4.0},b_len_squared{4.0},normal{0.0,1.0,0.0},area{4.0f},
      inv_area{0.25f},sampler_ptr{nullptr}
{
}

Rectangle::Rectangle(const Rectangle &r)
    :GeometricObject(r),p0(r.p0),a(r.a),b(r.b),a_len_squared(r.a_len_squared),
      b_len_squared(r.b_len_squared),normal(r.normal),area(r.area),
      inv_area(r.inv_area)
{
}

Rectangle::Rectangle(const Point3D &p, const Vector3D &va, const Vector3D &vb)
    :GeometricObject(),p0{p},a{va},b{vb},a_len_squared{va.len_squared()},
      b_len_squared{vb.len_squared()},normal{0.0,1.0,0.0},
      area{static_cast<float>(a.length() * b.length())},
      inv_area{1.0f / area},sampler_ptr{nullptr}
{
}

Rectangle::Rectangle(const Point3D &p, const Vector3D &va, const Vector3D &vb, const Vector3D &nor)
    :GeometricObject(),p0{p},a{va},b{vb},a_len_squared{va.len_squared()},
      b_len_squared{vb.len_squared()},normal{nor},
      area{static_cast<float>(a.length() * b.length())},
      inv_area{1.0f / area},sampler_ptr{nullptr}
{
}

Rectangle::~Rectangle()
{
    if (sampler_ptr) {
            delete sampler_ptr;
            sampler_ptr = nullptr;
    }
}

Rectangle *Rectangle::clone() const
{
    return (new Rectangle(*this));
}

Rectangle &Rectangle::operator=(const Rectangle &rhs)
{
    if (this == &rhs)
        return (*this);

    GeometricObject::operator=(rhs);

    p0				= rhs.p0;
    a				= rhs.a;
    b				= rhs.b;
    a_len_squared	= rhs.a_len_squared;
    b_len_squared	= rhs.b_len_squared;
    area			= rhs.area;
    inv_area		= rhs.inv_area;
    normal			= rhs.normal;

    if (sampler_ptr) {
        delete sampler_ptr;
        sampler_ptr = nullptr;
    }
    if (rhs.sampler_ptr)
        sampler_ptr= rhs.sampler_ptr->clone();

    return (*this);
}

bool Rectangle::hit(const Ray &ray, double &tmin, ShadeRec &sr) const
{
    double t = ( (p0 - ray.o) * normal ) / (ray.d * normal);

    if (t <= kEpsilon)
        return false;

    Point3D p = ray.o + ray.d * t;
    Vector3D d = p - p0;

    double ddota = d * a;

    if (ddota < 0.0 || ddota > a_len_squared)
        return false;

    double ddotb = d * b;

    if (ddotb < 0.0 || ddotb > b_len_squared)
        return false;

    tmin 				= t;
    sr.normal 			= normal;
    sr.local_hit_point 	= p;

    return true;
}

void Rectangle::set_sampler(Sampler *sampler)
{
    sampler_ptr = sampler;
}

Point3D Rectangle::sample()
{
    Point2D sample_point = sampler_ptr->sample_unit_square();
    double px=static_cast<double>(sample_point.x);
    double py=static_cast<double>(sample_point.y);
    return (p0 + (a * px) + (b * py) );
}

Vector3D Rectangle::get_normal(const Point3D &p)
{
    return normal;
}

float Rectangle::pdf(ShadeRec &sr)
{
    return inv_area;
}


