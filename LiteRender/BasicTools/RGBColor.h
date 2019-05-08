#ifndef _RGB_H_
#define _RGB_H_

class RGBColor 
{
public:
	RGBColor();
	RGBColor(float c);
	RGBColor(float _r, float _g, float _b);
	RGBColor(const RGBColor &c);
	~RGBColor();

	RGBColor &operator=(const RGBColor &rhs);

	RGBColor operator+(const RGBColor &v) const;
	RGBColor operator-(const RGBColor &v) const;
	RGBColor operator*(const float s) const;
	RGBColor operator/(const float s) const;

	RGBColor &operator+=(const RGBColor &v); 
	RGBColor &operator-=(const RGBColor &v);
	RGBColor &operator*=(const float s);
	RGBColor &operator/=(const float s);

	bool operator==(const RGBColor &c) const;

	float average() const;
	RGBColor powc(float p) const;

public:
	float r;
	float g;
	float b;
};

#endif
