#include <iostream>
#include "../include/Tensor.hpp"

int main() {
    // First matrix (2x3)
    std::vector<std::vector<float>> values1 = {
        {0.1, 0.2, 0.3},
        {0.4, 0.5, 0.6}
    };
    Tensor t1(values1);

    // Second matrix (3x2)
    std::vector<std::vector<float>> values2 = {
        {0.7, 0.8, 0.11},
        {0.9, 0.10, 0.12}
        // {0.11, 0.12}
    };
    Tensor t2(values2);

    t1.print();
    t2.print();

    Tensor t3 = t1.transpose();

    t3.print();

    return 0;
}