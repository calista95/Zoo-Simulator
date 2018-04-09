#This is the Makefile for Project 2
#Author: Calista Wong 

output: project2main.o zoo.o animalClass.o tigerClass.o penguinClass.o turtleClass.o 
	g++ project2main.o zoo.o animalClass.o tigerClass.o penguinClass.o turtleClass.o -o output
project2main.o: project2main.cpp
	g++ -c project2main.cpp
zoo.o: zoo.cpp zoo.hpp
	g++ -c zoo.cpp
animalClass.o: animalClass.cpp animalClass.hpp
	g++ -c animalClass.cpp
tigerClass.o: tigerClass.cpp tigerClass.hpp
	g++ -c tigerClass.cpp
penguinClass.o: penguinClass.cpp penguinClass.hpp
	g++ -c penguinClass.cpp
turtleClass.o: turtleClass.cpp turtleClass.hpp
	g++ -c turtleClass.cpp
clean:
	rm *.o output
	
