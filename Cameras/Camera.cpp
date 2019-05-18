#include "Camera.h"

Camera::Camera()
    :eye{ 0, 0, 500 }, lookat{ 0.0 },u{1.0, 0.0, 0.0}, v{0.0, 1.0, 0.0},
      w{0.0, 0.0, 1.0}, up{ 0.0, 1.0, 0.0 }, exposure_time{ 1.0f }
{
}

Camera::Camera(const Camera & c)
    : eye{ c.eye }, lookat{ c.lookat },u{ c.u },
      v{ c.v }, w{ c.w }, up{ c.up },exposure_time{ c.exposure_time }
{
}

Camera::~Camera()
{
}

void Camera::compute_uvw(void)
{
	w = eye - lookat;
	w.normalize();
	u = up ^ w;
	u.normalize();
	v = w ^ u;

	if (eye.x == lookat.x && eye.z == lookat.z && eye.y > lookat.y) { // camera looking vertically down
		u = Vector3D(0.0, 0.0, 1.0);
		v = Vector3D(1.0, 0.0, 0.0);
		w = Vector3D(0.0, 1.0, 0.0);
	}

	if (eye.x == lookat.x && eye.z == lookat.z && eye.y < lookat.y) { // camera looking vertically up
		u = Vector3D(1.0, 0.0, 0.0);
		v = Vector3D(0.0, 0.0, 1.0);
		w = Vector3D(0.0, -1.0, 0.0);
	}
}

Camera & Camera::operator=(const Camera & c)
{
	if (this == &c)
		return *this;
	eye = c.eye;
	lookat = c.lookat;
	up = c.up;
	u = c.u;
	v = c.v;
	w = c.w;
	exposure_time = c.exposure_time;
	return *this;
}
