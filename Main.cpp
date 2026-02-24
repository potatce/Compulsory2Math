#include <iostream>
#include "Matrix.h"

int main() {

	Matrix m1(3, 3);
	m1.read();
	m1.print();

	std::cout << m1.vectorMultiply(Vector3D(1, 2, 3)).x << "\n";
	std::cout << m1.vectorMultiply(Vector3D(1, 2, 3)).y << "\n";
	std::cout << m1.vectorMultiply(Vector3D(1, 2, 3)).z << "\n";

/*
	m1.inverse().print();

	std::cout <<"Determinant: " << m1.determinant();
	m1.transpose().print();

	Matrix m2(3, 3);
	m2.read();
	m2.print();


	Matrix multiM = m1.multiply(m2);
	multiM.print();

	Matrix multiM2 = m2.multiply(m1);
	multiM2.print();

	multiM2.transpose().print();

*/
	return 0;
}