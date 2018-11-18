#include "expsmooth.h"

namespace filter {
std::vector<double> expSmooth(std::vector<double> data, double alp)
{
    std::vector<double> res(data.size(), 0);
    res[0] = data[0];

    for (size_t i = 1; i < data.size(); ++i)
    {
        res[i] = alp*data[i] + (1 - alp)*res[i-1];
    }

    return res;
}
}
