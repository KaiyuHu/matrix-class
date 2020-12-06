#include <iostream>
#include "matrix.hpp"
using namespace std;
matrix::matrix(int rows, int cols)
{
    col = cols;
    row = rows;
    p = new float*[row];
    for(int i = 0; i < row; i++)
    {
        p[i] = new float[col];
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            p[i][j] = rand()%10;
        }
    }
}

matrix::~matrix() {
    for(int i = 0; i < row; i++)
    {
         delete[] p[i];
    }
    delete []p;
}
void matrix::Show() const {
    //cout << rows_num <<" "<<cols_num<< endl;//显示矩阵的行数和列数
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
matrix& matrix::operator=(const matrix& m)
{
    for (int i = 0; i < row; i++) {
        memcpy( p[i],m.p[i],sizeof(int)*col);
    }
    cout << endl;
    return *this;
}

matrix& matrix::operator+(const matrix& m)
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            p[i][j] += m.p[i][j];
        }
    }
    return *this;
}


matrix matrix::operator*(const matrix& B)
{
    matrix temp = matrix(row,B.col);
    
    for (int m = 0; m < row; m += 4) {
      for (int n = 0; n < B.col; n += 4) {
            temp.p[m + 0][n + 0] = 0; temp.p[m + 0][n + 1] = 0; temp.p[m + 0][n + 2] = 0; temp.p[m + 0][n + 3] = 0;
          temp.p[m + 1][n + 0] = 0; temp.p[m + 1][n + 1] = 0; temp.p[m + 1][n + 2] = 0; temp.p[m + 1][n + 3] = 0;
          temp.p[m + 2][n + 0] = 0; temp.p[m + 2][n + 1] = 0; temp.p[m + 2][n + 2] = 0; temp.p[m + 2][n + 3] = 0;
          temp.p[m + 3][n + 0] = 0; temp.p[m + 3][n + 1] = 0; temp.p[m + 3][n + 2] = 0; temp.p[m + 3][n + 3] = 0;
          
        for (int k = 0; k < col; k += 4) {
          //k+0
          float A00=p[m+0][k+0] , A10=p[m+1][k+0] , A20=p[m+2][k+0] , A30=p[m+3][k+0];
          float B00=B.p[k+0][n+0] , B01=B.p[k+0][n+1] , B02=B.p[k+0][n+2] , B03=B.p[k+0][n+3];
          temp.p[m+0][n+0] += A00*B00;  temp.p[m+0][n+1] += A00*B01;  temp.p[m+0][n+2] += A00*B02;  temp.p[m+0][n+3] += A00*B03;
          temp.p[m+1][n+0] += A10*B00;  temp.p[m+1][n+1] += A10*B01;  temp.p[m+1][n+2] += A10*B02;  temp.p[m+1][n+3] += A10*B03;
          temp.p[m+2][n+0] += A20*B00;  temp.p[m+2][n+1] += A20*B01;  temp.p[m+2][n+2] += A20*B02;  temp.p[m+2][n+3] += A20*B03;
          temp.p[m+3][n+0] += A30*B00;  temp.p[m+3][n+1] += A30*B01;  temp.p[m+3][n+2] += A30*B02;  temp.p[m+3][n+3] += A30*B03;
          //k+1
          float A01=p[m+0][k+1] , A11=p[m+1][k+1] , A21=p[m+2][k+1] , A31=p[m+3][k+1];
          float B10=B.p[k+1][n+0] , B11=B.p[k+1][n+1] , B12=B.p[k+1][n+2] , B13=B.p[k+1][n+3];
          temp.p[m+0][n+0] += A01*B10;  temp.p[m+0][n+1] += A01*B11;  temp.p[m+0][n+2] += A01*B12;  temp.p[m+0][n+3] += A01*B13;
          temp.p[m+1][n+0] += A11*B10;  temp.p[m+1][n+1] += A11*B11;  temp.p[m+1][n+2] += A11*B12;  temp.p[m+1][n+3] += A11*B13;
          temp.p[m+2][n+0] += A21*B10;  temp.p[m+2][n+1] += A21*B11;  temp.p[m+2][n+2] += A21*B12;  temp.p[m+2][n+3] += A21*B13;
          temp.p[m+3][n+0] += A31*B10;  temp.p[m+3][n+1] += A31*B11;  temp.p[m+3][n+2] += A31*B12;  temp.p[m+3][n+3] += A31*B13;
          //k+2
          float A02=p[m+0][k+2] , A12=p[m+1][k+2] , A22=p[m+2][k+2] , A32=p[m+3][k+2];
          float B20=B.p[k+2][n+0] , B21=B.p[k+2][n+1] , B22=B.p[k+2][n+2] , B23=B.p[k+2][n+3];
          temp.p[m+0][n+0] += A02*B20;  temp.p[m+0][n+1] += A02*B21;  temp.p[m+0][n+2] += A02*B22;  temp.p[m+0][n+3] += A02*B23;
          temp.p[m+1][n+0] += A12*B20;  temp.p[m+1][n+1] += A12*B21;  temp.p[m+1][n+2] += A12*B22;  temp.p[m+1][n+3] += A12*B23;
          temp.p[m+2][n+0] += A22*B20;  temp.p[m+2][n+1] += A22*B21;  temp.p[m+2][n+2] += A22*B22;  temp.p[m+2][n+3] += A22*B23;
          temp.p[m+3][n+0] += A32*B20;  temp.p[m+3][n+1] += A32*B21;  temp.p[m+3][n+2] += A32*B22;  temp.p[m+3][n+3] += A32*B23;
          //k+3
          float A03=p[m+0][k+3] , A13=p[m+1][k+3] , A23=p[m+2][k+3] , A33=p[m+3][k+3];
          float B30=B.p[k+3][n+0] , B31=B.p[k+3][n+1] , B32=B.p[k+3][n+2] , B33=B.p[k+3][n+3];
          temp.p[m+0][n+0] += A03*B30;  temp.p[m+0][n+1] += A03*B31;  temp.p[m+0][n+2] += A03*B32;  temp.p[m+0][n+3] += A03*B33;
          temp.p[m+1][n+0] += A13*B30;  temp.p[m+1][n+1] += A13*B31;  temp.p[m+1][n+2] += A13*B32;  temp.p[m+1][n+3] += A13*B33;
          temp.p[m+2][n+0] += A20*B30;  temp.p[m+2][n+1] += A20*B31;  temp.p[m+2][n+2] += A20*B32;  temp.p[m+2][n+3] += A20*B33;
          temp.p[m+3][n+0] += A33*B30;  temp.p[m+3][n+1] += A33*B31;  temp.p[m+3][n+2] += A33*B32;  temp.p[m+3][n+3] += A33*B33;
        }
      }
    }

    return temp;
}

ostream & operator<<(ostream & os, const matrix & t){
    for (int i = 0; i < t.row; i++) {
        for (int j = 0; j < t.col; j++) {
            os << t.p[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
    return os;
}
istream& operator>>(istream& is, matrix& m)
{
    for (int i = 0; i < m.row; i++) {
        for (int j = 0; j < m.col; j++) {
            is >> m.p[i][j];
        }
    }
    return is;
}

matrix& matrix::operator*(int a)
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            p[i][j] = a*p[i][j];
        }
    }
    return *this;
}

matrix& operator*(int a, matrix&n)
{
    for (int i = 0; i < n.row; i++) {
        for (int j = 0; j < n.col; j++) {
            n.p[i][j] = a*n.p[i][j];
        }
    }
    return n;
}

