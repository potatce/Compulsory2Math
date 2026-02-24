#include "Matrix.h"

#include <iostream>
#include <list>

Matrix::Matrix()
{
	m = M;
	n = N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {

			A[i][j] = 0;
		}
	}
}

Matrix::Matrix(int _m, int _n) : m(_m), n(_n)
{
	for (int i = 0; i < _m; i++) {
		for (int j = 0; j < _n; j++) {

			A[i][j] = 0;
		}
	}
}


void Matrix::read()
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			
			std::cout << "Enter value for A[" << i << "][" << j << "]: ";
			std::cin >> A[i][j];

		}
	}
}

void Matrix::print()
{
	for (int i = 0; i < m; i++) {
		std::cout << "\n";
		for (int j = 0; j < n; j++) {

			std::cout << A[i][j] << " ";
		}
	}

	std::cout << "\n";
}

Matrix Matrix::multiply(Matrix other) {

	//Multiplication is defined if A has dimension m x n and B has dimension n x m.
	if ((n != other.m)) {
		std::cout << "Multiplication not defined\n";
		return Matrix();
	}


	Matrix result(m, other.n);

	for (int i = 0; i < result.m; i++) {
		for (int j = 0; j < result.n; j++) {


			double value = 0;

			for (int k = 0; k < n; k++) {

				value += A[i][k] * other.A[k][j];
			}

			result.A[i][j] = value;

		}
	}

	return result;
}


Matrix Matrix::transpose()
{
	Matrix result(m, n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {

			result.A[i][j] = A[j][i];
		}
	}

	return result;
}

double Matrix::determinant()
{
	//Only works with 3x3 matrix
	if ((m != 3) || (n != 3)) {
		std::cout << "Please only run this with a 3x3 matrix.\n";
		return 0;
	}

	return A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1])
	- A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0])
		+ A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
}

Matrix Matrix::cofactor() {
//only works for 3x3 matrix

	std::list<double> row1;
	std::list<double> row2;

	Matrix result(n, m);
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			//looping through the matrix
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < m; l++) {
					
					//check if he col or row are the same as the C. Adding to list.
					if ((k != i) && (l != j)) {

						if (row1.size() < n - 1) row1.push_back(A[k][l]);
						else if (row2.size() < m - 1) row2.push_back(A[k][l]);
					}
				}
			}

			result.A[i][j] = - ((row1.front() * row2.back()) - (row1.back() * row2.front()));
			
			/*check if the lists are correct
			for (double element : row1) { std::cout << element << " "; }
			std::cout << "\n";
			for (double element : row2) { std::cout << element << " "; }
			std::cout << "\n";
			std::cout << "\n";*/



			row1.clear();
			row2.clear();
		}
	}

	return result;
}

Matrix Matrix::inverse()
{
	if (determinant() == 0) {
		std::cout << "Matrix does not have an inverse";
		return Matrix();
	}

	//Only works with 3x3 matrix
	if ((m != 3) || (n != 3)) {
		std::cout << "Please only run this with a 3x3 matrix.\n";
		return Matrix();
	}

	Matrix result = cofactor().transpose();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			result.A[i][j] /= determinant();
		}
	}

	return result;
}



Vector3D Matrix::vectorMultiply(Vector3D v)
{
	if (m != 3) {
		std::cout << "Only multiply 3D vectors with a matrix that has as many columns as indexes in the vector.\n";
		return Vector3D();
	}

	Matrix vector3Matrix(3, 1);
	vector3Matrix.A[0][0] = v.x;
	vector3Matrix.A[1][0] = v.y;
	vector3Matrix.A[2][0] = v.z;

	vector3Matrix =  multiply(vector3Matrix);

	Vector3D result;
	result.x = vector3Matrix.A[0][0];
	result.y = vector3Matrix.A[1][0];
	result.z = vector3Matrix.A[2][0];

	return result;
}

Vector3D::Vector3D() {

	x = 0;
	y = 0;
	z = 0;

}

Vector3D::Vector3D(double _x, double _y, double _z) {

	x = _x;
	y = _y;
	z = _z;

}

