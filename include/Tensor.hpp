#ifndef TENSOR_H
#define TENSOR_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>

class Tensor {
    private:
        std::vector<std::vector<float>> data;
        int rows;
        int cols;
    
    public:
        Tensor(int rows, int columns);
        Tensor(std::vector<std::vector<float>>& data);

        Tensor dot(const Tensor& other); 
        Tensor add(const Tensor& other); 
        Tensor transpose();

        void print();
        float& operator()(int i, int j);
};

#endif