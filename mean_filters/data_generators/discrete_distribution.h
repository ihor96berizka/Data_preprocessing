#ifndef DISCRETE_DISTRIBUTION_H
#define DISCRETE_DISTRIBUTION_H

#include <ctime>
#include <cstdlib>
#include <vector>

namespace data_generator {


void count(double* a, double* inter, int* key, size_t size_a, size_t size_inter);
void genVector(int* x, double* ri, double* inter, int* out, size_t size_ri, size_t size_inter);
void genRi(int k, double* ri);
int getDiscreteNumber();
std::vector<double> getDiscreteVector(size_t numbers);
}
#endif // DISCRETE_DISTRIBUTION_H
