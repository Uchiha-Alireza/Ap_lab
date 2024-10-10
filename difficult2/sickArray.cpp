#include "Array.h"
#include <iostream>
void newArray(int**& arr, int& n){
    arr = new int*[n + 1]; 
    for (int i = 0; i < n; i++){
        *(arr+i) = new int[n]; 
    }
    arr[n] = nullptr; 
}
void squareArray(int**& arr){
    int sizeArray = 0;
    while (*(arr + sizeArray) != nullptr){
        sizeArray++;
    }
    int** tmp = new int*[sizeArray]; 
    for (int i = 0; i < sizeArray; i++){
        *(tmp+i) = new int[sizeArray]; 
        for (int j = 0; j < sizeArray; j++) {
            *(*(tmp + i) + j) = *(*(arr + i) + j); 
        }
    }
    for (int i = 0; i < sizeArray; i++){
        for (int j = 0; j < sizeArray; j++){
            *(*(arr + i) + j) = 0; 
            for (int k = 0; k < sizeArray; k++){
                *(*(arr + i) + j) += *(*(tmp + i) + k) * *(*(tmp + k) + j); 
            }
        }
    }

    for (int i = 0; i < sizeArray; i++) {
        delete[] *(tmp+i); 
    }
    delete[] tmp; 
}
void printArray(int**& arr) {
    int sizeArray = 0;
    while (*(arr + sizeArray) != nullptr){ 
        sizeArray++;
    }
    
    for (int i = 0; i < sizeArray; i++) {
        for (int j = 0; j < sizeArray; j++){
            std::cout << "row : " << i << " col : " << j << " >>>> " << *(*(arr + i) + j) << std::endl; // چاپ مقادیر
        }
    }
}
void freeArray(int**& arr) {
    int sizeArray = 0;
    while (*(arr + sizeArray) != nullptr){ 
        sizeArray++;
    }
    
    for (int i = 0; i < sizeArray; i++){
        delete[] *(arr+i); 
    }
    delete[] arr; 
    arr = nullptr; 
}
