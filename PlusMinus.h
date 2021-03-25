#ifndef PLUSMINUS_H
#define PLUSMINUS_H
#include <iostream>
#include <math.h>
class PlusMinus
{
private:
	unsigned int plusSign;
	unsigned int minusSign;

public:
	PlusMinus();
	PlusMinus(unsigned int& plusSign, unsigned int& minusSign);
	unsigned int getPlusSign() const { return plusSign; }
	void setPlusSign(unsigned int val) { plusSign = val; }
	unsigned int getMinusSign() const { return minusSign; }
	void setMinusSign(unsigned int val) { minusSign = val; }
	bool isPlusSignFour() const;
	void print() const;
	void getFromUser();
	std::pair<int, int> get();

};

#endif