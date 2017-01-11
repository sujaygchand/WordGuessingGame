#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {
	InvalidStatus,
	OK,
	Not_Isogram,
	WrongLength,
	NotLowercase
};

class FWordGuessingGame {

public:	

	// Constructor
	FWordGuessingGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;


	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;	// TODO make a more rich return value.

	void Reset();		// TODO make a more rich return value.
	FBullCowCount SubmitValidGuess(FString);

// Ignore for now
private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bIsGameWon;
};