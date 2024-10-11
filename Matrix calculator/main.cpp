#include "CalMat.h"
#include <iostream>

int main(){
    Matrix mat1;
    mat1.row = 2;
    mat1.col = 2;
    creat_Mat(mat1);  
    Matrix mat2;
    mat2.row = 2;
    mat2.col = 2;
    creat_Mat(mat2);  
    Matrix result;
    result.row = 2;
    result.col = 2;
    creat_Mat(result); 
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            mat1.Mat[i][j] = 2 * i + j;  
            mat2.Mat[i][j] = 3 * i + j;  
        }
    }
    bool B = addMatrix(mat1, mat2, result);
    if (B){
        std::cout << "Matrix 1 + Matrix 2:" << std::endl;
        for (int i = 0; i < result.row; i++){
            for (int j = 0; j < result.col; j++){
                std::cout << result.Mat[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    else{
        std::cout << "Addition of matrices failed!" << std::endl;
    }
    B = subtractMatrix(mat1, mat2, result);
    if (B){
        std::cout << "Matrix 1 - Matrix 2:" << std::endl;
        for(int i = 0; i < result.row; i++){
            for (int j = 0; j < result.col; j++){
                std::cout << result.Mat[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    else{
        std::cout << "Subtraction of matrices failed!" << std::endl;
    }
    double scalar = 5.0;
    B = addMatrix(mat1, scalar, result);
    if (B){
        std::cout << "Matrix 1 + Scalar 5:" << std::endl;
        for (int i = 0; i < result.row; i++){
            for (int j = 0; j < result.col; j++){
                std::cout << result.Mat[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    else{
        std::cout << "Addition of matrix with scalar failed!" << std::endl;
    }
    B = subtractMatrix(mat1, scalar, result);
    if (B){
        std::cout << "Matrix 1 - Scalar 5:" << std::endl;
        for (int i = 0; i < result.row; i++){
            for (int j = 0; j < result.col; j++){
                std::cout << result.Mat[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    else{
        std::cout << "Subtraction of matrix with scalar failed!" << std::endl;
    }
    free_Mat(mat1);
    free_Mat(mat2);
    free_Mat(result);
    return 0;
}
