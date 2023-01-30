#include "Circle.h"

Circle::Circle() : Curve(Crcl), _radius(0.0) {}

Circle::Circle(const double& radius) : Curve(Crcl) {
	if (radius < 0.0)
		throw("Radius cannot be negative\n");
	else
		_radius = radius;
}

Circle::Circle(const Circle& circle) : Curve(Crcl), _radius(circle._radius) {}

Circle Circle::operator=(const Circle& circle) {
	if (this != &circle)
		_radius = circle._radius;

	return *this;
}

double Circle::get_radius() {
	return _radius;
}

std::vector<double> Circle::point_at(const double& t) {
	return std::vector<double>({ _radius* cos(t), _radius* sin(t), 0.0 });
}

std::vector<double> Circle::derivative_at(const double& t) {
	return std::vector<double>({ -_radius * sin(t), _radius* cos(t), 0.0 });
}