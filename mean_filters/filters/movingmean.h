#ifndef MOVINGMEAN_H
#define MOVINGMEAN_H

#include <vector>

namespace filter {
std::vector<double> movingMean(std::vector<double> data, size_t p);
}
#endif // MOVINGMEAN_H
