#ifndef API_H
#define API_H

#include <iostream>
#include "CurveRandomFactory.h"

extern "C" __declspec(dllexport) void task();
//void calculate_at_025pi(std::vector<std::shared_ptr<Curve>>& source);
//void sort_and_sum_circles(std::vector<std::shared_ptr<Curve>>& source);

#endif // !API_H

