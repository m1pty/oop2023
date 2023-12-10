#include <iostream>
#include <cmath>
bool checkReachability(std::pair<int, int> p1, std::pair<int, int> p2, float imag_dist)
{
    float real_dist = sqrtf((p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second));
    if ((imag_dist > real_dist) || (fabs(real_dist - imag_dist) <= __FLT_EPSILON__))
        return true;
    return false;
}