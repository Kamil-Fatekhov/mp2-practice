#include "tvector.h"
#ifndef __TMATRIX_H__
#define __TMATRIX_H__

#include <iostream>

using namespace std;
const int MAX_MATRIX_SIZE = 10000;

// Верхнетреугольная матрица
template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
public:
    TMatrix(int s = 10);
    TMatrix(const TMatrix& mt);                    // копирование
    TMatrix(const TVector<TVector<ValType> >& mt); // преобразование типа
    bool operator==(const TMatrix& mt) const;      // сравнение
    bool operator!=(const TMatrix& mt) const;      // сравнение
    TMatrix& operator= (const TMatrix& mt);        // присваивание
    TMatrix  operator+ (const TMatrix& mt);        // сложение
    TMatrix  operator- (const TMatrix& mt);        // вычитание
    TMatrix  operator* (const TMatrix& mt);        // умножение
    // ввод / вывод
    friend istream& operator>>(istream& in, TMatrix& mt)
    {
        for (int i = 0; i < mt.Size; i++)
            in >> mt.pVector[i];
        return in;
    }
    friend ostream& operator<<(ostream& out, const TMatrix& mt)
    {
        for (int i = 0; i < mt.Size; i++)
            out << mt.pVector[i] << endl;
        return out;
    }
};

template <class ValType>
TMatrix<ValType>::TMatrix(int s) : TVector<TVector<ValType> >(s)
{
    if (s < 0) throw "Size cant be negative";
    if (s > MAX_MATRIX_SIZE) throw "Size is too large";
    for (int i = 0; i < s; i++) {
        pVector[i] = TVector<ValType>(s - i, i);
    }
} /*-------------------------------------------------------------------------*/

template <class ValType> // конструктор копирования
TMatrix<ValType>::TMatrix(const TMatrix<ValType>& mt) :
    TVector<TVector<ValType> >(mt) {}

template <class ValType> // конструктор преобразования типа
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> >& mt) :
    TVector<TVector<ValType> >(mt) {}

template <class ValType> // сравнение
bool TMatrix<ValType>::operator==(const TMatrix<ValType>& mt) const
{
    return TVector<TVector<ValType>>::operator==(mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TMatrix<ValType>::operator!=(const TMatrix<ValType>& mt) const
{
    return !(*this == mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType>& mt)
{
    if (this != &mt) { if (Size != mt.Size) {
    delete[] pVector;
    pVector = new TVector<ValType>[mt.Size];
    }
    Size = mt.Size;
    StartIndex = mt.StartIndex;
    for (int i = 0; i < Size; i++) pVector[i] = mt.pVector[i];
    } return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType>& mt)
{
    if (Size != mt.Size) throw "Sizes isnt equal";
    return TVector<TVector<ValType>>::operator+(mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType>& mt)
{
    if (Size != mt.Size) throw "Sizes isnt equal";
    return TVector<TVector<ValType>>::operator-(mt);
} /*-------------------------------------------------------------------------*/
template <class ValType> // умножение
TMatrix<ValType> TMatrix<ValType>::operator*(const TMatrix& mt)
{
    
    if (Size != mt.Size) throw "Not equal sizes";
    TMatrix res(Size);

    for (int i = 0; i < Size; ++i) {
        for (int j = i; j < Size; ++j) {
            res[i][j - i] = 0;
        }
    }

    for (int i = 0; i < Size; ++i) {
        for (int j = i; j < Size; ++j) {
            for (int k = i; k <= j; ++k) {
                res[i][j - i] += (*this)[i][k - i] * mt[k][j - k];
            }
        }
    }


    return res;
}

// TVector О3 Л2 П4 С6
// TMatrix О2 Л2 П3 С3
#endif
