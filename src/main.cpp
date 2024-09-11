#include <iostream>
#include "../include/Tensor.hpp"

int main() {
    // First matrix (2x3)
    std::vector<std::vector<float>> values1 = {
        {1, 2, 3},
        {4, 5, 6}
    };
    Tensor t1(values1);

    // Second matrix (3x2)
    std::vector<std::vector<float>> values2 = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    Tensor t2(values2);

    t1.print();
    t2.print();

    Tensor t3 = t1.dot(t2);

    t3.print();

    return 0;
}