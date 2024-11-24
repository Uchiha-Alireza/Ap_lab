#include "Motorcycle.h"

Motorcycle::Motorcycle(const std::string& _factory, const std::string& _model, const std::string& _color, int _id, int _year, int _maxSpeed, double _salePrice, double _dailyRentPrice)
    : Vehicle(_factory, _model, _color, _id, _year, _maxSpeed),
    isSold(false), isRented(false), salePrice(_salePrice), PriceDay(_dailyRentPrice) {}
void Motorcycle::drive() {
    std::cout << "Driving at speeds between 0 and " << maxSpeed / 2 << " km/h (half max speed).\n";
}
void Motorcycle::ShowDetail() const { 
    std::cout << "Motorcycle - Model: " << model << ", Factory: " << factory << ", Color: " << color << ", Year: " << year << ", Max Speed: " << maxSpeed << ", Sale Price: " << salePrice << " dollars, Daily Rent Price: " << PriceDay << " dollars.\n";
}
bool Motorcycle::canBeSold() const {
    return !isSold && !isRented; 
}
bool Motorcycle::canBeRent() const {
    return !isRented; 
}
void Motorcycle::sell() {
    if (canBeSold()) {
        std::cout << "Selling the motorcycle for " << salePrice << " dollars.\n";
        isSold = true;
    }
    else {
        std::cout << "Motorcycle is not available for sale.\n";
    }
}
void Motorcycle::Rent(int days) {
    if (canBeRent()) {
        double totalRentPrice = days * PriceDay;
        std::cout << "Renting the motorcycle for " << totalRentPrice << " dollars for " << days << " days.\n";
        isRented = true;
    }
    else {
        std::cout << "Motorcycle is already rented.\n";
    }
}
