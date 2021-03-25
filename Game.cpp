#include "Game.h"

Game::Game()
{
	fillPossibleAnswers();
	computerNumber.generateNumber();
	getRunMode();
}

Number Game::getComputerNumber() const
{ 
	return computerNumber; 
}

void Game::setComputerNumber(Number number)
{ 
	computerNumber = number;
}

std::vector<unsigned int> Game::getPossibleAnswers() const
{ 
	return possibleAnswers; 
}

void Game::setPossibleAnswers(std::vector<unsigned int> val)
{ 
	possibleAnswers = val; 
}

void Game::run()
{
	while (true)
	{
		runComputerTurn();
		runUserTurn();
	}
}

//compares two numbers and generates plus and minus signs
PlusMinus Game::generatePlusAndMinusSigns(Number realNumber, Number userGuess) 
{
	std::vector<unsigned int> realNumberVec = realNumber.convertIntToVec(realNumber.getNumberValue());
	std::vector<unsigned int> userGuessVec = userGuess.convertIntToVec(userGuess.getNumberValue());
	PlusMinus plusMinus;
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (realNumberVec[i] == userGuessVec[j])
			{
				if (i == j)
				{
					plusMinus.setPlusSign(plusMinus.getPlusSign() + 1);
				}
				else
				{
					plusMinus.setMinusSign(plusMinus.getMinusSign() + 1);
				}
			}
		}
	}
	return plusMinus;
}

//get new guesses from left reduced possible answers
void Game::deleteFromPossibleAnswers(Number computerGuess, PlusMinus userPlusMinus)
{
	for (size_t index = 0; index < getPossibleAnswers().size();)
	{
		Number possibleAnswer(getPossibleAnswers()[index]);
		PlusMinus tempPlusMinus = generatePlusAndMinusSigns(computerGuess, possibleAnswer);
		if (tempPlusMinus.getPlusSign() != userPlusMinus.getPlusSign() || tempPlusMinus.getMinusSign() != userPlusMinus.getMinusSign())
		{
			possibleAnswers.erase(possibleAnswers.begin() + index);
		}
		else
		{
			index++;
		}
	}
	if (possibleAnswers.size() == 0)
	{
		std::cout << "you may have entered a wrong response along the game.\nYou may want to double check your answers\n\n\n";
		exit(-1);
	}
}

void Game::fillPossibleAnswers()
{
	for (size_t index = 1023; index <= 9876; index++)
	{
		Number number(index);
		if (number.areDigitsUnique(index))
		{
			possibleAnswers.push_back(index);
		}
	}
}

void Game::runComputerTurn()
{
	Number computerGuess;
	PlusMinus userPlusMinus;
	computerGuess.setNumberValue(possibleAnswers[0]);
	std::cout << "computer guess: ";
	computerGuess.print();
	userPlusMinus.getFromUser();
	if (userPlusMinus.isPlusSignFour())
	{
		std::cout << "game finished computer won\n\n" << std::endl;
		exit(-1);
	}
	deleteFromPossibleAnswers(computerGuess, userPlusMinus);
	std::cout << "-------------------\n";
}

void Game::runUserTurn()
{
	Number userGuess;
	PlusMinus computerPlusMinus;
	std::cout << "enter your guess: ";
	userGuess.getFromUserInput();
	computerPlusMinus = generatePlusAndMinusSigns(getComputerNumber(), userGuess);
	computerPlusMinus.print();
	if (computerPlusMinus.isPlusSignFour())
	{
		std::cout << "game finished user won\n\n" << std::endl;
		exit(-1);
	}
	std::cout << "-------------------\n";

}

//get run mode from user at the beggining of the game
void Game::getRunMode()
{
	int runMode;
	std::cout << "enter run mode:" << std::endl;
	std::cout << "1: Release" << std::endl;
	std::cout << "2: Debug" << std::endl;
	std::cin >> runMode;
	if (runMode == 2)
	{
		std::cout << "computer number = ";
		computerNumber.print();
	}
}