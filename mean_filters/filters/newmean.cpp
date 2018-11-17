#include "newmean.h"

namespace filter {
std::vector<double> newMean(std::vector<double> data)
{
    std::vector<double> res(data.size(), 0);
    res[0] = data[0];
    double factor = 1.0 / data.size();
    for (size_t i = 1; i < data.size(); ++i)
    {
        res[i] = res[i-1] + factor * (data[i] - res[i-1]);
    }

    return res;
}
}
