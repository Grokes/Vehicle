#pragma once
#include <iostream>
#include <Windows.h>
class Vehicle
{
protected:
	int speed{};
	int price{};
	int mass{};

public:
	Vehicle(int price = 0, int mass = 0) : price{ price }, mass{ mass } {}

public:
	virtual void use() = 0;
	virtual void repair()
	{
		std::cout << "�������� ���� ���������������, ��� ���� �������\n";
		price *= 1.1;
	}
	virtual void get_param()
	{
		std::cout << "��������� ����������\n" <<
			"��������� " << price << std::endl <<
			"��� " << mass << std::endl;
	}
};

#include "Automobile.h"
#include "Bicycle.h"