/*********************************************************************************File: animalClass.cpp
Name: Calista Wong 
Description: This contains the implementation for the animal class. 
********************************************************************************/

#include "animalClass.hpp"


Animal::Animal()
	{
         age=1;
	}

Animal::Animal(int a)
 	{
	 age = a;
	}       

void Animal::addAge()
        {
	 age++; 
	}

//getter functions//

int Animal::getAge()
	{
	 return age;
	}

int Animal::getCost()
	{
	 return cost;
	}

int Animal::getBabies()
	{
	 return babies;
	}

double Animal::getFoodCost()
	{
	 return foodCost;
	}

int Animal::getPayoff()
	{
	 return payoff;
	}
