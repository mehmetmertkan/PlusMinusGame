#ifndef NUMBER_H
#define NUMBER_H
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
class Number
{
private:
	unsigned int numberValue;

public:
	Number();
	Number(unsigned int number);
	unsigned int getNumberValue() const;
	void setNumberValue(unsigned int value);
	void print() const;
	void generateNumber();
	void getFromUserInput();
	bool areDigitsUnique(const unsigned int& number);
	unsigned int get();
	std::vector<unsigned int> convertIntToVec(const unsigned int& number);
};

#endif