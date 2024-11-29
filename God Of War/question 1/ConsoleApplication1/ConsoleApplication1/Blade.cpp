#include "Blade.h"
Blade::Blade(int _power, float _durability, int _level, float _WinRate, bool _Magical, bool _Double):Weapon(_power,_durability,_level),WinRate(_WinRate),Magical(_Magical),Double(_Double){}
int Blade::getId() {
	return id + 10000;
}
int Blade::getPower() {
	if (Magical == true && Double == false) {
		return power * WinRate * 3;
	}
	if (Magical == false && Double == true) {
		return power * WinRate * 2;
	}
}
int Blade::getLevel() {
	if (power>0&&power<=100) {
		return 1;
	}
	else if (power > 100 && power <= 250) {
		return 2;
	}
	else if (power > 250 && power < 400) {
		return 3;
	}
	else {
		return 4;
	}
}