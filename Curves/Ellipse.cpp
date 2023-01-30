#include "Ellipse.h"

Ellipse::Ellipse() : Curve(Ell), _a(0.0), _b(0.0) {}

Ellipse::Ellipse(const double& a, const double& b) : Curve(Ell) {
	if (a < 0.0 || b < 0.0)
		throw("Parameters cannot be negative");
	else {
		_a = a;
		_b = b;
	}
}

Ellipse::Ellipse(const Ellipse& ell) : Curve(Ell), _a(ell._a), _b(ell._b) {}

Ellipse Ellipse::operator=(const Ellipse& ell) {
	if (this != &ell) {
		_a = ell._a;
		_b = ell._b;
	}

	return *this;
}

std::vector<double> Ellipse::point_at(const double& t) {
	return std::vector<double>({ _a* cos(t), _b* sin(t), 0.0 });
}
std::vector<double> Ellipse::derivative_at(const double& t) {
	return std::vector<double>({ -_a * sin(t), _b* cos(t), 0.0 });
}