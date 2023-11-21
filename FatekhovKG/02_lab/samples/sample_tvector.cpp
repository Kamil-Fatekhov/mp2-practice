#include "tvector.h"

void main() {
	TVector<int> b(4, 0);
	TVector<int> a(4, 0);
	int c;
	cin >> b;
	cout << b<<endl;
	cin >> a;
	cout << a << endl;
	c = a * b;
	cout << c;
}