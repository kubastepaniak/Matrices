#include "Matrix.h"

Matrix::Matrix()
{
	mat = NULL;
}

Matrix::Matrix(unsigned int x, unsigned int y)
{
	mat = new rcmat(x, y);
}

Matrix::~Matrix()
{
	mat->refCount--;
	if(mat->refCount == 0)
		delete mat;
	else
		mat = NULL;
}

Matrix::rcmat::rcmat(unsigned int x, unsigned int y)
{
	xSize = x;
	ySize = y;
	refCount = 1;
	data = new double*[xSize];
	for(int xIt = 0; xIt < xSize; xIt++)
	{
		data[xIt] = new double[ySize];
	}
}

Matrix::rcmat::rcmat(unsigned int x, unsigned int y, double** data)
{
	xSize = x;
	ySize = y;
	refCount = 1;
	this->data = new double*[xSize];
	for(int xIt = 0; xIt < xSize; xIt++)
	{
		this->data[xIt] = new double[ySize];
		for(int yIt = 0; yIt<ySize; yIt++)
		{
			this->data[xIt][yIt] = data[xIt][yIt];
		}
	}
}

Matrix::rcmat::~rcmat()
{
	for(int xIt = 0; xIt < xSize; xIt++)
	{
		delete [] data[xIt];
	}
	delete [] data;
}

Matrix::Matrix(const Matrix& m)
{
	this->mat = m.mat;
	m.mat->refCount++;
}

void Matrix::detach()
{
	rcmat* newTab = new rcmat(mat->xSize, mat->ySize, mat->data);
	if(mat->refCount == 1)
		this->mat = newTab;
	else
	{
		mat->refCount--;
		this->mat = newTab;
	}
}

void Matrix::operator=(const Matrix& m)
{
	this->mat = m.mat;
	m.mat->refCount++;
}

Matrix::Dref Matrix::operator()(unsigned int x, unsigned int y)
{
	return Dref(*this, x, y);
}

double Matrix::operator()(unsigned int x, unsigned int y) const
{
	return mat->data[x][y];
}

Matrix& Matrix::operator+(const Matrix& m)
{
	if(this->mat->xSize == m.mat->xSize && this->mat->ySize == m.mat->ySize)
		std::cout << "addition";
	else
		std::cout << "cannot add matrices" << std::endl;
}

std::istream& operator>>(std::istream& in, const Matrix& m)
{
	for(int x = 0; x < m.mat->xSize; x++)
	{
		for(int y = 0; y < m.mat->ySize; y++)
		{
			in >> m.mat->data[x][y];
		}
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Matrix& m)
{
	out << "\n";
	for(int x = 0; x < m.mat->xSize; x++)
	{
		for(int y = 0; y < m.mat->ySize; y++)
		{
			out << m.mat->data[x][y] << "\t";
		}
		out << "\n";
	}
	return out;
}

Matrix::Dref::operator double() const
{
	return matrix.mat->data[x][y];
}

Matrix::Dref& Matrix::Dref::operator=(double n)
{
	matrix.detach();
	matrix.mat->data[x][y] = n;
	return *this;
}

Matrix::Dref& Matrix::Dref::operator=(const Dref& ref)
{
	return operator=((double)ref);
}
