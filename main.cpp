#include "fixed_point.h"
#include<cstdio>
//using namespace std;

void div_price() {

    FixedPoint <2, long>p(3, 50);
    FixedPoint <2, long>r(1, 50);
    FixedPoint <2, long> ra = p / r;

    if(ra == 2.33)
        std::cout << "Div is OK " << ra << std::endl;
}

void add_price() {

    FixedPoint <4,long>p(0,2000);
    FixedPoint <4, long>r(0, 1000);
    FixedPoint  <4, long> ra = p + r;

    if (ra == 0.3)
        std::cout << "Adding is OK" << std::endl;
}


void unar_price() {

    FixedPoint <4, long>p(3,5);
    //p = (-p);
    if ( p == -3.5000)
        std::cout << "unar is OK" << std::endl;
}

void mul_price() {

    FixedPoint <4, long>p(3);
    FixedPoint <4, long>r(1, 5555);
    FixedPoint  <4, long> ra = p * r;

    if(ra == 4.6665)
        std::cout << "Mul is OK " << ra << std::endl;
}

void mul_as_price() {

    FixedPoint <4, long>p(3);
    FixedPoint <4,long>r(1, 5555);
    r *= p;

    if (r == 4.6665)
        std::cout << "Mul is OK " << std::endl;
}

void temp_max()
{

    FixedPoint <1, char>p(12, 7);
    if (numeric_limits<FixedPoint<1, char> >::max() == p)
        std::cout << "Max tenplate is OK" << std::endl;

}

void test_fib()
{
    unsigned int fibo = compilation_fib<2>::value;
    if (fibo == 2)
        std::cout << "Fibo is OK "<< std::endl;
}

int main() {

    //FixedPoint <4>::theType p = 5;
    //cout<<FixedPoint::PRECISION<< endl ;
    //std::cout << p << std::endl;

    //div_price();
    //add_price();
    //mul_price();
    //unar_price();
    //mul_as_price();
    //temp_max();
    test_fib();

    std::cout << "im here" << std::endl;

    return 0;
}