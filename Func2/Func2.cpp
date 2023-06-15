#include <iostream>
#include <cmath>

double Hyp(double a, double b) {
	return std::sqrt(a * a + b * b);
}

double TriArea(double a, double b) {
	return (a * b) / 2;
}

int main() {
	//double sides = { a, b,	ba,		c,	cba,	 d,		dcba,	e,		edcba };
	//double sides = { 0, 1,	2,		3,	4,		 5,		6,		7,		8 };
	double sides[9];

	std::cout << "Enter a: ";
	std::cin >> sides[0];

	std::cout << "Enter b: ";
	std::cin >> sides[1];

	std::cout << "Enter c: ";
	std::cin >> sides[3];

	std::cout << "Enter d: ";
	std::cin >> sides[5];

	std::cout << "Enter e: ";
	std::cin >> sides[7];

	if (sides[0] < 0 || sides[1] < 0 || sides[3] < 0 || sides[5] < 0 || sides[7] < 0) {
		std::cout << "Error! The sides cannot be negative" << std::endl;
		return -1;
	}

	double sq = 0;
	for (int i = 1; i <=7; i+=2) {
		sides[i+1]=Hyp (sides[i-1], sides[i]);
		sq += (sides[i - 1] * sides[i]) / 2;
	}

	
	double per = sides[0];
	for (int i=1; i<=7; i+=2)
	{
		if (i + 2 != 9)
			per += sides[i];
		else { per += sides[i] + sides[i+1];}
	}

	std::cout << "\nAll numbers:" << std::endl;
	for (int i = 0; i < 9; i++) {
		std::cout <<i<<". "<< sides[i] << std::endl;
	}

	std::cout << "\nSquare: " << sq << std::endl;
	std::cout << "Perimetr: " << per<<std::endl;
}