#ifndef CIRCLE_H
#define CIRCLE_H

#include "Curve.h"

class Circle : public Curve {
private: // fields
	double _radius;
public: // methods
	Circle();
	Circle(const double& radius);
	Circle(const Circle& circle);
	Circle operator=(const Circle& circle);
	double get_radius();
	std::vector<double> point_at(const double& t);
	std::vector<double> derivative_at(const double& t);
	~Circle() {}
};

#endif // !CIRCLE_H
