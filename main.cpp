#include "fixed_point.h"
#include<cstdio>
using namespace std;

void div_price() {

	Price <long,2>p(3, 50);
	Price <long,2>r(3, 50);
	Price  <long,2> ra = p / r;
	
	cout << "div: " << ra << endl;
}

void add_price() {

	Price <long,4>p(0,2000);
	Price <long,4>r(0, 1000);
	Price  <long,4> ra = p + r;

	if (ra == 0.3)
		cout << "Adding is OK" << endl;
}


void unar_price() {

	Price <long, 4>p(3,5);
	cout << "unar: " << -p << endl;
}

void mul_price() {

	Price <long,4>p(3);
	Price <long,4>r(1, 5555);
	Price  <long,4> ra = p * r;

	cout << "mul: " << ra << endl;
}

void mul_as_price() {

	Price <long, 4>p(3);
	Price <long, 4>r(1, 5555);
	r *= p;
	cout <<"mul and assignment: " << r << endl;
}

int main() {

	div_price();
	add_price();
	mul_price();
	unar_price();
	mul_as_price();

	cout << "im here" << endl;

	return 0;
}