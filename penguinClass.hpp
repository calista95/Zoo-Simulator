/*******************************************************************************File: penguinClass.hpp
Name: Calista Wong 
Description: This is the header file for the penguin class.
***************************************************************************/

#ifndef PENGUINCLASS_HPP
#define PENGUINCLASS_HPP

#include "animalClass.hpp"

class Penguin : public Animal
	{
	  public:
	  Penguin(); //default constructor to initialize values 
	  void setAge(int);
	};

#endif
