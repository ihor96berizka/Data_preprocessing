#include "median.h"
#include <QDebug>

namespace filter {
std::vector<double> Median(std::vector<double> data, size_t window_size)
{
    std::vector<double> res;

    if (data.size() % window_size == 0)
    {
        for (size_t i = 0; i < data.size(); i+= window_size)
        {
            qDebug() << "i = " << i;
            std::vector<double> window_data(data.begin() + i, data.begin() + window_size + i);
            qDebug() << "window:";
            for (auto& item: window_data)
            {
                qDebug() << item;
            }
            std::sort(window_data.begin(), window_data.end());
            qDebug() << "sorted window:";
            for (auto& item: window_data)
            {
                qDebug() << item;
            }
            double value = 0;
            if (window_size % 2 == 0)
            {
                value = window_data[window_size/2];
            }
            else
            {
                value = window_data[window_size-1] + window_data[window_size]/2;
            }
            qDebug() << "filtered value: " << value;
            res.push_back(value);
        }
    }



    return res;
}

}
