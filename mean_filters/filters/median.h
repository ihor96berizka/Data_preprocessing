#ifndef MEDIAN_H
#define MEDIAN_H

#include <vector>
#include <algorithm>

namespace filter {
std::vector<double> Median(std::vector<double> data, size_t window_size);
}
#endif // MEDIAN_H
