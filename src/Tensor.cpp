#include "../include/Tensor.hpp"

Tensor::Tensor(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    this->data.resize(rows, std::vector<float>(cols, 0.0f));
}

Tensor::Tensor(std::vector<std::vector<float>>& values) {

    // correct format checks 

    rows = values.size();
    if ( rows == 0 ) {
        throw std::invalid_argument("Matrix cannot have 0 rows");
    }

    cols = values[0].size();
    for (const auto& row : values) {
        if (row.size() != cols) {
            throw std::invalid_argument("All rows must have the same number of columns");
        }
    }

    data = values;
}

float& Tensor::operator()(int i, int j) {
    if ( i >= rows || j >= cols || i < 0 || j < 0 ) {
        throw std::out_of_range("Out of bounds indexes");
    }

    return data[i][j];
}

void Tensor::print() {

    for (const auto& row : data) {
        for (const auto& item : row) {
            std::cout << " " << item << " ";
        }
        std::cout << std::endl;
    }
}