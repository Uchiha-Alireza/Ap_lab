#pragma once
#include <iostream>
class Vehicle {
protected:
	int id;
	std::string factory;
	std::string model;
	std::string color;
	int year;
	int maxSpeed;
public:
	Vehicle(std::string,std::string,std::string,int,int,int);
	int getid()const;
	virtual void drive() = 0;
	virtual void ShowDetail()const = 0;
	virtual ~Vehicle()=default;
	friend std::ostream& operator<<(std::ostream&, const Vehicle&);
};