#ifndef CALMAT_H
#define CALMAT_H
struct Matrix{
    int row;
    int col;
    int** Mat;
};
bool addMatrix(const Matrix&,const Matrix&,Matrix&);
bool addMatrix(const Matrix&,double,Matrix&);
bool subtractMatrix(const Matrix&,const Matrix&,Matrix&);
bool subtractMatrix(const Matrix&,double,Matrix&);
void creat_Mat(Matrix&);
void free_Mat(Matrix& New);
#endif