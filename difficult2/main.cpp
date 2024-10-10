#include "Array.h"
#include <iostream>

int main() {
    int** matrix;
    int size = 2;
    newArray(matrix, size);
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            *(matrix[i] + j) = 2 * i + j; 
        }
    }
    squareArray(matrix); 
    printArray(matrix);
    freeArray(matrix);
    return 0;
}
