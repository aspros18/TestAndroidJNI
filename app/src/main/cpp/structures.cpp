//
// Created by aimar on 2018/4/22.
//

#include "structures.h"

Complex operator+(Complex obj1, Complex obj2)
{
    Complex ret;
    ret.dReal = obj1.dReal + obj2.dReal;
    ret.dImag = obj1.dImag + obj2.dImag;

    return ret;
}

