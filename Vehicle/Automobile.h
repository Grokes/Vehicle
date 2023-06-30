#pragma once
#include "Vehicle.h"
#include <string>

class Automobile : public Vehicle
{
protected:
	short fuel_percent{};
	std::string engine;

public:
	Automobile(int price = 0, int mass = 0, std::string engine = "Standart") : Vehicle(price, mass), engine{engine} {}

public:
	virtual void use() override
	{
		if (fuel_percent)
			std::cout << "Врррурур" << std::endl;
		else
			std::cout << "Нет топлива\n";
	}
	virtual void get_param() override
	{
		Vehicle::get_param();
		std::cout << "Тип двигателя: " << engine << std::endl;
		std::cout << "Запас топлива " << fuel_percent << "%" << std::endl;
	}
	void repair() override final
	{
		Vehicle::repair();
		refuel();
		std::cout << "TC было заправлено\n";
	}
private:
	void refuel()
	{
		fuel_percent = 100;
	}
};

class Car : public Automobile
{
public:
	Car(int price = 0, int mass = 0, std::string engine = "Standart") : Automobile(price, mass, engine) {}

public:
	void use() override final
	{
		Automobile::use();
		fuel_percent -= 20;
		if (fuel_percent < 0)
			fuel_percent = 0;
	}
};

class Bus : public Automobile
{
private:
	int capacity;
public:
	Bus(int price = 0, int mass = 0, std::string engine = "Standart", int capacity = 10) : Automobile(price, mass, engine), capacity{capacity} {}

public:
	void get_param() override final
	{
		Automobile::get_param();
		std::cout << "Вместимость " << capacity << std::endl;
	}
	void use() override final
	{
		Automobile::use();
		fuel_percent -= 50;
		if (fuel_percent < 0)
			fuel_percent = 0;
	}
};

class Truck : public Automobile
{
private:
	int capacity;
public:
	Truck(int price = 0, int mass = 0, std::string engine = "Standart", int capacity = 100) : Automobile(price, mass, engine), capacity{ capacity } {}

public:
	void get_param() override final
	{
		Automobile::get_param();
		std::cout << "Грузоподъёмность " << capacity << std::endl;
	}
	void use() override final
	{
		Automobile::use();
		fuel_percent -= 70;
		if (fuel_percent < 0)
			fuel_percent = 0;
	}
};