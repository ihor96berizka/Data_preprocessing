#ifndef EXPSMOOTH_H
#define EXPSMOOTH_H

#include <vector>

namespace filter {
std::vector<double> expSmooth(std::vector<double> data, double alp);
}
#endif // EXPSMOOTH_H
