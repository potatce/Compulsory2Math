#include "Matrix.h"
#include <iostream	>

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
	if ((m != other.n) || (n != other.m)) {
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
	if ((m != 3) && (n != 3)) {
		std::cout << "Please only run this with a 3x3 matrix.\n";
		return 0;
	}

	return A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1])
	- A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0])
		+ A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
}

Matrix Matrix::inverse()
{
	return Matrix();
}

Vector3D Matrix::multiply(Vector3D v)
{
	return Vector3D();
}
