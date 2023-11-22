#include "tmatrix.h"

void main() {
	TMatrix<int> a(3);
	TMatrix<int> b(3);
	bool res = (a == b);
	cout << res;
	/*TMatrix<int> c(3);
	a[2][2] = 4;
	cout << a<<endl;
	cin >> b;
	cout << b<<endl;
	c = a * b;
	cout << c;*/
}
