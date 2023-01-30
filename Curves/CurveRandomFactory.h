#ifndef CURVE_RANDOM_FACTORY_H
#define CURVE_RANDOM_FACTORY_H

#include <memory>
#include <random>
#include "Curve.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

static std::shared_ptr<Curve> create_curve() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> curve_type_generator(Crcl, Hlx);
	std::uniform_real_distribution<> parameters_generator(1e-16, 100.0);

	// 0 - Circle
	// 1 - Ellipse
	// 2 - Helix
	int curve_type = curve_type_generator(gen);

	switch (curve_type)
	{
	case Crcl:
		return std::make_shared<Circle>(parameters_generator(gen));
		break;
	case Ell:
		return std::make_shared<Ellipse>(
				parameters_generator(gen),
				parameters_generator(gen)
			);
		break;
	case Hlx:
		return std::make_shared<Helix>(
			parameters_generator(gen),
			parameters_generator(gen)
			);
		break;
	default:
		break;
	}
}

#endif // !CURVE_RANDOM_FACTORY_H
