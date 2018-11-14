#include "Matrix.h"
using namespace std;

int main()
{
	Matrix m(2, 3);
	cin >> m;
	cout << m;

	Matrix m2(m);
	cout << m2;

	Matrix m3;
	m3 = m;
	cout << m3;

	cout << m(1, 2) << endl;
	m(1, 2) = 23;
	cout << m(1, 2) << endl;

	cout << m << m2 << m3;

	return 0;
}