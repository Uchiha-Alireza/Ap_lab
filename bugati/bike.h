#pragma once
#include "Vehicle.h"
class Bike :public Vehicle {
private:
	int PriceDay;
	bool isSold;
	bool isRented;
public:
	Bike(const std::string&, const std::string&, const std::string&,int, int, int);
	void ShowDetail()const;
	void drive()override;
	void Rent(int days);
	bool canBeSold()const;
};