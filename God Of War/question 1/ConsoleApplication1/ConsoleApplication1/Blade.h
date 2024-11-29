#pragma once
#include "Weapon.h"
class Blade:public Weapon{
private:
	float WinRate;
	bool Magical;
	bool Double;
public:
	Blade(int _power, float _durability, int _level,float _WinRate,bool _Magical,bool _Double);
	int getId();
	int getPower();
	int getLevel();
};