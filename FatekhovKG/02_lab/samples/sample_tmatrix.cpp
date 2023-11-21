#include "tmatrix.h"

void main() {
	TMatrix<int> a(3);
	TMatrix<int>b(3);
	TMatrix<int> c(3);
	cin >> a;
	cout << a<<endl;
	cin >> b;
	cout << b<<endl;
	c = a * b;
	cout << c;
}
