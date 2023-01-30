#include "api.h"

void calculate_at_025pi(std::vector<std::shared_ptr<Curve>>& source) {
	std::vector<double> tmp(3);
	double param = 0.78539816339; // 0.25 * pi
	int crv = 0;

	for (auto& curve : source) {
		std::cout << "Curve " << crv << std::endl;
		tmp = curve->point_at(param);
		std::cout << "\t Point at 0.25 * pi" << std::endl;
		std::cout << "\t\t";
		for (auto& elem : tmp)
			std::cout << elem << " ";
		std::cout << std::endl;

		tmp = curve->derivative_at(param);
		std::cout << "\t Derivative at 0.25 * pi" << std::endl;
		std::cout << "\t\t";
		for (auto& elem : tmp)
			std::cout << elem << " ";
		std::cout << std::endl;

		++crv;
	}
}

void sort_and_sum_circles(std::vector<std::shared_ptr<Curve>>& source) {
	std::vector<std::shared_ptr<Circle>> circles;

	for (auto& curve : source) {
		std::shared_ptr<Circle> tmp = std::dynamic_pointer_cast<Circle>(curve);
		if (tmp.get() != nullptr)
			circles.emplace_back(std::move(tmp));
	}

	std::sort(circles.begin(), circles.end(),
		[](std::shared_ptr<Circle>& c1, std::shared_ptr<Circle>& c2) {
			return c1->get_radius() < c2->get_radius();
		}
	);

	std::cout << "\nSorted circles\n";
	std::cout << "First tripple\n";

	for (size_t i = 0; i < std::min(static_cast<size_t>(3), circles.size()); ++i)
		std::cout << "Radius of " << i << " is " << circles[i]->get_radius() << std::endl;

	std::cout << "Last tripple\n";

	for (size_t i = std::max(static_cast<size_t>(0), circles.size() - 3); i < circles.size(); ++i)
		std::cout << "Radius of " << i << " is " << circles[i]->get_radius() << std::endl;

	std::cout << std::endl;
	double radiuses_sum{ 0.0 };

	for (auto& circle : circles)
		radiuses_sum += circle->get_radius();

	std::cout << "Sum of radii is " << radiuses_sum << std::endl;
}

void task() {
	std::vector<std::shared_ptr<Curve>> curves(50);

	for (auto& curve : curves)
		curve = create_curve();

	calculate_at_025pi(curves);
	sort_and_sum_circles(curves);
}