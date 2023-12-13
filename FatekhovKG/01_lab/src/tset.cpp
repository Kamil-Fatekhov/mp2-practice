// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : BitField(mp)
{
	MaxPower = mp;
}


TSet::TSet(const TSet& s) : BitField(s.BitField)
{
	MaxPower = s.GetMaxPower();
}


TSet::TSet(const TBitField& bf) : BitField(bf)
{
	MaxPower = bf.GetLength();
}

TSet::operator TBitField()
{
	return BitField;
}

int TSet::GetMaxPower(void) const 
{
	return MaxPower;
}

int TSet::IsMember(const int Elem) const 
{
	if ((Elem < MaxPower) & (Elem >= 0))
		if (BitField.GetBit(Elem) == 1) return 1;
		else return 0; else throw "Negative Elem";
}

void TSet::InsElem(const int Elem) 
{
	if ((Elem < MaxPower) & (Elem >= 0))
		BitField.SetBit(Elem); else throw "Negative n";
}

void TSet::DelElem(const int Elem) 
{
	if ((Elem < MaxPower) & (Elem >= 0))
		BitField.ClrBit(Elem); else throw "Negative n";
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet& s) 
{
	if ((*this) == s) return (*this);
	MaxPower = s.MaxPower;
	BitField = s.BitField;
	return *this;
}

int TSet::operator==(const TSet& s) const 
{
	if (MaxPower != s.GetMaxPower())
		return 0;

	for (int i = 0; i < MaxPower; ++i)
	{
		if (BitField.GetBit(i) != s.BitField.GetBit(i))
			return 0;
	}
	return 1;
}

int TSet::operator!=(const TSet& s) const 
{
	return !(*this == s);
}

TSet TSet::operator+(const TSet& s) 
{
	TSet A(max(MaxPower, s.GetMaxPower()));
	A.BitField = BitField | s.BitField;
	return A;
}



TSet TSet::operator+(const int Elem) 
{
	TSet a(*this);
	if ((Elem < MaxPower) & (Elem >= 0)) {
		a.InsElem(Elem);
	}
	else throw "Negative Elem";
	return a;
}

TSet TSet::operator-(const int Elem) 
{
	TSet a(*this);
	if ((Elem < MaxPower) & (Elem >= 0)) {
		a.DelElem(Elem);
	}
	else throw "Negative Elem";
	return a;
}

TSet TSet::operator*(const TSet& s) 
{
	TSet a(BitField & s.BitField);
	return a;
}

TSet TSet::operator~(void) 
{
	TSet a(~BitField);
	return a;

}


istream& operator>>(istream& istr, TSet& s) 
{
	for (int i = 0; i < s.MaxPower; i++) {
		s.DelElem(i);
	}
	cout << "Input your set (enter any negative to stop)" << endl;
	int i;

	while (1) {
		istr >> i;
		if (i < 0) {
			return istr;
		}
		if   ((i > s.MaxPower)) {
			throw "OUTOFRANGE";
		}
		s.InsElem(i);
	}
	return istr;
}

ostream& operator<<(ostream& ostr, const TSet& s) 
{
	cout << s.BitField;
	return ostr;
}