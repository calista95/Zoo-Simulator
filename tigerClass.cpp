/******************************************************************************************File: tigerClass.cpp
Name: Calista Wong 
Description: This contains the implementation for the tiger class.
****************************************************************************************/

#include <iostream>
#include "tigerClass.hpp"

Tiger::Tiger() //default constructor to initialize values 
	{
	 age = 1;
	 cost = 10000;
	 babies = 1;
	 foodCost = 5*BASEFOOD;
	 payoff = 2000;
	}

void Tiger::setAge(int i)
	{
	 age = i;
	}
