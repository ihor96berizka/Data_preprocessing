#include "movingmean.h"

namespace filter {
std::vector<double> movingMean(std::vector<double> data, size_t p)
{
    std::vector<double> res(data.size(), 0);
    for (size_t i = 0; i < data.size(); i++)
    {
        for (size_t k = 0; k < p; ++k)
        {
            if (i+k < data.size())
            {
                res[i+p/2] += data[i+k];
            }
        }
        res[i+p/2] *= 1.0 / (p+1);
    }
    return res;
}
}
