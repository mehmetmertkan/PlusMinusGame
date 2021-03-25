#include "Number.h"

Number::Number()
{
	numberValue = -1;
}

Number::Number(unsigned int number)
{
	numberValue = number;
}
unsigned int Number::getNumberValue() const 
{ 
	return numberValue; 
}

void Number::setNumberValue(unsigned int value)
{ 
	numberValue = value;
}

void Number::print() const
{
	std::cout << numberValue << std::endl;
}

//generates a random 4 digit number
void Number::generateNumber()
{
	std::vector<unsigned int> vec;
	srand(time(NULL));
	std::set<unsigned int> alreadyGeneratedDigits;
	while (vec.size() < 4)
	{
		unsigned int digi = rand() % 10;

		//handles first number not zero case
		if (digi == 0 && vec.size() == 0)
		{
			continue;
		}

		// for generating a unique number for every digit
		const bool is_in = alreadyGeneratedDigits.find(digi) != alreadyGeneratedDigits.end();
		if (!is_in)
		{
			alreadyGeneratedDigits.insert(digi);
			vec.push_back(digi);
		}
	}
	numberValue = vec[0] * 1000 + vec[1] * 100 + vec[2] * 10 + vec[3];
}

void Number::getFromUserInput()
{
	numberValue = get();
}

bool Number::areDigitsUnique(const unsigned int& number)
{
	std::vector<unsigned int> vec = convertIntToVec(number);
	std::unordered_set<unsigned int> unorderedSet;
	unorderedSet.insert(vec[0]);
	unorderedSet.insert(vec[1]);
	unorderedSet.insert(vec[2]);
	unorderedSet.insert(vec[3]);
	if (unorderedSet.size() == 4)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//checks if entered number is valid
unsigned int Number::get()
{
	int userInput = 0;
	while (1)
	{
		std::cin >> userInput;
		if (!std::cin || userInput < 1023 || userInput > 9876)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "try a valid number\nenter your guess:";
		}
		else if (areDigitsUnique(userInput) == false)
		{
			std::cout << "try a valid number\nenter your guess:";
		}
		else
		{
			return userInput;
		}
	}
}

std::vector<unsigned int> Number::convertIntToVec(const unsigned int& number)
{
	std::vector<unsigned int> vec;
	unsigned int n0 = number / 1000;
	unsigned int n1 = (number % 1000) / 100;
	unsigned int n2 = (number % 100) / 10;
	unsigned int n3 = number % 10;
	vec = { n0,n1,n2,n3 };
	return vec;
}