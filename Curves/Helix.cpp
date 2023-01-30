#include "Helix.h"

Helix::Helix() : Curve(Hlx), _radius(0.0), _a(0.0) {}

Helix::Helix(const double& radius, const double& a) : Curve(Hlx) {
	if (radius < 0.0 || a < 0.0)
		throw("Parameters cannot be negative\n");
	else {
		_radius = radius;
		_a = a;
	}
}

Helix::Helix(const Helix& helix) : Curve(Hlx), _radius(helix._radius), _a(helix._a) {}

Helix Helix::operator=(const Helix& helix) {
	if (this != &helix)
		_radius = helix._radius;

	return *this;
}

std::vector<double> Helix::point_at(const double& t) {
	return std::vector<double>({ _radius * cos(t), _radius * sin(t), _a * t });
}

std::vector<double> Helix::derivative_at(const double& t) {
	return std::vector<double>({ -_radius * sin(t), _radius * cos(t), _a });
}