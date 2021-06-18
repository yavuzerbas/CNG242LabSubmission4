/* Yavuz Erbas 2243426
I read and accept the submission rules and the extra rules specified in each question. This is my
own work that is done by myself only */
#pragma once
#include <iostream>
#include "Fighter.h"
using std::cout;

class Haohmaru : public Fighter
{
public:
	Haohmaru() : Fighter(120, 20) {}
	Haohmaru(int fighterHealth,int fighterAttack) : Fighter(fighterHealth,fighterAttack) {}
	void print() {
		cout << "Haohmaru's current stamina: " << this->getHealthbar() << "\n";
	}
	void printFighter() {
		cout << "Haohmaru's attack power:" << this->getAttackPower() << "\n";
		cout << "Haohmaru's max health(healthbar):" << this->getHealthbar() << "\n";
	}

};

