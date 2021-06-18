/* Yavuz Erbas 2243426
I read and accept the submission rules and the extra rules specified in each question. This is my
own work that is done by myself only */
#pragma once
class Fighter{
private:
	int healthbar;
	int attackPower;
	bool lost;
public:
	Fighter(int fighterHealthbar,int fighterAttackPower) {
		healthbar = fighterHealthbar;
		attackPower = fighterAttackPower;
		this->lost = false;
	}
	virtual void print(void) = 0;
	virtual void printFighter(void) = 0;

	int getHealthbar() const {
		return this->healthbar;
	}
	int getAttackPower() const {
		return this->attackPower;
	}
	void updateHealthBar(int damage) {
		healthbar -= damage;
		if (healthbar <= 0) {
			lost = true;
			healthbar = 0; //in case negative;
		}
	}
	void setLost(bool lostOrNot) {
		this->lost = lostOrNot;
	}
	bool isLost() const {
		return lost;
	}
};

