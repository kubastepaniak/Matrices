#pragma once
using namespace std;

struct DifferentMatrixDimensions : public exception {
	const char* what () const throw () {
		return "Matrices have invalid dimensions";
	}
};