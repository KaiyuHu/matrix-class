//
//  main.cpp
//  assignment-4-8
//
//  Created by 胡开域 on 2020/11/28.
//  Copyright © 2020 胡开域. All rights reserved.
//

#include <iostream>
#include "matrix.hpp"
int main()
{
    matrix a = matrix(16,16);
    cout<<"matrix a is"<<endl;
    cout<<a;
    matrix b = matrix(16,16);
    cout<<"matrix b is"<<endl;
    cout<<b;
    matrix c = a*b;
    cout<<"matrix c = a*b, matrix c is "<<endl;
    cout<<c;
    matrix d = matrix(16,16);
    d = c;
    cout<<"matrix d = c, matrix d is "<<endl;
    cout<<d<<endl;
    matrix e = matrix(16, 16);
    cout<<"matrix e = a * 2"<<endl;
    e = a*2;
    cout<<e;
    matrix f = matrix(16, 16);
    f = 2*b;
    cout<<"matrix m = 2 * b "<<endl;
    cout<<f;
    return 0;
    
};
