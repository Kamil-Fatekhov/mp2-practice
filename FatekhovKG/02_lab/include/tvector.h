#pragma once
#include <iostream>;
using namespace std;

const int MAX_VECTOR_SIZE = 100000000;


// Шаблон вектора
template <class ValType>
class TVector
{
protected:
    ValType* pVector;
    int Size;       // размер вектора
    int StartIndex; // индекс первого элемента вектора
public:
    TVector(int s = 10, int si = 0);
    TVector(const TVector& v);                // конструктор копирования
    ~TVector();
    int GetSize() { return Size; } // размер вектора
    int GetStartIndex() { return StartIndex; } // индекс первого элемента
    ValType& operator[](int pos);        
    //ValType& operator[](int pos) const;  // доступ
    bool operator==(const TVector& v) const;  // сравнение
    bool operator!=(const TVector& v) const;  // сравнение
    TVector& operator=(const TVector& v);     // присваивание

    // скалярные операции
    TVector  operator+(const ValType& val);   // прибавить скаляр
    TVector  operator-(const ValType& val);   // вычесть скаляр
    TVector  operator*(const ValType& val);   // умножить на скаляр

    // векторные операции
    TVector  operator+(const TVector& v);     // сложение
    TVector  operator-(const TVector& v);     // вычитание
    ValType  operator*(const TVector& v);     // скалярное произведение

    // ввод-вывод
    friend istream& operator>>(istream& in, TVector& v)
    {
        for (int i = 0; i < v.Size; i++)
            in >> v.pVector[i];
        return in;
    }
    friend ostream& operator<<(ostream& out, const TVector& v)
    {
        for (int i = 0; i < v.Size; i++)
            out << v.pVector[i] << ' ';
        return out;
    }
};

template <class ValType>
TVector<ValType>::TVector(int s, int si)
{
    if (s < 0) throw "Size cant be negative";
    if (s > MAX_VECTOR_SIZE) throw  "size is too large";
    Size = s;
    if (si < 0) throw "StartIndex cant be negative";
    /*if (si > s) throw "StartIndex cant be more than vector size";*/
    StartIndex = si;
    pVector = new ValType[Size];
    for (int i = 0; i < Size; i++) {
        pVector[i] = 0;
    }
} /*-------------------------------------------------------------------------*/

template <class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector& v)
{
    Size = v.Size;
    StartIndex = v.StartIndex;
    pVector = new ValType[Size];
    for (int i = 0; i < Size; i++) pVector[i] = v.pVector[i];
} /*-------------------------------------------------------------------------*/

template <class ValType>
TVector<ValType>::~TVector()
{
    delete[] pVector;
} /*-------------------------------------------------------------------------*/

template <class ValType> // доступ
ValType& TVector<ValType>::operator[](const int pos)
{
    if (pos < 0) throw "negative ind";
    if (pos < StartIndex) throw "invalid ind";
    if (pos > Size + StartIndex) throw "invalid size";
    return pVector[pos - StartIndex];
} /*-------------------------------------------------------------------------*/

//template <class ValType> // доступ
//ValType& TVector<ValType>::operator[](int pos) const
//{
//    return pVector[pos];
//}/*-------------------------------------------------------------------------*/
template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector<ValType>& v) const
{
    if (Size != v.Size) return false;
    if (StartIndex != v.StartIndex) return false;
    for (int i = 0; i < Size; i++) {
        if (pVector[i] != v.pVector[i]) return false;
    }
    return true;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator!=(const TVector& v) const
{
    return !(*this == v);
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector& v)
{
    if (*this == v) return *this;
    delete[] pVector;
    Size = v.Size;
    pVector = new ValType[Size];
    StartIndex = v.StartIndex;
    for (int i = 0; i < Size; i++) {
        pVector[i] = v.pVector[i];
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType& val)
{
    TVector<ValType> tmp(Size, StartIndex);
    for (int i = 0; i < Size; i++) 
       tmp.pVector[i] = pVector[i] + val;
    return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType& val)
{
    TVector<ValType> tmp(Size, StartIndex);
    for (int i = 0; i < Size; i++)
        tmp.pVector[i] = pVector[i] - val;
    return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType& val)
{
    TVector<ValType> tmp(Size, StartIndex);
    for (int i = 0; i < Size; i++)
        tmp.pVector[i] = pVector[i] * val;
    return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType>& v)
{
    if (Size != v.Size) throw "Vector sizes have to be equal";
    if (StartIndex != v.StartIndex) throw "Vector start indexes have to be equal";
    TVector<ValType> tmp(Size, StartIndex);
    for (int i = 0; i < Size; i++)
        tmp.pVector[i] = pVector[i] + v.pVector[i];
    return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType>& v)
{
    if (Size != v.Size) throw "Vector sizes have to be equal";
    if (StartIndex != v.StartIndex) throw "Vector start indexes have to be equal";
    TVector<ValType> tmp(Size, StartIndex);
    for (int i = 0; i < Size; i++)
        tmp.pVector[i] = pVector[i] - v.pVector[i];
    return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType>& v)
{
    if (Size != v.Size) throw "Vector sizes have to be equal";
    if (StartIndex != v.StartIndex) throw "Vector start indexes have to be equal";
    ValType tmp = ValType();
    for (int i = 0; i < Size; i++) {
        tmp += pVector[i] * v.pVector[i];
    }
    return tmp;
} /*-------------------------------------------------------------------------*/