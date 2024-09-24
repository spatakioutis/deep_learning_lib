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

    std::cout << "Tensor ("<< rows << " x " << cols << "):" << std::endl;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::fixed << std::setprecision(3) 
                      << std::setw(6) << data[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
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
            result(i,j) = sum;
        }
    }

    return result;
}

Tensor Tensor::add(const Tensor& other) {

    if (this->rows != other.rows || this->cols != other.cols) {
        throw std::invalid_argument("Dimensions of tensors must match.");
    }

    Tensor result(this->rows, this->cols);

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            result(i,j) = this->data[i][j] + other.data[i][j];
        }
    }

    return result;
}

Tensor Tensor::transpose() {
    Tensor result(this->cols, this->rows);

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            result(j,i) = this->data[i][j];
        }
    }

    return result;
}