#ifndef __PINHOLE__
#define __PINHOLE__

#include "../BasicTools/Point2D.h"
#include "../World/World.h"    // we can #include "World.h" here

struct RGB
{
	unsigned char R;
	unsigned char G;
	unsigned char B;
};

class Pinhole : public Camera {
public:

	Pinhole();

	Pinhole(const Pinhole& ph);

	virtual ~Pinhole();

	virtual Camera* clone(void) const;

	Pinhole& operator= (const Pinhole& rhs);

	void set_view_distance(const float vpd);

	void set_zoom(const float zoom_factor);

	Vector3D get_direction(const Point2D& p) const;

	void display_pixel(const RGBColor & pixel_color, RGB &color, ViewPlane &vp) const;

	virtual void render_scene(const World& w);

private:

	float	d;		// view plane distance
	float	zoom;	// zoom factor

};

inline void Pinhole::set_view_distance(float _d) {
	d = _d;
}

inline void Pinhole::set_zoom(float zoom_factor) {
	zoom = zoom_factor;
}

#endif