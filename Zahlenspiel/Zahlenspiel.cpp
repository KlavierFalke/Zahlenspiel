#include <iostream>
#include <stdio.h>
#include <time.h> 
#include <cstdlib>
#include <Windows.h>

using namespace std;

void RunMenu();
char Menu();
void RunGame();
int GetUserGuess();
bool ValidateUserGuess(int guess, int rightResult);

int maxNumber;

int main() {

	srand(time(NULL));

	RunMenu();

	return(0);
}

void RunMenu() {

	while (true) {

		char input = Menu();
		if (input == 'P' || input == 'p')
			RunGame();
		else if (input == 'Q' || input == 'q')
			break;
		else
			cout << "\nError bei '" << input << "' bitte versuche es mit P oder Q\n";
	}
}

char Menu() {

	char input = ' ';
	cout << "MENU\n\n(P)lay\n(Q)uit\n\n";
	cout << "Input: ";
	cin >> input;

	system("cls");
	return input;
}

void RunGame() {

	cout << endl << "Gebe deine maximale Zahl an: ";
	cin >> maxNumber;


	int randomNumber = rand() % maxNumber + 1;
	int guess;
	int tries = 0;
	cout << "\nDie gesuchte Zahl ist zwischen 1 und " << maxNumber << " (eingeschlossen 1 und " << maxNumber << ").\n\n";
	do {

		guess = GetUserGuess();
		tries++;
	} while (!ValidateUserGuess(guess, randomNumber));
	cout << "Du hast " << tries << " Versuche gebraucht.\nIn dem Zahlenraum von 1 bis " << maxNumber << "." << endl << "\n";
}

int GetUserGuess() {

	int guess;
	cout << "Deine Zahl: ";
	cin >> guess;

	return guess;
}

bool ValidateUserGuess(int guess, int rightResult) {

	if (guess == rightResult) {
		system("cls");
		cout << "\nDein Eingabe von " << guess << " ist richtig.\n";
		return true;
	}

	else if (guess < rightResult) {
		system("cls");
		cout << "\nDie gesuchte Zahl ist groesser als " << guess << ".\n";
		return false;
	}

	else if (guess > rightResult) {
		system("cls");
		cout << "\nDie gesuchte Zahl ist kleiner als " << guess << ".\n";
		return false;
	}

	else {
		system("cls");
		cout << "\nError Input (Bei der Zahl: " << guess << ")\n";
		return false;
	}
}
