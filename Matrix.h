#pragma once
#include <iostream>

class Matrix {
	struct rcmat;
	rcmat *mat;
public:
	class Dref;
	Matrix();
	Matrix(unsigned int x, unsigned int y);
	Matrix(const Matrix& m);
	~Matrix();
	void detach();
	bool checkDimensions(const Matrix& m);
	bool checkMultiplicationCondition(const Matrix& m);
	void operator=(const Matrix& m);
	Dref operator()(unsigned int x, unsigned int y);
	double operator()(unsigned int x, unsigned int y) const;
	Matrix& operator+=(const Matrix& m);
	Matrix& operator-=(const Matrix& m);
	Matrix& operator*=(const Matrix& m);
	Matrix operator+(const Matrix& m);
	Matrix operator-(const Matrix& m);
	Matrix operator*(const Matrix& m);
	friend std::istream& operator>>(std::istream& in, const Matrix& m);
	friend std::ostream& operator<<(std::ostream& out, const Matrix& m);
};

struct Matrix::rcmat {
	double **data;
	unsigned int xSize, ySize;
	unsigned int refCount;
	rcmat(unsigned int x, unsigned int y);
	rcmat(unsigned int x, unsigned int y, double** data);
	~rcmat();
};

class Matrix::Dref {
	friend class Matrix;
	Matrix& matrix;
	unsigned int x, y;
	Dref(Matrix& initMat, unsigned int xAt, unsigned int yAt)
		:matrix(initMat), x(xAt), y(yAt) {};
public:
	operator double() const;
	Matrix::Dref& operator=(double n);
	Matrix::Dref& operator=(const Dref& ref);
};
