#include "Matrix.h"

Matrix::Matrix(int rows, int cols) : m_rows(rows), m_cols(cols){
    m_matrix.reserve(rows * cols);
    FillMatrix();
}

int Matrix::DeterminantOfMatrix(std::vector<int>& matrix, int dimension){
    if(dimension == 1){
        return matrix[0];
    }
    else if(dimension == 2){
        return matrix[0] * matrix[3] - matrix[1] * matrix[2];
    }
    else{
        int d = 0;

        std::vector<int> temp(dimension * dimension);
        for(int h = 0; h < dimension; ++h){
            int i = 0;
            int j = 0;
            for(int k = 1; k < dimension; ++k){
                for(int t = 0; t < dimension; ++t){
                    if(k != 0 && t != h){
                        temp[i * (dimension - 1) + j] = matrix[k * dimension + t];
                        j++;

                        if(j == dimension - 1){
                            j = 0;
                            i++;
                        }
                    }
                }
            }

            d+= std::pow(-1, h) * matrix[h] * DeterminantOfMatrix(temp, dimension - 1);
        }
        return d;
    }
}

void Matrix::GetDeterminant(){
    std::cout << "Determinant of your Matrix is " << DeterminantOfMatrix(m_matrix, m_cols);
}

void Matrix::PrintMatrix(){
    for(int i = 0; i < m_rows; ++i){
        for(int j = 0; j < m_cols; ++j){
            std::cout << "|" << m_matrix[i * m_rows + j];
        }
        std::cout << "|" << std::endl;
    }
}

void Matrix::FillMatrix(){
    for(int i = 0; i < m_rows * m_cols; ++i){
        m_matrix[i] = rand() % 10;
    }
}