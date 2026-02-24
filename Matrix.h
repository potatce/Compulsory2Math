#pragma once

class Vector3D {

public:
    Vector3D();
    Vector3D(double _x, double _y, double _z);

    double x;
    double y;
    double z;

};


class Matrix
{
public:
    Matrix();
    Matrix(int _m, int _n);

    void read();
    void print();
    Matrix multiply(Matrix other);
    Matrix transpose();
    double determinant();
    Matrix cofactor();
    Matrix inverse();
    Vector3D vectorMultiply(Vector3D v);
private:
    static const int M = 10;
    static const int N = 10;
    double A[M][N];
    int m; // actual number of rows
    int n; // actual number of columns
};
