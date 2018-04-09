#ifndef ZOO_HPP
#define ZOO_HPP
#include "tigerClass.hpp"
#include "penguinClass.hpp"
#include "turtleClass.hpp"

class Zoo
   {
    private:
    int money,
	profit,
        numTigers,
        bonus,
        animalBorn,
        event,
	arraySizeTiger,
	arraySizePenguin,
	arraySizeTurtle, 
	spotsTiger,
	spotsPenguin,
	spotsTurtle, 
        numPenguins,
        numTurtles;
    Tiger**tigers;
    Penguin**penguins;
    Turtle**turtles;

    public:
    Zoo();//default constructor
    void buyAnimals();
    void incrementDay();
    //increment day functions	
    void incrementAge();
    void feedAnimals();
    void randomEvent();
    void getProfit(); 
    void buyAnother();
    bool playAgain();
    //random event functions
    void sick();
    void attendanceBoom();
    void baby();

   };

#endif
