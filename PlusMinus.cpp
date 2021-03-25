#include "PlusMinus.h"

PlusMinus::PlusMinus()
{
	plusSign = 0;
	minusSign = 0;
}

PlusMinus::PlusMinus(unsigned int& plusSign, unsigned int& minusSign)
{
	setPlusSign(plusSign);
	setMinusSign(minusSign);
}

//check if game is finished
bool PlusMinus::isPlusSignFour() const
{
	if (plusSign == 4)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void PlusMinus::print() const
{
	std::cout << "computer answer: ";
	if (plusSign != 0)
	{
		std::cout << "+" << plusSign << " ";
	}
	else if (plusSign == 0)
	{
		std::cout << "0 ";
	}
	if (minusSign != 0)
	{
		std::cout << "-" << minusSign;
	}
	else if (minusSign == 0)
	{
		std::cout << "0 ";
	}
	std::cout << std::endl;
}

void PlusMinus::getFromUser()
{
	std::pair<unsigned int, int> pa = get();
	plusSign = pa.first;
	minusSign = -1 * pa.second;
}

//checks if response from user is valid
std::pair<int, int> PlusMinus::get()
{
	std::pair<int, int> pa;
	while (true)
	{
		std::cout << "enter your response: ";
		std::cin >> pa.first >> pa.second;
		if (!std::cin || 
			pa.first < 0 || pa.first > 4 ||
			pa.second > 0 || pa.second < -4 ||
			(pa.first == 3 && pa.second == -1) ||
			pa.first + pa.second > 4 ||
			pa.first + pa.second < -4 ||
			abs(pa.first) + abs(pa.second) > 4)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "try valid numbers" << std::endl;
		}
		else
		{
			return pa;
		}
	}
}