#include "data_generators/discrete_distribution.h"

namespace data_generator {

void count(double* a, double* inter, int* key, size_t size_a, size_t size_inter)
{
    for (size_t i = 0; i < size_a; ++i)
    {
        for (size_t j = 0; j < size_inter; ++j)
        {
            if (j != 0) {
                if (a[i] < inter[j] && a[i] > inter[j-1]){
                    key[j]++;
                }
            }
            else {
                if (a[i] < inter[j]){
                    key[0]++;
                }
            }
        }
    }
}

void genVector(int* x, double* ri, double* inter, int* out, size_t size_ri, size_t size_inter)
{
    for (size_t i = 0; i < size_ri; ++i)
    {
        for (size_t j = 0; j < size_inter; ++j)
        {
            if (j != 0)
            {
                if (ri[i] < inter[j] && ri[i] > inter[j-1]){
                    out[i] = x[j];
                }
            }
            else{
                if (ri[i] < inter[j]){
                    out[i] = x[j];
                }
            }
        }
    }
}

void genRi(int k, double* ri)
{
    srand(time(0));
    for (int i = 0; i < k; ++i)
    {
        ri[i] = double(rand()) / RAND_MAX;
    }
}

std::vector<double> getDiscreteVector(size_t numbers)
{
    std::vector<double> res(numbers, 0);

    size_t size_inter = 5;
    int x[] = {3, 10, 12, 15, 24};
    double p[] = {0.1, 0.3, 0.3, 0.2, 0.1};
    double interv[size_inter] = {0};
    size_t n = numbers;

    double ri[n] = {0};
    for (size_t i = 0; i < size_inter; ++i)
    {
        interv[i] = 0;
        for (size_t j = 0; j < i+1; ++j)
        {
            interv[i] += p[j];
        }
    }

    genRi(n, ri);

    int key[size_inter] = {0};
    count(ri, interv, key, n, size_inter);

    int local_data[n] = {0};
    genVector(x, ri, interv, local_data, n, size_inter);

    for (size_t i = 0; i < numbers; ++i)
    {
        res[i] = local_data[i];
    }
    return res;
}
}
