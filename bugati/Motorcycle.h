#pragma once
#include "Vehicle.h"

class Motorcycle :public Vehicle {
private:
	double salePrice;
	bool isSold;
	bool isRented;
	double PriceDay;
public:
	Motorcycle(const std::string&, const std::string&, const std::string&,int, int, int,double,double);
	void drive()override;
	void ShowDetail()const;
	bool canBeSold()const;
	bool canBeRent()const;
	void sell();
	void Rent(int);

};