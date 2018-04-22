//
// Created by aimar on 2018/4/22.
//

#ifndef __STRUCTURES_H__
#define __STRUCTURES_H__

class Complex{
public:
    double dReal, dImag;

    Complex(){  dReal = 0; dImag = 0;}
    Complex(double r, double i){
        this->dReal = r;
        this->dImag = i;
    }

    // 写在类里面
    // 友元函数是可以直接访问类的私有成员的非成员函数。它是定义在类外的普通函数，它
    // 不属于任何类，但需要在类的定义中加以声明，声明时只需在友元的名称前加上关键字friend
    //friend Complex operator+(Complex obj1, Complex obj2);
};

// 重载操作符写在类的外面
Complex operator+(Complex obj1, Complex obj2);

#endif //__STRUCTURES_H__
