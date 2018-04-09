/*******************************************************************************File: penguinClass.cpp
Name: Calista Wong 
Description: This contains the implementation class for the penguin class.
*****************************************************************************/

#include <iostream>
#include "penguinClass.hpp"

Penguin::Penguin()
	{
	  age = 1;
	  cost = 1000;
	  babies = 5;
	  foodCost = BASEFOOD;
	  payoff = 100;
	}

void Penguin::setAge(int i)
	{
	  age = i;
	}
