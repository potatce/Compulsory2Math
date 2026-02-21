#pragma once

class Vector3D {

public:
    Vector3D();

private:
    static const int M = 10;
    static const int N = 10;
    static const int O = 10;
    double A[M][N][O];
    int m;
    int n;
    int o;
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
    Matrix inverse();
    Vector3D multiply(Vector3D v);
private:
    static const int M = 10;
    static const int N = 10;
    double A[M][N];
    int m; // actual number of rows
    int n; // actual number of columns
};
