#pragma once
#include "Vehicle.h"
class Car :public Vehicle {
private:
	double salePrice;
	bool isSold;
public:
	Car(const std::string&, const std::string&, const std::string&, int, int, int,double);
	void drive()override;
	void ShowDetail() const;
	bool canBeSold()const;
	void sell();
};