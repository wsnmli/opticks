#pragma once

#include <iostream>
using namespace std;

template <typename T>
class Complex { public:
    Complex(T real, T imag) :real(real), imag(imag) {}
    Complex( ) :real(0), imag(0) {}
    T real, imag;

};