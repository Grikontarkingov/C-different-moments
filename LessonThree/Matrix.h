#ifndef _MATRIX_H
#define _MATRIX_H
#include <vector>
#include <cstdlib>
#include <iostream>
#include <valarray>

class Matrix {
public:
    Matrix(int rows, int cols);

    void PrintMatrix();
    int DeterminantOfMatrix(std::vector<int>& temp, int dimension);
    void GetDeterminant();

private:
    int m_rows;
    int m_cols;
    std::vector<int> m_matrix;

    void FillMatrix();
};


#endif //_MATRIX_H
