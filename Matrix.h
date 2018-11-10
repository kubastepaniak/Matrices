#pragma once
#include <iostream>

class Matrix {
	class Dref;
	struct rcmat;
	rcmat *mat;
public:
	Matrix();
	Matrix(unsigned int x, unsigned int y);
	Matrix(const Matrix& m);
	~Matrix();
	void operator=(const Matrix& m);
	Dref operator()(unsigned int x, unsigned int y);
	double operator()(unsigned int x, unsigned int y) const;
	Matrix& operator+(const Matrix& m);
	friend std::istream& operator>>(std::istream& in, const Matrix& m);
	friend std::ostream& operator<<(std::ostream& out, const Matrix& m);
};

struct Matrix::rcmat {
	double **data;
	unsigned int xSize, ySize;
	unsigned int refCount;
	rcmat(unsigned int x = 0, unsigned int y = 0);
	~rcmat();
};

class Matrix::Dref {
	friend class Matrix;
	const Matrix& matrix;
	unsigned int x, y;
	Dref(const Matrix& initMat, unsigned int xAt, unsigned int yAt)
		:matrix(initMat), x(xAt), y(yAt) {};
public:
	operator double() const;
	Matrix::Dref& operator=(double n);
	Matrix::Dref& operator=(const Dref& ref);
};
