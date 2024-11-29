#include "Mace.h"
Mace::Mace(int _power, float _durability, int _level, int _RazorCount):Weapon(_power,_durability,_level),RazorCount(_RazorCount) {}
int Mace::getLevel() {
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
int Mace::getId() {
	return id + 30000;
}
int Mace::getPower() {
	return power* RazorCount;
}