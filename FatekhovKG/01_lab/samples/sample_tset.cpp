#include <iostream>
#include "tset.h"

int main()
{
    cout << "------TSET_TEST------" << endl;
    TSet set1(6);
    set1.InsElem(0);
    set1.InsElem(5);
    TSet set2(6);
    cout << "enter set length 6" << endl;
    cin >> set2;
    cout << "set1 = " << set1;
    cout << endl << "set2 = " << set2 << endl;
    cout << "Equal test:" << endl;
    int a = (set1 != set2);
    int b = (set1 == set2);
    std::cout << "set1 != set2 ->" << a << endl << "set1 == set2 ->" << b << std::endl;
    TSet set4(1);
    TSet set3(set1);
    set3.InsElem(2);
    cout << "set3(s1).inselem(2) -> " << set3 << endl;
    int g = set3.GetMaxPower();
    cout << "set3.maxpower -> " << g << endl;
    set4 = set3;
    set3.DelElem(3);
    cout << "set4 = set3 -> " << set4 << endl;
    cout << "set3.delelem(3)-> " << set3 << endl;
    set3 = set4 + set2;
    cout << "set3 = set4 + set2 -> " << set3 << endl;
    set2 = set2 * set4;
    cout << "set2 = set2 * set4 -> " << set2 << endl;
    set1 = ~set3;
    cout << "set1 = ~set3 -> " << set1 << endl;
    system("PAUSE");
    return 0;
}
