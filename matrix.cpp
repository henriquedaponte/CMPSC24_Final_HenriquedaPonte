#include <iostream>
#include "matrix.h"



Matrix matrixAdd(const Matrix & matrix_1, const Matrix & matrix_2){
 
    if(matrix_1.empty() || matrix_2.empty() || matrix_1[0].empty() || matrix_2[0].empty()){
        throw std::invalid_argument("-1");
    }else
    if( (matrix_1.size() != matrix_2.size()) || (matrix_1[0].size() != matrix_2[0].size()) ){
        throw std::invalid_argument("-1");
    }else{

    size_t arows = matrix_1.size();
    size_t acolumns = matrix_1[0].size();
    Matrix matrix_3(arows, Array(acolumns, 0));

        for(int i = 0; i < matrix_1.size(); i++){
            for(int j = 0; j < matrix_1[i].size(); j++){
                matrix_3[i][j] = matrix_1[i][j] + matrix_2[i][j];
            }
        }
        return matrix_3;
    }
}


Matrix matrixMultiply(const Matrix & matrix_1, const Matrix & matrix_2){
    
    // Checking if the No. of columns for matrix_1 are equal to the No. of rows for matrix_2,
    // Checking if Matrices are empty,
    //Else, perform operation
    if(matrix_1.empty() || matrix_2.empty() || matrix_1[0].empty() || matrix_2[0].empty()){
        throw std::invalid_argument("-1");
    }else
        if( (matrix_1[0].size() != matrix_2.size()) ){
        throw std::invalid_argument("-1");
    }else {

    size_t arows = matrix_1.size();
    size_t brows = matrix_2.size();
    size_t bcolumns = matrix_2[0].size();

    Matrix matrix_3(arows, Array(bcolumns, 0));

        for(int i = 0; i < arows; i++){
            for(int j = 0; j < bcolumns; j++){
                for(int k = 0; k < brows; k++){
                    matrix_3[i][j] += matrix_1[i][k] * matrix_2[k][j];
                }
            }
        }
        return matrix_3;
    }
}

