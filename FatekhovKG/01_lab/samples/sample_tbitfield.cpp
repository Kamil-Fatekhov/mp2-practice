#include <iostream>
#include "tbitfield.h"

int main()
{
    cout << "------TBITFIELD_TEST------"<<endl;
    const int size1 = 3, size2 = 5;
    TBitField bf1(size1), bf2(size2);
    cout << "Equal test:"<<endl;
    int a = (bf1 != bf2);
    int b = (bf1 == bf2);
    cout << "bf1 = " << bf1 << endl << "bf2 = " << bf2 << endl;
    std::cout << "bf1 != bf2 -> " << a << endl << "bf1 == bf 2 -> " << b << std::endl;
    TBitField bf3(bf1);
    cout << "enter bitfield length 3" << endl;
    cin >> bf3;
    int c = bf3.GetLength();
    cout << "Length of bf3 = " << c << endl;
    bf3.SetBit(2);
    cout << "SetBit(2) for bf3: " << bf3<<endl;
    bf3.ClrBit(2);
    cout << "ClrBit(2) for bf3: " << bf3<<endl;
    const int g = bf3.GetBit(2);
    cout << "GetBit(2) for bf3: " << g << endl;
    bf2 = bf3;
    cout << "bf2 = bf3 -> " << bf2 << endl;
    bf2 = bf3 | bf1;
    cout << "bf2 = bf3 | bf1 -> " << bf2 << endl;
    bf2 = bf3 & bf1;
    cout << "bf2 = bf3 & bf1 -> " << bf2 << endl;
    bf2 = ~bf1;
    cout << "bf2 = ~bf1 -> " << bf2 << endl;
    system("PAUSE");
    return 0;
}
