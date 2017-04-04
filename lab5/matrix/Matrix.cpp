//
// Created by adrian on 03.04.17.
//
#include "Matrix.h"


using namespace std;
namespace algebra {
    Matrix::Matrix(const std::initializer_list<std::vector<std::complex<double>>> &matrix) : matrix_var(matrix) {
        n_row_ = matrix_var.size();
        n_col_ = matrix_var[0].size();

    }

    Matrix::Matrix(const Matrix &matrix) {
        matrix_var = matrix.matrix_var;
        n_col_ = matrix.n_col_;
        n_row_ = matrix.n_row_;

    }

    Matrix::Matrix(int n_row, int n_col) {
        matrix_var.resize(n_row);
        for (int i = 0; i < n_row; i++) {
            matrix_var[i].resize(n_col);
        }
        n_row_ = n_row;
        n_col_ = n_col;
    }


    Matrix::Matrix() {
        matrix_var.resize(0);
        n_row_ = 0;
        n_col_ = 0;
    }

    std::string Matrix::Print() const {

        if (matrix_var.size() != 0) {
            string str = "[";
            for (int i = 0; i < this->n_row_; i++) {
                for (int j = 0; j < this->n_col_; j++) {
                    std::string tmp1, tmp2;
                    stringstream stream1, stream2;
                    stream1 << matrix_var[i][j].real();
                    tmp1 = stream1.str();
                    str += tmp1;
                    str += "i";
                    stream2 << matrix_var[i][j].imag();
                    tmp2 = stream2.str();
                    str += tmp2;
                    str += ", ";
                }
                str[str.size() - 2] = ';';
            }
            str[str.size() - 2] = ']';
            str.pop_back();
            return str;
        }
        return "[]";
    }

    pair<size_t, size_t> Matrix::Size() const {
        pair<size_t, size_t> size = {n_row_, n_col_};
        return size;
    }

    void Matrix::Set(complex<double> var, size_t n_row,
                     size_t n_col) {
        matrix_var[n_row][n_col] = var;
    }

    algebra::Matrix Matrix::Add(const algebra::Matrix &matrix2) const {

        if (n_row_ == matrix2.n_row_ and n_col_ == matrix2.n_col_) {
            algebra::Matrix new_matrix(n_row_, n_col_);
            for (int i = 0; i < n_row_; i++) {
                for (int j = 0; j < n_col_; j++) {
                    new_matrix.Set(matrix_var[i][j] + matrix2.matrix_var[i][j], i, j);
                }
            }
            return new_matrix;
        }
        return Matrix();
    }

    algebra::Matrix Matrix::Sub(const algebra::Matrix &matrix2) const {

        if (n_row_ == matrix2.n_row_ and n_col_ == matrix2.n_col_) {
            algebra::Matrix new_matrix(n_row_, n_col_);
            for (int i = 0; i < n_row_; i++) {
                for (int j = 0; j < n_col_; j++) {
                    new_matrix.Set(matrix_var[i][j] - matrix2.matrix_var[i][j], i, j);
                }
            }
            return new_matrix;
        }
        return Matrix();
    }

    algebra::Matrix Matrix::Mul(const algebra::Matrix &matrix2) const {
        if (n_col_ == matrix2.n_row_) {
            Matrix new_matrix(n_row_, matrix2.n_col_);
            for (int i = 0; i < n_row_; i++) {
                for (int j = 0; j < matrix2.n_col_; j++) {
                    std::complex<double> value = 0.;
                    for (int h = 0; h < matrix2.n_row_; h++) {
                        value += (matrix_var[i][h] * matrix2.matrix_var[h][j]);
                    }
                    new_matrix.Set(value, i, j);
                }
            }
            return new_matrix;
        }
        return Matrix();
    }

    algebra::Matrix Matrix::Pow(int n) {
        if (n_col_ == n_row_) {
            if (n == 0) {
                Matrix new_matrix(n_row_, n_col_);
                for (int i = 0; i < n_row_; i++) {
                    new_matrix.Set(1.0 + 0.i, i, i);
                }
                return new_matrix;
            }
            if (n > 1) {
                Matrix new_matrix = this->Mul(*this);
                for (int i = 1; i < n - 1; i++) {
                    new_matrix = new_matrix.Mul(*this);
                }
                return new_matrix;
            }
            if (n == 1) return *this;
        }
        return Matrix{};
    }
}