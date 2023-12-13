// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len)
{
	if (len < 0) throw "length can`t be negative";
	BitLen = len;
	MemLen = BitLen / (sizeof(TELEM) * 8) + 1;
	pMem = new TELEM[MemLen];
	for (int i = 0; i < MemLen; i++) pMem[i] = 0;
}
TBitField::TBitField(const TBitField& bf) {
	BitLen = bf.BitLen;
	MemLen = bf.MemLen;
	pMem = new TELEM[MemLen];
	for (int i = 0; i < MemLen; i++) pMem[i] = bf.pMem[i];
}
TBitField::~TBitField() {
	delete[] pMem;
}
int TBitField::GetMemIndex(const int n) const {
	return (n / (sizeof(TELEM) * 8));
}
TELEM TBitField::GetMemMask(const int n) const {
	if ((n > BitLen) || (n < 0)) throw "Negative n";
	return 1 << (n & (sizeof(TELEM) * 8 - 1));
}
int TBitField::GetLength(void) const {
	return BitLen;
}
void TBitField::SetBit(const int n) {
	if ((n > BitLen) || (n < 0)) throw "Negative n";
	pMem[GetMemIndex(n)] = (GetMemMask(n) | pMem[GetMemIndex(n)]);
}

void TBitField::ClrBit(const int n) {
	if ((n > BitLen) || (n < 0)) throw "Negative n";
	pMem[GetMemIndex(n)] &= (~GetMemMask(n));
}

int TBitField::GetBit(const int n) const {
	if ((n > BitLen) || (n < 0)) throw "Negative n";
	if (pMem[GetMemIndex(n)] & GetMemMask(n)) return 1; else return 0;
}

ostream& operator <<(ostream& ostr, const TBitField& bf) {


	for (int i = 0; i < bf.BitLen; i++)
		if (bf.GetBit(i) == 0)
			ostr << 0;
		else ostr << 1;
	ostr << endl;
	return ostr;

}
TBitField& TBitField::operator=(const TBitField& bf) {
	if (this == &bf) {
		return(*this);
	}
	BitLen = bf.BitLen;
	MemLen = bf.MemLen;
	delete[] pMem;
	pMem = new TELEM[MemLen];
	for (int i = 0; i < MemLen; i++) 
		pMem[i] = bf.pMem[i];
	return *this;
	
}

int TBitField::operator==(const TBitField& bf) const 
{
	if (BitLen != bf.GetLength())
		return 0;
	else
	{
		for (int i = 0; i < BitLen; ++i)
		{
			if (GetBit(i) != bf.GetBit(i))
				return 0;
		}
	}
	return 1;
}

int TBitField::operator!=(const TBitField& bf) const 
{
	return !((*this) == bf);

}

TBitField TBitField::operator|(const TBitField& bf) 
{
	TBitField tmp(max(BitLen, bf.BitLen));
	for (int i = 0; i < BitLen; i++) {
		if (GetBit(i)) {
			tmp.SetBit(i);
		}
	}
	for (int i = 0; i < bf.MemLen; i++) {
		tmp.pMem[i] = tmp.pMem[i] |= bf.pMem[i];
	}
	return (tmp);
	
}

TBitField TBitField::operator&(const TBitField& bf) 
{
	TBitField tmp(max(BitLen, bf.BitLen));
	for (int i = 0; i < min(MemLen, bf.MemLen); i++) {
		tmp.pMem[i] = pMem[i] & bf.pMem[i];
	}
	return (tmp);
}
TBitField TBitField::operator~(void) 
{
	TBitField a(*this);
	for (int i = 0; i < (a.MemLen - 1); i++) a.pMem[i] = ~(a.pMem[i]);
	for (int i = ((a.MemLen - 1) * (sizeof(TELEM) * 8)); i < (a.BitLen); i++) {
		if (a.GetBit(i) == 1) a.ClrBit(i);
		else a.SetBit(i);
	}
	return a;
}



istream& operator>>(istream& istr, TBitField& bf) 
{
	int tmp;
	for (int i = 0; i < bf.BitLen; i++) {
		istr >> tmp;
		if ((tmp != 0) && (tmp != 1)) {
			throw "The bit cannot take such a value";
		}

		if (tmp == 0) {
			bf.ClrBit(i);
		}
		else {
			bf.SetBit(i);
		}
	}
	return istr;
}