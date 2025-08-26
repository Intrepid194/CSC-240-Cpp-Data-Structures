// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include "frac.h"
int main()
{

	FractionType one;
	FractionType two;
	one.Initialize(2112, 32133);
	two.Initialize(45433, 53453);
	FractionType three = one + two;
	three.print();

	three = one - two;
	three.print();
	// FractionType x;
	// FractionType y;
	// x.Initialize(1, 3);
	// y.Initialize(2, 3);
	// FractionType z = x + y;
	// // z.print();

	// // z.reduce();
	// // z.print();

	// FractionType g;
	// g.Initialize(15, 20);
	// // g.reduce();
	// // g.print();
}
