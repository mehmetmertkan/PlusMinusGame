#ifndef GAME_H
#define GAME_H
#include "Number.h"
#include "PlusMinus.h"
class Game
{
private:
	Number computerNumber;
	std::vector<unsigned int> possibleAnswers;

public:
	Game();
	Number getComputerNumber() const;
	void setComputerNumber(Number number);
	std::vector<unsigned int> getPossibleAnswers() const;
	void setPossibleAnswers(std::vector<unsigned int> val);
	void run();
	PlusMinus generatePlusAndMinusSigns(Number realNumber, Number userGuess) ;
	void deleteFromPossibleAnswers(Number computerGuess, PlusMinus userPlusMinus);
	void fillPossibleAnswers();
	void runComputerTurn();
	void runUserTurn();
	void getRunMode();
};

#endif