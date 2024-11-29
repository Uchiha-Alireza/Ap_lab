#pragma once
class Weapon {
protected:
	int id;
	int power;
	float durability;
	int level;
	static int nextId;
public:
	Weapon(int _power,float _durability,int _level);
	virtual int getId();
	virtual int getPower();
	float getDurability();
	virtual int getLevel();
	virtual ~Weapon() = default;
};