//
// Created by adrian on 03.04.17.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <vector>
#include <string>
#include <sstream>
#include <complex>
#include <string.h>


using namespace std;
namespace algebra {

    class Matrix {
    public:
        Matrix(const std::initializer_list<std::vector<std::complex<double>>> &matrix);

        Matrix(const Matrix &matrix);

        Matrix(int n_row, int n_col);

        Matrix();

        ~Matrix() {};

        string Print() const;

        pair<size_t, size_t> Size() const;

        void Set(std::complex<double> var, size_t n_row, size_t n_col);

        Matrix Add(const algebra::Matrix &matrix2) const;

        Matrix Sub(const algebra::Matrix &matrix2) const;

        Matrix Mul(const algebra::Matrix &matrix2) const;

        Matrix Pow(int n);


    private:
        vector<vector<complex<double>>> matrix_var;
        size_t n_row_;
        size_t n_col_;
    };
}


#endif //JIMP_EXERCISES_MATRIX_H
