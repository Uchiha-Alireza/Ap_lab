#include "Car.h"
Car::Car(const std::string& _factory, const std::string& _model, const std::string& _color, int _id, int _year, int _maxSpeed, double _salePrice)
    : Vehicle(_factory, _model, _color, _id, _year, _maxSpeed), salePrice(_salePrice), isSold(false) {}
void Car::drive() {
    std::cout << "Driving at speeds between 0 and " << maxSpeed << " km/h.\n";
}
void Car::ShowDetail() const {
    std::cout << "Car - Model: " << model
        << ", Factory: " << factory
        << ", Color: " << color
        << ", Year: " << year
        << ", Max Speed: " << maxSpeed
        << ", Price: " << salePrice << " dollars.\n";
}
bool Car::canBeSold() const {
    return !isSold; 
}
void Car::sell() {
    if (isSold) {
        std::cout << "Car has already been sold.\n";
    }
    else {
        std::cout << "Selling the car for " << salePrice << " dollars.\n";
        isSold = true;
    }
}
