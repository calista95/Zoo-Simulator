/*********************************************************************************File: tigerClass.hpp
Name: Calista Wong 
Description: This contains the header file for the tiger class 
*****************************************************************************/

#ifndef TIGERCLASS_HPP
#define TIGERCLASS_HPP

#include "animalClass.hpp"

class Tiger : public Animal
   {
	public:
	Tiger(); //default constructor to initialize values
	void setAge(int); 
   };

#endif

