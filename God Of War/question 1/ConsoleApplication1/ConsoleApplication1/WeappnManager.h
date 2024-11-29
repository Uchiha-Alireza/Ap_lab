#include <iostream>
#include "Vector.h"
#include "Vector.cpp"
#include "Weapon.h"
#include "Blade.h"
#include "Bow.h"
#include "Mace.h"

class WeaponManager {
private:
	Alireza::vector<Weapon*>weapons;
public:
	void addWeapon(Weapon* weapon);
	std::string getWeaponType(int index);
	int getWeaponPower(int index);
	float getWeaponDurability(int index);
	int getWeaponId(int index);
	int getTotalPower();
	void displayWeapons();
	void sortWeaponsByPower();
};