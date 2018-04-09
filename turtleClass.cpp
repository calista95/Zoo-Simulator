/*******************************************************************************File: turtleClass.cpp
Name: Calista Wong 
Description: This is the implementation file for the turtle class.
**************************************************************************/

#include <iostream>
#include "turtleClass.hpp"

Turtle::Turtle()
	{
	  age = 1;
	  cost = 100;
	  babies = 10;	
	  foodCost = 5;
	  payoff = 5;
	}

void Turtle::setAge(int i)
	{
	  age = i;
	}
