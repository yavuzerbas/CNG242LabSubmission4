/* Yavuz Erbas 2243426
I read and accept the submission rules and the extra rules specified in each question. This is my
own work that is done by myself only */
#pragma once
#include <iostream>
#include "Fighter.h"
using std::cout;

class Genjuro : public Fighter
{
public:
	Genjuro() : Fighter(100, 30) {}
	Genjuro(int fighterHealth, int fighterAttack) : Fighter(fighterHealth, fighterAttack) {}
	void print() {
		cout << "Genjuro's current stamina: " << this->getHealthbar() << "\n";
	}
	void printFighter() {
		cout << "Genjuro's attack power:" << this->getAttackPower() << "\n";
		cout << "Genjuro's max health(healthbar):" << this->getHealthbar() << "\n";
	}

};

