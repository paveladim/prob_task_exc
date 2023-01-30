#ifndef HELIX_H
#define HELIX_H

#include "Curve.h"

class Helix : public Curve {
private: // fields
	double _radius;
	double _a;
public: // methods
	Helix();
	Helix(const double& radius, const double& a);
	Helix(const Helix& helix);
	Helix operator=(const Helix& helix);
	std::vector<double> point_at(const double& t);
	std::vector<double> derivative_at(const double& t);
	~Helix() {}
};

#endif // !HELIX_H
