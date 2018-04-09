/******************************************************************************************************File:project2main.cpp
Name: Calista Wong 
Description: This contains the main for project 2. It creates a zoo object, then sends it to the zoo function to start the game. 
***********************************************************************************/
#include <iostream>
#include "zoo.hpp"
#include "animalClass.hpp"
using namespace std;

int main()
	{
	 	Zoo zoo;
		zoo.buyAnimals();
		zoo.incrementDay();	
		return 0;
	}
