#include "FWordGuessingGame.h"


//using FString = std::string;
//using int32 = int;

// Constructor
FWordGuessingGame::FWordGuessingGame() {
	Reset();
}

void FWordGuessingGame::Reset() {

	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "snow";

	MyMaxTries = MAX_TRIES;

	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bIsGameWon = false;
}

int32 FWordGuessingGame::GetMaxTries() const { return MyMaxTries; }
int32 FWordGuessingGame::GetCurrentTry()const { return MyCurrentTry; }
int32 FWordGuessingGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FWordGuessingGame::IsGameWon() const {	return bIsGameWon; }

EGuessStatus FWordGuessingGame::CheckGuessValidity(FString Guess) const {

	// Guess isn't an isogram
	if (false) {
		return EGuessStatus::Not_Isogram;
	}

	// if the guess isn't all lowercase
	else if (false) {
		return EGuessStatus::NotLowercase;
	}

	// if the guess is wrong word length
	else if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::WrongLength;
	}
	// otherwise return OK

	else {
		return EGuessStatus::OK;
	}
}

// Recieves a valid guess, increments turn, and returns count
FBullCowCount FWordGuessingGame::SubmitValidGuess(FString Guess) {

	// Increment the turn number
	MyCurrentTry++;

	// setup a return varible
	FBullCowCount BullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length();
	int32 WordLength = Guess.length();

	// loop through all letters in the guess
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {

		// compare letters against the hidden word
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
			// if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				// Increment bulls if they're in the same place
				if (MHWChar == GChar) {
					BullCowCount.Bulls++;
				} else {
					// Increment cows if not 
					BullCowCount.Cows++;
				}
			}
		}

	}

	if (BullCowCount.Bulls == WordLength) {
		bIsGameWon = true;
	}
	else {
		bIsGameWon = false;
	}

	return BullCowCount;
}
