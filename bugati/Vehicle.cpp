#include "Vehicle.h"

Vehicle::Vehicle(std::string _factory, std::string _model, std::string _color,int _id,int _year,int _maxSpeed):factory(_factory),model(_model),color(_color),id(_id), year(_year), maxSpeed(_maxSpeed) {}
std::ostream& operator<<(std::ostream& output,const Vehicle& other) {
	output << "Factory: " << other.factory <<"\nModel: " << other.model <<"\nColor: " << other.color <<"\nYear: " << other.year <<"\nMaxSpeed : " << other.maxSpeed << "\n";
	return output;
}
int Vehicle::getid()const {
	return this->id;
}
