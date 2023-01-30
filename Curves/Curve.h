#ifndef CURVE_H
#define CURVE_H

#include <cmath>
#include <vector>

enum CurveType {
	Crcl,
	Ell,
	Hlx
};

class Curve {
private: // fields
	int _curve_type;
public: // methods
	Curve() = delete;
	Curve(const int& type) : _curve_type(type) {};
	int get_type() { return _curve_type; }
	virtual std::vector<double> point_at(const double& t) = 0;
	virtual std::vector<double> derivative_at(const double& t) = 0;
	virtual ~Curve() {};
};

#endif // !CURVE_H
