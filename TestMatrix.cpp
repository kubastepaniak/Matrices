#include "Matrix.h"
#define BAR "\n----------------------------\n"
using namespace std;

int main()
{
	Matrix m(2, 3);
	cin >> m;
	cout << BAR << m;

	Matrix m2(m);
	cout << BAR << m2;

	Matrix m3;
	m3 = m;
	cout << BAR << m3;

	Matrix m4(3, 3);
	cin >> m4;
	cout << BAR << m4;

	cout << BAR << m(1, 2) << endl;
	m(1, 2) = 23;
	cout << m(1, 2) << endl;
	cout << m;

	cout << BAR << m2;
	m2 += m3;
	cout << m2 << m3;

	/*Matrix m5;
	m5 = m + m4;
	cout << BAR << m5;*/		// causes DifferentMatrixDimensions exception

	Matrix m6;
	m6 = m2 * m4;
	cout << BAR << m6;

	return 0;
}