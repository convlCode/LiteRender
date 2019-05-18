#ifndef CAMERA_H
#define CAMERA_H

#include "../BasicTools/Point3D.h" //included Vector3D
#include "BasicTools/Point2D.h"
#include "BasicTools/Ray.h"
class World;

class Camera {
public:

	Camera();   							

	Camera(const Camera& c);					

	virtual ~Camera();

	virtual Camera*	clone(void) const = 0;
    virtual Ray get_ray(Point2D &point) const=0;
    //virtual void render_scene(const World& w) = 0;

	void set_eye(const Point3D& p);

	void set_eye(const float x, const float y, const float z);

	void set_lookat(const Point3D& p);

	void set_lookat(const float x, const float y, const float z);

	void set_up_vector(const Vector3D& u);

	void set_up_vector(const float x, const float y, const float z);

	//void set_roll(const float ra);

	void set_exposure_time(const float exposure);

	void compute_uvw(void);


protected:

	Point3D			eye;				// eye point
	Point3D			lookat; 			// lookat point
	Vector3D		u, v, w;			// orthonormal basis vectors
	Vector3D		up;					// up vector
	float			exposure_time;

	Camera& operator= (const Camera& c);
};

inline void Camera::set_eye(const Point3D & p)
{
	eye = p;
}

inline void Camera::set_eye(const float x, const float y, const float z)
{
    eye.x = static_cast<double>(x);
    eye.y = static_cast<double>(y);
    eye.z = static_cast<double>(z);
}

inline void Camera::set_lookat(const Point3D & p)
{
	lookat = p;
}

inline void Camera::set_lookat(const float x, const float y, const float z)
{
    lookat.x = static_cast<double>(x);
    lookat.y = static_cast<double>(y);
    lookat.z = static_cast<double>(z);
}

inline void Camera::set_up_vector(const Vector3D & u)
{
	up = u;
}

inline void Camera::set_up_vector(const float x, const float y, const float z)
{
    up.x = static_cast<double>(x);
    up.y = static_cast<double>(y);
    up.z = static_cast<double>(z);
}

inline void Camera::set_exposure_time(const float exposure)
{
	exposure_time = exposure;
}

#endif
