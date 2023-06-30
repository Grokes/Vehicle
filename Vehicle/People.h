#pragma once
#include<iostream>
#include "Vehicle.h"
#include <map>
#include <string>

class People
{
private:
	std::map<std::string, Vehicle*> garage;

public:
	People() = default;

public:
	void add(std::string name, Vehicle& vehicle)
	{
		garage.emplace(name, &vehicle);
	}
	void show()
	{
		for (auto el : garage)
			std::cout << el.first << std::endl;
	}
	auto find(std::string param)
	{
		return garage.find(param);
	}
};

void use(std::map<std::string, Vehicle*>::iterator& iter)
{
	iter->second->use();
}
void get_param(std::map<std::string, Vehicle*>::iterator& iter)
{
	iter->second->get_param();
}
void repair(std::map<std::string, Vehicle*>::iterator& iter)
{
	iter->second->repair();
}


