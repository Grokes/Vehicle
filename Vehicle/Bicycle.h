#pragma once
#include "Vehicle.h"

class Bicycle: public Vehicle
{
protected:
	size_t count_wheels;

public:
	Bicycle(int price = 0, int mass = 0, size_t wheels = 2) : Vehicle(price, mass), count_wheels{wheels} {}
	virtual void get_param() override
	{
		Vehicle::get_param();
		std::cout << "Кол-во колёс " << count_wheels << std::endl;
	}
	virtual void use() override
	{
		std::cout << "шшшшткткшшшктшшкт" << std::endl;
	}
};

class Sport_bicycle : public Bicycle
{
private:
	short gear_shift{};

public:
	Sport_bicycle(int price = 0, int mass = 0, size_t wheels = 2): Bicycle(price, mass, wheels){}

public:
	void use() override final
	{
		for (int i{}; i < 6; ++i)
		{
			Bicycle::use();
			change_gear();
			std::cout << "Текущая передача " << gear_shift << std::endl;
			std::cout << "Текущая скорость " << speed << "\n\n";
		}
		speed = 0;
		gear_shift = 0;
		std::cout << "Средство возвращено в гараж\n";
	}
	void get_param() override final
	{
		Bicycle::get_param();
		std::cout << "Есть возможность переключать скорости\n";
	}

private:
	void change_gear() 
	{ 
		++gear_shift;
		speed += 5; 
	}
};

class Classic_bicycle : public Bicycle
{
public:
	Classic_bicycle(int price = 0, int mass = 0, size_t wheels = 2) : Bicycle(price, mass, wheels) {}

public:
	void use() override final
	{
		Bicycle::use();
		speed = 15;
		Sleep(1000);
		speed = 0;
		std::cout << "Средство возвращено в гараж\n";
	}
	void get_param() override
	{
		Bicycle::get_param();
	}
};

class Children_bicycle : public Bicycle
{
private:
	bool isUprade{};
public:
	Children_bicycle(int price = 0, int mass = 0, size_t wheels = 2) : Bicycle(price, mass, wheels) {}

public:
	void use() override final
	{
		Bicycle::use();
		std::cout << "Дзынь-дзынь\n";
		speed = 8;
		Sleep(1000);
		speed = 0;
		std::cout << "Средство возвращено в гараж\n";
	}
	void get_param() override
	{
		Bicycle::get_param();
		if (isUprade)
			std::cout << "Установлены доп. колёса\n";
	}
	void repair() override final
	{
		Vehicle::repair();
		if (!isUprade)
		{
			std::cout << "Были установлены доп. колёса\n";
			count_wheels += 2;
			isUprade = true;
		}
	}
};