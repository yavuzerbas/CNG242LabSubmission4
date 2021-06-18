/* Yavuz Erbas 2243426
I read and accept the submission rules and the extra rules specified in each question. This is my
own work that is done by myself only */
#include <iostream>
#include "ctime"
#include "Fighter.h"
#include "Genjuro.h"
#include "Haohmaru.h"

using std::cout;
using std::cin;

char firstPlayer() {
	char* input = new char[10];
	bool key = false;
	while (true) {
		cout << "Who goes first?\n Genjuro(1), Haohmaru(2):";
		cin >> input;
		if(input[0] == '1' || input[0] == '2'){
			cout << "\n";
			return input[0];
		}
		cout << "\nInvalid input!\n";
	};
}
char randomNext() {//creates random char in ('1','2')
	int randomNumber = rand();
	if ((randomNumber % 2) == 1) {
		return '1';
	}
	else {
		return '2';
	}
}
char fight(Genjuro* genjuro, Haohmaru* haohmaru) {
	char whoIsAttacking = firstPlayer();
	while ((!genjuro->isLost()) && (!haohmaru->isLost())) {
		if (whoIsAttacking == '1') {//genjuro attacks
			cout << "Genjuro's attack!\n";
			haohmaru->updateHealthBar(genjuro->getAttackPower());
			haohmaru->print();
			cout << "-----------\n";
			whoIsAttacking = randomNext();
		}
		else {
			cout << "Haohmaru's attack!\n";
			genjuro->updateHealthBar(haohmaru->getAttackPower());
			genjuro->print();
			cout << "-----------\n";
			whoIsAttacking = randomNext();
		}
	}
	//fight ended

	cout << "\n";

	if (haohmaru->isLost()) {
		cout << "Haohmaru lost!\n";
		cout << "Genjuro won!\n\n";
		return 'G';
	}
	else {
		cout << "Genjuro lost!\n";
		cout << "Haohmaru won!\n\n";
		return 'H';
	}
	
}

void newGameConfigurations(Genjuro* genjuro, Haohmaru* haohmaru) {

	//killing the remaining one
	do {//loop is for in case had a health bigger than 100000!
		genjuro->updateHealthBar(100000);
		haohmaru->updateHealthBar(100000);
	} while ((!genjuro->isLost()) || (!haohmaru->isLost()));
	//remaing one is dead (I could have just created a setHealthBar method inside Fighter class but I didn't want to alter the Fighter class much!)
	genjuro->setLost(false);
	haohmaru->setLost(false);

	genjuro->updateHealthBar(-100);
	haohmaru->updateHealthBar(-120);
}

int main()
{
	srand(time(0));
	char* input = new char[10];
	char key;
	Genjuro* genjuro = new Genjuro();
	Haohmaru* haohmaru = new Haohmaru();
	int genjuroWinCounter = 0, haohmaruWinCounter = 0;
	do {
		genjuro->printFighter();
		haohmaru->printFighter();
		if (fight(genjuro, haohmaru) == 'G') {
			genjuroWinCounter++;
		}
		else {
			haohmaruWinCounter++;
		}

		cout << "Genjuro: " << genjuroWinCounter << "\t" << "Haohmaru: " << haohmaruWinCounter << "\n\n";

		cout << "Would you like to play again(y/n):";
		cin >> input;
		key = input[0];
		if (key == 'y') {
			newGameConfigurations(genjuro, haohmaru);
		}
		cout << "\n";
	} while (key == 'y');
	cout << "Goodbye!\n";
}