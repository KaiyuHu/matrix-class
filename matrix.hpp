//
//  matrix.hpp
//  assignment-4-8
//
//  Created by 胡开域 on 2020/11/28.
//  Copyright © 2020 胡开域. All rights reserved.
//

#ifndef STOCK00_H_
#define STOCK00_H_
#include <string>
using namespace std;
class matrix // class declaration
{
  private:
    int col;
    int row;
public:
    float **p;
    matrix(int, int);
    ~matrix();
    void Show() const;
    matrix& operator=(const matrix&);//矩阵的复制
    matrix& operator+(const matrix&);
    matrix operator*(const matrix&);
    matrix& operator*(int a);
    friend matrix& operator*(int a, matrix& n);
    friend ostream & operator<<(ostream & os, const matrix & t);
    friend std::istream& operator>>(std::istream&, matrix&);
    
}; // note semicolon at the end

#endif
