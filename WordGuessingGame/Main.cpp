/* This is the console executable

*/


#include <string>
#include "FWordGuessingGame.h"
#include<iostream>

using FText = std::string;
//using int32 = int;

void PrintIntro();
FText GetValidGuess();
void ReturnGuess(FText Guess);
void PlayGame(int32 GuessCounter);
bool bAskToPlayAgain();
void PrintBullsAndCows(int32 Bulls, int32 Cows, bool bNewLine);

FWordGuessingGame WGGame;	// Initialises game

int main() {

	int32 GuessCounter = 5;
	bool bPlayAgain = false;

	do {
		PrintIntro();
		PlayGame(GuessCounter);
		//TODO make a game summary 
		bPlayAgain = bAskToPlayAgain();
	}

	while (bPlayAgain);

	return 0;	// Exit Application
}

void PlayGame(int32 GuessCounter) {

	WGGame.Reset();

	int32 MaxTries = WGGame.GetMaxTries();

	// Loop asking for guesses while game is not won 
	// and there are still turns
	while (!WGGame.IsGameWon() && WGGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetValidGuess();

		// submit valid guess to the game
		FBullCowCount BullCowCount = WGGame.SubmitValidGuess(Guess);
		// print number of bulls and cows
		PrintBullsAndCows(BullCowCount.Bulls, BullCowCount.Cows, true);

		// TODO Valid guess loop

	}

	//TODO make a game summary 
}


// Introduce the game
void PrintIntro() {

	std::cout << "\nWelcome to Isogram Rangers, a fun word guessings game" << std::endl;
	std::cout << "Can you guess the " << WGGame.GetHiddenWordLength();
	std::cout << " letter isogram, I'm Thinking of? \n" << std::endl;
}

// Loops until user gives valid guess
FText GetValidGuess() {

	FText Guess = "";
	EGuessStatus Status = EGuessStatus::InvalidStatus;

	do {
		int32 CurrentGuess = WGGame.GetCurrentTry();
		std::cout << "Try " << CurrentGuess;
		std::cout << ". Enter your Guess: ";
		std::getline(std::cin, Guess);

		Status = WGGame.CheckGuessValidity(Guess);

		// Switch statement That determines the action for input type
		switch (Status) {
		case EGuessStatus::WrongLength:
			std::cout << "Please enter a " << WGGame.GetHiddenWordLength() << " letter word. \n";
			break;

		case EGuessStatus::NotLowercase:
			std::cout << "Please ensure all leters are lower case." << std::endl;
			break;

		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram, a word with no repeating letters." << std::endl;
			break;

		case EGuessStatus::OK:
			break;

		default:
			// Assume guess is valid
			break;
		}
	}
	while (Status != EGuessStatus::OK);
	return Guess;
}

// Prints the guess to screen
void ReturnGuess(FText Guess) {
	std::cout << "Your Guess: ";
	std::cout << Guess << std::endl;
}

void PrintBullsAndCows(int32 Bulls, int32 Cows, bool bNewLine) {
	std::cout << "Bulls = " << Bulls;
	std::cout << ". Cows = " << Cows;

	if (bNewLine) {
		std::cout << std::endl;
	}
}

bool bAskToPlayAgain() {
	std::cout << "Do you want to play again? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);

	std::cout << std::endl;

	if (Response[0] == 'y' || Response[0] == 'Y') {
		return true;
	}
	else {
		return false;
	}
}




