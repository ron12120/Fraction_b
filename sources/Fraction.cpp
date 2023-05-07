#include "Fraction.hpp"
     using namespace std;
     namespace ariel
     {
          Fraction::Fraction(int numerator ,int denominator):_numerator(numerator),_denominator(denominator){
               if (denominator==0)
                    throw invalid_argument("can't divide in zero");
               if(denominator<0){
                    _numerator*=-1;
                    _denominator*=-1;
               }
               reduce();
          };
          Fraction::Fraction(float number){
               this->_numerator= number*1000;
               this->_denominator=1000;
               reduce();
          }
          Fraction::Fraction():_numerator(0),_denominator(1){};

          void Fraction::reduce(){
               int gcd= __gcd(_numerator,_denominator);
               _numerator/=gcd;
               _denominator/=gcd;   
               if(gcd<0)
               {
                    _numerator*=-1;
                    _denominator*=-1;
               }
          }
          
          //operator +
          Fraction Fraction:: operator+(const Fraction &frac)const{
               long long num1 = static_cast<long long>(this-> _numerator) * static_cast<long long>(frac._denominator);
               long long num2 = static_cast<long long>(this->_denominator) * static_cast<long long>(frac._numerator);
               long long up =num1+num2;
               long long down= static_cast<long long>(this->_denominator) * static_cast<long long>(frac._denominator);
               if((up>std::numeric_limits<int>::max())||(down>std::numeric_limits<int>::max()))
                    throw overflow_error("the fraction is too big");
               if((up<std::numeric_limits<int>::min())||(down<std::numeric_limits<int>::min()))
                    throw overflow_error("the fraction is too small");
               Fraction ans(up,down);
               return ans;   
          }
          Fraction Fraction:: operator+(float number){
               Fraction temp(number);
               return(*this+temp);
          }
          Fraction operator+(float number, const Fraction &frac) 
          {
               Fraction temp(number);
               return (frac+temp);     
          }

          //operator -
          Fraction Fraction:: operator-(const Fraction &frac){
               long long num1 = static_cast<long long>(this-> _numerator) * static_cast<long long>(frac._denominator);
               long long num2 = static_cast<long long>(this->_denominator) * static_cast<long long>(frac._numerator);
               long long up =num1-num2;
               long long down= static_cast<long long>(this->_denominator) * static_cast<long long>(frac._denominator);
               if((up>std::numeric_limits<int>::max())||(down>std::numeric_limits<int>::max()))
                    throw overflow_error("the fraction is too big");
               if((up<std::numeric_limits<int>::min())||(down<std::numeric_limits<int>::min()))
                    throw overflow_error("the fraction is too small");
               Fraction ans(up,down);
               return (ans);
          }    
          Fraction Fraction:: operator-(float number){
               Fraction temp(number);
               return(*this-temp);
          }
          Fraction operator-(float number, const Fraction &frac) 
          { 
               Fraction temp(number);
               return(temp-frac);
          }

          //opertor *
          Fraction Fraction:: operator*(const Fraction &frac){
               long long up = static_cast<long long>(this-> _numerator) * static_cast<long long>(frac._numerator);
               long long down= static_cast<long long>(this->_denominator) * static_cast<long long>(frac._denominator);
               if((up>std::numeric_limits<int>::max())||(down>std::numeric_limits<int>::max()))
                    throw overflow_error("the fraction is too big");
               if((up<std::numeric_limits<int>::min())||(down<std::numeric_limits<int>::min()))
                    throw overflow_error("the fraction is too small");
               Fraction temp(up,down);
               return (temp);
          }
          Fraction Fraction::operator*(float number){
               Fraction temp(number);
               return (*this*temp);
          }
          Fraction operator*(float number, const Fraction &frac){
                Fraction temp(number);
                return(temp*frac);
          }

          //operator /
          Fraction Fraction:: operator/(const Fraction &frac){
               if(frac._numerator==0)
                    throw runtime_error("can't divide in zero");
               Fraction temp(frac._denominator,frac._numerator);
               return(*this*temp);
          }
          Fraction Fraction::operator/(float number){
               if(number==0)
                    throw runtime_error("can't divide in zero");
               Fraction temp(number);
               return (*this/temp);
          }
          Fraction operator/(float number, const Fraction &frac){
               if(frac._numerator==0)
                    throw runtime_error("can't divide in zero");
                Fraction temp(number);
                return(temp/frac);
          }

          //operator ++
          Fraction Fraction:: operator++(int){
               Fraction temp(*this);
               int up = this->_numerator+=this->_denominator;
               Fraction ans(up,this->_denominator);
               *this=ans;
               return temp;
          }
          Fraction Fraction:: operator++(){
               int up = this->_numerator+=this->_denominator;
               Fraction ans(up,this->_denominator);
               *this=ans;
               return *this;
          }

          //operator --
          Fraction Fraction:: operator--(int){
               Fraction temp(*this);
               int up = this->_numerator-=this->_denominator;
               Fraction ans(up,this->_denominator);
               *this=ans;
               return temp;
          }
          Fraction Fraction:: operator--(){
               int up = this->_numerator-=this->_denominator;
               Fraction ans(up,this->_denominator);
               *this=ans;
               return *this;
          }

           //operator >
          bool Fraction:: operator>(const Fraction &frac)const{
               int sum1= this->_numerator * frac._denominator;
               int sum2= this->_denominator * frac._numerator;
               return(sum1>sum2);
          }
          bool Fraction::operator>(float number){
               Fraction temp(number);
               return (*this>temp);
          }
          bool operator>(float number, const Fraction &frac){
                Fraction temp(number);
                return(temp>frac);
          }

          //operator <
          bool Fraction::operator<(const Fraction &frac)const{
               int sum1= this->_numerator * frac._denominator;
               int sum2= this->_denominator * frac._numerator;
               return(sum1<sum2);
          }
          bool Fraction::operator<(float number){
               Fraction temp(number);
               return (*this<temp);
          }
          bool operator<(float number,const Fraction &frac){
                Fraction temp(number);
                return(temp<frac);
          }


          //operator >=
          bool Fraction:: operator>=(const Fraction &frac)const{
               int sum1= this->_numerator * frac._denominator;
               int sum2= this->_denominator * frac._numerator;
               return(sum1>=sum2);
          }
          bool Fraction::operator>=(float number){
               Fraction temp(number);
               return (*this>=temp);
          }
          bool operator>=(float number,const Fraction &frac){
                Fraction temp(number);
                return(temp>=frac);
          }

          //operator <=
          bool Fraction:: operator<=(const Fraction &frac)const{
               int sum1= this->_numerator * frac._denominator;
               int sum2= this->_denominator * frac._numerator;
               return(sum1<=sum2);
          }
          bool Fraction::operator<=(float number){
               Fraction temp(number);
               return (*this<=temp);
          }
          bool operator<=(float number,const Fraction &frac){
                Fraction temp(number);
                return(temp<=frac);
          }

          //operator ==
          bool Fraction:: operator==(const Fraction &frac)const{
               int sum1= this->_numerator * frac._denominator;
               int sum2= this->_denominator * frac._numerator;
               return(sum1==sum2);
          }
          bool Fraction::operator==(float number)const{
               Fraction temp(number);
               return (*this == temp);
          }
          bool operator==(float number,const Fraction &frac){
                Fraction temp(number);
                return(temp==frac);
          }
          ostream &operator<<(ostream &ostr, const Fraction &frac) 
          { 
               ostr<<frac._numerator<<"/"<<frac._denominator;
               return ostr;
          }
          istream &operator>>(istream &istr,Fraction &franc)
          {
               int up, down;
               istr>>up>>down;
               if(istr.fail())
                    throw runtime_error("the input is not proper");
               else
               {  
                    if(down==0)
                         throw runtime_error("can't divide in zero");
                    franc = Fraction(up,down);
               }
               return istr;
          }

     }