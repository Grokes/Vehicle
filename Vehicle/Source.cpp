#include <iostream>
#include <Windows.h>
#include "Vehicle.h"
#include "People.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Bus bus(100000,3000, "Ultra engine");
	Sport_bicycle bicycle(1000, 30);

	People test;
	test.add("Bus", bus);
	test.add("Bicycle", bicycle);
	test.show();

	auto iterator = test.find("Bicycle");
	use(iterator);
	std::cout << std::endl;
	get_param(iterator);
	std::cout << std::endl;
	repair(iterator);
	std::cout << std::endl;
	std::cout << std::endl;

	iterator = test.find("Bus");
	repair(iterator);
	std::cout << std::endl;
	use(iterator);
	std::cout << std::endl;
	get_param(iterator);
	
	


	return 0;
}