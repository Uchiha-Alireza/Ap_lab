#pragma once
#include "Weapon.h"
class Bow :public Weapon {
private:
	float FireRate;
public:
	Bow(int _power, float _durability, int _level, float _FireRate);
	int getId();
	int getPower();
	int getLevel();
};