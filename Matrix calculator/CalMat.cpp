#include "CalMat.h"
void creat_Mat(Matrix & New){
    New.Mat=new int*[New.row];
    for(int i=0;i<New.row;i++){
        New.Mat[i]=new int[New.col];
    }
}
void free_Mat(Matrix& New){
    for(int i=0;i<New.row;i++){
        delete [] New.Mat[i];
    }
    delete [] New.Mat;
    New.Mat=nullptr;
}
bool addMatrix(const Matrix& Mat1,const Matrix& Mat2,Matrix& Result){
    if(Mat1.col!=Mat2.col || Mat1.row!=Mat2.row || Mat1.Mat==nullptr || Mat2.Mat==nullptr || Result.Mat==nullptr){
        return false;
    }
    for(int i=0;i<Mat1.row;i++){
        for(int j=0;j<Mat1.col;j++){
            Result.Mat[i][j]=Mat1.Mat[i][j]+Mat2.Mat[i][j];
        }
    }
    return true;
}
bool addMatrix(const Matrix& Mat1,double scaler ,Matrix& Result){
    if(Mat1.row!=Result.row || Mat1.col!=Result.col || Mat1.Mat==nullptr || Result.Mat==nullptr){
        return false;
    }
    for(int i=0;i<Mat1.row;i++){
        for(int j=0;j<Mat1.col;j++){
            Result.Mat[i][j]=Mat1.Mat[i][j]+scaler;
        }
    }
    return true;
}
bool subtractMatrix(const Matrix& Mat1,const Matrix& Mat2,Matrix& Result){
    if(Mat1.col!=Mat2.col || Mat1.row!=Mat2.row || Mat1.Mat==nullptr || Mat2.Mat==nullptr || Result.Mat==nullptr){
        return false;
    }
    for(int i=0;i<Mat1.row;i++){
        for(int j=0;j<Mat1.col;j++){
            Result.Mat[i][j]=Mat1.Mat[i][j]-Mat2.Mat[i][j];
        }
    }
    return true;
}
bool subtractMatrix(const Matrix& Mat1,double scaler,Matrix& Result){
    if(Mat1.row!=Result.row || Mat1.col!=Result.col || Mat1.Mat==nullptr || Result.Mat==nullptr){
        return false;
    }
    for(int i=0;i<Mat1.row;i++){
        for(int j=0;j<Mat1.col;j++){
            Result.Mat[i][j]=Mat1.Mat[i][j]-scaler;
        }
    }
    return true;
}
