/**********************************************************************************File: turtleClass.hpp
Name: Calista Wong 
Description: This is the header file for the turtle class.
**************************************************************************/

#ifndef TURTLECLASS_HPP
#define TURTLECLASS_HPP

#include "animalClass.hpp"

class Turtle : public Animal
	{
	  public:
	  Turtle(); //default constructor
	  void setAge(int);
	};

#endif

