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

Tensor Tensor::dot(const Tensor& other) {

    if (this->cols != other.rows) {
        throw std::invalid_argument("Number of columns of the first matrix must equal the number of rows of the second matrix.");
    }
    
    Tensor result(this->rows, other.cols);

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < other.cols; j++) {

            float sum = 0.0f;
            for (int k = 0; k < this->cols; k++) {
                sum += this->data[i][k] * other.data[k][j];
            }
            result(i, j) = sum;
        }
    }

    return result;
}