/*********************************************************************************File: animalClass.hpp
Name: Calista Wong 
Description: This contains the header file for the animal class
*************************************************************************/

#ifndef ANIMALCLASS_HPP
#define ANIMALCLASS_HPP


class Animal
   {
    protected:
    static const int BASEFOOD=10; //base food cost set at a constant of $10
    int age,
        cost,
        babies,
        foodCost;
    double payoff;
    public:
    Animal();
    Animal(int);
    void addAge();
    //various getter functions
    int getAge();
    int getCost();
    int getBabies();
    double getFoodCost();
    int getPayoff();
   };
#endif
