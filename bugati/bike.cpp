#include "bike.h"
Bike::Bike(const std::string& _factory, const std::string& _model, const std::string& _color,int _id,int _year, int _maxSpeed):Vehicle(_factory,_model,_color,_id,_year,_maxSpeed) {}
void Bike::drive() {
	for (int i = 0; i < maxSpeed; i++) {
		std::cout << "pedaling\n";
	}
}
bool Bike::canBeSold()const {
    if (isRented == true) {
        return false;
    }
    else {
        return true;
    }
}
void Bike::Rent(int days) {
    if (canBeSold() != false) {
        double rentPrice = days * PriceDay;
        std::cout << "Renting the Bike for " << rentPrice << "dollars for " << days << "days." << std::endl;
        isRented = true;
    }
    else {
        std::cout << "Bike is already rented.\n";
    }
}
void Bike::ShowDetail()const {
    std::cout << "Bike - Model: " << model << ", Factory: " << factory << ", Color: " << color << ", Year: " << year << ", Max Speed: " << maxSpeed << " Daily Rent Price: " << PriceDay << " dollars.\n";

}