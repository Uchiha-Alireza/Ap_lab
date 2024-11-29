#pragma once
#include "Weapon.h"
class Mace:public Weapon{
private:
	int RazorCount;
public:
	Mace(int _power, float _durability, int _level,int _RazorCount);
	int getId();
	int getPower();
	int getLevel();
};