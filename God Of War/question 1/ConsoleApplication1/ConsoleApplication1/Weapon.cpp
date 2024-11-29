#include "Weapon.h"
int Weapon::nextId = 1;
Weapon::Weapon(int _power,float _durability,int _level):id(nextId),power(_power),durability(_durability),level(_level){
	nextId++;
}
float Weapon::getDurability() {
	return power / 10;
}
int Weapon::getId() {
	return id;
}
int Weapon::getPower() {
	return power;
}
int Weapon::getLevel() {
	return level;
}
