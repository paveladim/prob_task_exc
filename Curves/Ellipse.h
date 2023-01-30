#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Curve.h"

class Ellipse : public Curve {
private: // fields
	double _a;
	double _b;
public: // methods
	Ellipse();
	Ellipse(const double& a, const double& b);
	Ellipse(const Ellipse& ell);
	Ellipse operator=(const Ellipse& ell);
	std::vector<double> point_at(const double& t);
	std::vector<double> derivative_at(const double& t);
	~Ellipse() {}
};

#endif // !ELLIPSE_H
