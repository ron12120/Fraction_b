#include <iostream>
#include <istream>
#include <algorithm>
#include <limits>
#pragma once

using namespace std;
namespace ariel{
    class Fraction{
        int _numerator;
        int _denominator;
        void reduce();
        
        public:

        Fraction(int numerator ,int denominator);
        Fraction(float number);
        Fraction();

        int getNumerator()const{return this->_numerator;}
        int getDenominator()const{return this-> _denominator;}

        
        Fraction operator+(const Fraction &frac)const;
        Fraction operator+(float number);
        friend Fraction operator+(float number, const Fraction &frac);

        Fraction operator-(const Fraction &frac);
        Fraction operator-(float number);
        friend Fraction operator-(float number, const Fraction &frac);

        Fraction operator*(const Fraction &frac);;
        Fraction operator*(float number);
        friend Fraction operator*(float number, const Fraction &frac);

        Fraction operator/(const Fraction &frac);
        Fraction operator/(float number);
        friend Fraction operator/(float number, const Fraction &frac);

        Fraction operator++(int);
        Fraction operator++();

        Fraction operator--(int);
        Fraction operator--();

        bool operator>(const Fraction &frac)const;
        bool operator>(float number);
        friend bool operator>(float number, const Fraction &frac);

        bool operator<(const Fraction &frac)const;
        bool operator<(float number);
        friend bool operator<(float number, const Fraction &frac);

        bool operator>=(const Fraction &franc)const;
        bool operator>=(float number);
        friend bool operator>=( float number, const Fraction &franc);

        bool operator<=(const Fraction &franc)const;
        bool operator<=(float number);
        friend bool operator<=(float number, const Fraction &franc);

        bool operator==(const Fraction &franc)const;
        bool operator==(float number)const;
        friend bool operator==(float number, const Fraction &franc);


        friend ostream &operator<<(ostream &ostr, const Fraction &frac);
        friend istream &operator>>(istream &istr,Fraction &frac);
        
    };
     
};
