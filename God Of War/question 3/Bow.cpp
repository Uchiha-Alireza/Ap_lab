#include "Bow.h"
Bow::Bow(int _power, float _durability, int _level, float _FireRate):Weapon(_power,_durability,_level),FireRate(_FireRate){}
int Bow::getId() {
	return id + 20000;
}
int Bow::getPower() {
	return power * FireRate;
}
int Bow::getLevel() {
	if (power > 0 && power <= 100) {
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
