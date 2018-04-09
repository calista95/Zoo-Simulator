#include <iostream>
#include "zoo.hpp"
#include <cstdlib>
using namespace std;

Zoo::Zoo()
	{
	 money=100000; //start off with $100,000
	 bonus=0; 
	 profit=0;
	 arraySizeTiger=10;
	 arraySizePenguin=10;
	 arraySizeTurtle=10; 
	}

void Zoo::buyAnimals()
	{
         cout << "You are now starting a new game of Zoo Tycoon. " << endl;
 
         //ask user how many aninals of each to purchase
	 cout << "Do you want to purchase 1 or 2 tigers?" << endl; 
         cin >> numTigers;
         while (!cin || numTigers<1 || numTigers >2)
	   {
            cout << "Bad value, enter another." << endl;
	    cin.clear();
            cin.ignore();
            cin >> numTigers;  
	   }
         cout << "Do you want to purchase 1 or 2 penguins?" << endl; 
         cin >> numPenguins;
         while (!cin || numPenguins<1 || numPenguins >2 )
	   {
            cout << "Bad value, enter another." << endl;
	    cin.clear();
            cin.ignore();
            cin >> numPenguins;  
	   }
         cout << "Do you want to purchase 1 or 2 turtles?" << endl; 
         cin >> numTurtles;
         while (!cin || numTurtles <1 || numTurtles>2)
	   {
            cout << "Bad value, enter another." << endl;
	    cin.clear();
            cin.ignore();
            cin >> numTurtles;  
	   }

	 //deduct from user's account
	 money = money-(numTigers*10000)-(numPenguins*1000)-(numTurtles*100);
	 cout << "You have $" << money << " remaining." << endl;
	 cout << endl;

	 //create animal objects and populate the respective arrays 
	 tigers = new Tiger*[arraySizeTiger];
	 spotsTiger = arraySizeTiger;
	 for (int i=0; i<numTigers; i++) //create x number of tigers 
	  {
	    tigers[i] = new Tiger;
	    spotsTiger--;
	  }

	 penguins = new Penguin*[arraySizePenguin];
	 spotsPenguin = arraySizePenguin;
	 for (int i=0; i<numPenguins; i++) //create x number of penguins
	  {
 	    penguins[i] = new Penguin;
	    spotsPenguin--;
	    
	  }
   
	 turtles = new Turtle*[arraySizeTurtle];
	 spotsTurtle = arraySizeTurtle;
         for (int i=0; i<numTurtles; i++) //create x number of turtles 
	  {
 	    turtles[i] = new Turtle;
	    spotsTurtle--;	
	  } 

	cout << "There are " << spotsTiger << " spots remaining for tigers." << endl;
	cout << "There are " << spotsPenguin << " spots remaining for penguins." << endl;
	cout << "There are " << spotsTurtle << " spots remaining for turtles." << endl;
	cout << endl;

	}

void Zoo::incrementDay()
	{
  	  bool playInStatus = true;
	  
	  int day=1;
	  while (playInStatus == true)
	   {	
	     cout << "Day " << day << ": " << endl;
	     cout << endl;	
	     //increment each animal's age by 1 day
	     this->incrementAge();

	     //feed animals 
 	     this->feedAnimals();

	     //random event of the day
	     this->randomEvent();

             //calculate the profit for the day
             this->getProfit();

	     //ask user if they want to buy another animal 
	     this->buyAnother();

	     //display current population of the zoo
	     cout << "Your zoo currently has:" << endl;
	     cout << numTigers << " tigers" << endl;
	     cout << numPenguins << " penguins" << endl;
	     cout << numTurtles << " turtles" << endl;	 
	     cout << endl;	    
	
	     //determine the status of the next round	
	     playInStatus = this->playAgain();
	     day++;
   	   }
	
	   //deallocate memory before exiting program
	   //delete memory of tiger 
	   for (int i=0; i<arraySizeTiger; i++)
		{
		  delete tigers[i];
		  tigers[i]=0;
		}
	   //delete memory of penguin
	   for (int i=0; i<arraySizePenguin; i++)
		{
		  delete penguins[i];
		  penguins[i]=0;	
		}
	   //delete memory of turtle
	   for (int i=0; i<arraySizeTurtle; i++)
		{
		  delete turtles[i];
		  turtles[i]=0;
		}

           cout << "You have exited the game." << endl;
	   cout << endl;	
	}   


/******************START OF INCREMENT DAY FUNCTIONS*************************/

void Zoo::incrementAge()
	{
	 //increment each tiger's age 
	 for (int i=0; i<numTigers; i++)
		{
		  tigers[i]->addAge();
		}

	 //increment each penguin's age
	 for (int i=0; i<numPenguins; i++)
		{
		  penguins[i]->addAge();
		}
	 //increment each turtle's age 
	  for (int i=0; i<numTurtles; i++)
		{
		  turtles[i]->addAge();
		}
	}

void Zoo::feedAnimals()
	{
	 cout << "Event: Must feed all animals." << endl; 	
	 double accumulator;
 	 for (int i=0; i<numTigers; i++)
	  {
	   double temp = tigers[i]->getFoodCost();
	   accumulator = accumulator + temp;
	  }
	 for (int i=0; i<numPenguins; i++)
	  {
	   double temp = penguins[i]->getFoodCost();
	   accumulator = accumulator + temp;
	  }
	 for (int i=0; i<numTurtles; i++)
	  {
	   double temp = turtles[i]->getFoodCost();
	   accumulator = accumulator + temp;
	  }

	 cout << "You have spent $" << accumulator << " on animal feed today." << endl;
	 money = money-accumulator; //update money left over after feeding all the animals
	 cout << "You have $" << money << " remaining after feeding your animals." << endl;
	 cout << endl;
	}

void Zoo::randomEvent()
	{
	 cout << "Event: A random event will happen to your zoo." << endl;
	 //get random number between 1 and 4
 	 event = rand()%4+1;
	 //assign random event
	 switch(event)
	      { 	
		case 1: //sickness
	  	  cout << "One of your animals has gotten sick." << endl;
		  cout << endl; 
		  this->sick();
		  break;
		case 2: //attendance boom
		  cout << "There is an attentance boom in your zoo." << endl;
		  cout << endl; 
		  this->attendanceBoom();
		  break;
		case 3: //baby animal
		  cout << "One of your animals is going to give birth." << endl;	
	   	  cout << endl;
		  this->baby();
		  break;
		case 4: //nothing happens
		  cout << "Nothing has happened today. " << endl;
		  cout << endl;
              } 
	}

void Zoo::getProfit()
	{
	 //calculate the profit for each animal
	 for (int i=0; i<numTigers; i++)
		{
	          int temp = tigers[i]->getPayoff();
	  	  profit = profit+temp;
		}

         for (int i=0; i<numPenguins; i++)
		{
	          int temp = penguins[i]->getPayoff();
	  	  profit = profit+temp;
		}

         for (int i=0; i<numTurtles; i++)
		{
	          int temp = turtles[i]->getPayoff();
	  	  profit = profit+temp;
		}
	 //add the bonus
	 cout << "The profit alone for today is: $" << profit << endl;
	 cout << "The bonus for today is: $" << bonus << endl;
	 profit = profit+bonus;
	 cout << "The profit with bonus added for today is: $" << profit << endl;
	 money = money + profit;
	 cout << "Your updated total amount of money in your account is $" << money << endl;
	 cout << endl;
	 //reset the bonus
	 bonus=0;
	 //reset the profit
	 profit=0;
	}

void Zoo::buyAnother()
	{
	 int buyAnother;
	 cout << "Do you want to buy an adult animal? Press 1 for yes and 2 for no." << endl;
         cin >> buyAnother;
         while (!cin || buyAnother<1 || buyAnother >2)
           {
            cout << "Bad value, enter another." << endl;
            cin.clear();
            cin.ignore();
            cin >> buyAnother;
           }

         if (buyAnother == 1) //user wants to buy another animal
           {
            int userChoice;
            cout << "Press number to buy:" << endl;
            cout << "1. tiger" << endl;
            cout << "2. penguin" << endl;
            cout << "3. turtle" << endl;
            cin>> userChoice;
            while (!cin || userChoice <1 || userChoice >3)
              {
               cout << "Bad input, enter another." << endl;
               cin.clear();
               cin.ignore();
               cin >> userChoice;
              } 
	    //declare pointer to hold temporary arrays
	    Tiger**tempTiger;
	    Penguin**tempPenguin;
	    Turtle**tempTurtle;

	    switch (userChoice)
	      {
                case 1://buy another tiger
		  if (numTigers%10 ==0) //we have a multiple of 10, need to resize the array
		   {
		     //copy contents of array into a temporary array
		     tempTiger= new Tiger*[numTigers];
	             for (int i=0; i<numTigers; i++)
			{
			  tempTiger[i] = tigers[i];	
			}
		     //delete memory and then resize old array with 10 new spots 
		     delete [] tigers;
		     arraySizeTiger=arraySizeTiger+10; //add 10 new spots
		     tigers = new Tiger*[arraySizeTiger];
		     //reassign the values, but don't add the new member just yet 
		     for (int i=0; i<(numTigers); i++)
			{
			  tigers[i] = tempTiger[i];
			}
		     //increment the tiger population by 1
	 	     numTigers++;
		     //now assign the last member
		     tigers[numTigers-1] = new Tiger;
		     //set the age of the new member as an adult
    		     tigers[numTigers-1]->setAge(3);
		     //subtract from user's bank account
	 	     money = money-10000;
		     //update avail spaces on array
		     spotsTiger = spotsTiger+10-1;
		   }	
		  else
		   {
		     //increment the tiger population by 1
	 	     numTigers++;
		     //assign the last member
		     tigers[numTigers-1] = new Tiger;
		     //set the age of the new member as an adult
    		     tigers[numTigers-1]->setAge(3);
		     //subtract from user's bank account
	 	     money = money-10000;
		     //update avail spaces on array
		     spotsTiger = spotsTiger-1;
		   }
		 cout << "You have successfully purchased an adult tiger." << endl;
		 break;

	        case 2://buy another penguin
		  if (numPenguins%10 ==0)
		   {  
		    //copy contents of array into a temporary array
		    tempPenguin= new Penguin*[numPenguins];
	            for (int i=0; i<numPenguins; i++)
			{
			  tempPenguin[i] = penguins[i];	
			}
		    //delete memory and then resize old array
		    delete [] penguins;
	            arraySizePenguin = arraySizePenguin+10;
		    penguins = new Penguin*[arraySizePenguin];
		    //reassign the values, but don't add the new member yet
		    for (int i=0; i<(numPenguins); i++)
			{
			  penguins[i] = tempPenguin[i];
			}
		    //increment the penguin population by 1
		    numPenguins++;
		    //now assign the last member
		    penguins[numPenguins-1] = new Penguin;
		    //set the age of the new member as an adult
    		    penguins[numPenguins-1]->setAge(3);
		    //subtract from user's bank account
	 	    money = money-1000;
		    //update avail spaces on array
		    spotsPenguin = spotsPenguin+10-1;
		   }

		  else
		   {
		    //increment the penguin population by 1
		    numPenguins++;
		    //now assign the last member
		    penguins[numPenguins-1] = new Penguin;
		    //set the age of the new member as an adult
    		    penguins[numPenguins-1]->setAge(3);
		    //subtract from user's bank account
	 	    money = money-1000;
		    //update avail spaces on array
		    spotsPenguin = spotsPenguin-1;

		   }	
		  cout << "You have successfully purchased an adult penguin." << endl;
	 	  break;

	        case 3://buy another turtle
		  if (numTurtles%10==0)
		   {
		     //copy contents of array into a temporary array
		     tempTurtle= new Turtle*[numTurtles];
	             for (int i=0; i<numTurtles; i++)
			{
			  tempTurtle[i] = turtles[i];	
			}
		     //delete memory and then resize old array
		     delete [] turtles;
		     arraySizeTurtle = arraySizeTurtle+10;
		     turtles = new Turtle*[arraySizeTurtle];
		     //reassign the values, but don't add the new member yet
		     for (int i=0; i<(numTurtles); i++)
			{
			  turtles[i] = tempTurtle[i];
			}
		     //increment number of turtles by 1
		     numTurtles++;
		     //now assign the last member
		     turtles[numTurtles-1] = new Turtle;
		     //set the age of the new member as an adult
    		     turtles[numTurtles-1]->setAge(3);
		     //subtract from user's bank account
	 	     money = money-100;
		    //update avail spaces on array
		    spotsTurtle = spotsTurtle+10-1;

	           }
		  else
		   {
		     //increment number of turtles by 1
		     numTurtles++;
		     //assign the last member
		     turtles[numTurtles-1] = new Turtle;
		     //set the age of the new member as an adult
    		     turtles[numTurtles-1]->setAge(3);
		     //subtract from user's bank account
	 	     money = money-100;
		     spotsTurtle = spotsTurtle-1;
		   }
		cout << "You have successfully purchased an adult turtle." << endl;
	   }
	  cout << "You have $" << money << " left after making your purchase." << endl;
	  cout << endl;
	  //update on array spaces remaining
	  cout << "There are " << spotsTiger << " spots remaining for tigers." << endl;
	  cout << "There are " << spotsPenguin << " spots remaining for penguins." << endl;
	  cout << "There are " << spotsTurtle << " spots remaining for turtles." << endl;
	  cout << endl;
	}	
	 else
	   {
		cout << "You have chosen not to buy another animal." << endl;
		cout << endl; 
           } 

	}

bool Zoo::playAgain()
	{
	     if (money <=0)
	  	{
                  cout << "You have insufficient funds. You do not have enough money to play again." << endl;
		  return  false;
		}		
	     else //user has enough money to continue
		{
		 int userChoice;
		 cout << "Do you want to play again? Press 1 for yes and 2 for no. "  << endl; 
	    	 cin >> userChoice;
		 //verify input
		 while (!cin || userChoice<1 || userChoice>2)
			{
			  cout << "Bad value, enter another." << endl;
			  cin.clear();
			  cin.ignore();
			  cin >> userChoice;
			}
		  if (userChoice ==1)
			{
			  return true;	
			}
		  else
			{
			  return false;
			}
		}	

	}
/********************START OF RANDOM EVENT FUNCTIONS*******************/


void Zoo::sick()
	{
	 int death = rand()%3+1; //generate a random number between 1-3
	 //declare pointer to hold temporary arrays
	    Tiger**tempTiger;
	    Penguin**tempPenguin;
	    Turtle**tempTurtle;

	 switch (death)
		{
		   case 1://a tiger will die
		     cout << "A tiger has died." << endl;
		     cout << endl;
	    	     //copy contents of array into a temporary array
		     tempTiger= new Tiger*[numTigers];
	             for (int i=0; i<numTigers; i++)
			 {
			  tempTiger[i] = tigers[i];	
	 		 }
	             //decrement number of tigers by 1
		     numTigers--;
		     //delete memory 
		     delete [] tigers;
		     tigers = new Tiger*[arraySizeTiger];
		     //reassign the values, do not add the one at the end since it is now dead
		     for (int i=0; i<numTigers; i++)
			{
			  tigers[i] = tempTiger[i];
			}
		     //update the number of spots for tigers
		     spotsTiger++; 
		     break;

 		   case 2://a penguin will die
		     cout << "A penguin has died." << endl;
		     cout << endl;
		     //copy contents of array into a temporary array
		     tempPenguin= new Penguin*[numPenguins];
	             for (int i=0; i<numPenguins; i++)
			{
			  tempPenguin[i] = penguins[i];	
			}
		     //decrement the number of penuins by 1
		     numPenguins--;
		     //delete memory 
		     delete [] penguins;
		     penguins = new Penguin*[arraySizePenguin];
		     //reassign the values, do not add the one at the end since it is now dead
		     for (int i=0; i<(numPenguins); i++)
			{
			  penguins[i] = tempPenguin[i];
			}
		     spotsPenguin++;	
	       	     break;

		   case 3://a turtle will die
		     cout << "A penguin has died." << endl; 
		     cout << endl;
                     //copy contents of array into a temporary array
		     tempTurtle= new Turtle*[numTurtles];
	             for (int i=0; i<numTurtles; i++)
			{
			  tempTurtle[i] = turtles[i];	
			}
		     //decrement number of tigers by 1
		     numTurtles--;
		     //delete memory and then resize old array
		     delete [] turtles;
		     turtles = new Turtle*[arraySizeTurtle];
		     //reassign the values, do not add the one at the end since it is now dead 
		     for (int i=0; i<(numTurtles); i++)
			{
			  turtles[i] = tempTurtle[i];
			}
		     spotsTurtle++;	
		}
	  //update on array spaces remaining
	  cout << "There are " << spotsTiger << " spots remaining for tigers." << endl;
	  cout << "There are " << spotsPenguin << " spots remaining for penguins." << endl;
	  cout << "There are " << spotsTurtle << " spots remaining for turtles." << endl;
	  cout << endl;

	}

void Zoo::attendanceBoom()
	{
                  bonus = rand()%250+250; //generate a random number between 250-500
	 cout << "You received a bonus of $" << bonus << "." << endl;
	 cout << endl;
                  for (int i=0; i<numTigers; i++)
                   {
                    money = money+bonus; //for every tiger, add bonus to existing money
                   }  
	}

void Zoo::baby()
	{
	
	 int mother=0;//indicates which species will give birth
	 bool birth = false;
	 int check = 3;
	
	 int number = rand()%3+1;//generate a random number between 1-3

	while (check >0 && birth == false)
		{
			switch(number)
				{
					case 1://check if a tiger can give birth
					for (int i=0; i<numTigers; i++)
						{
						if (tigers[i]->getAge()>=3)
						  {
						   mother = 1;	
						   birth = true; 
						  }
						}
					number++;//number should now be 2
					check--;
					break;
					case 2://check if a penguin can give birth
					for (int i=0; i<numPenguins; i++)
						{
						if (penguins[i]->getAge()>=3)
						  {
						   mother = 2;	
						   birth = true; 
						  }
						}
					number++;//number should now be 3
					check--;
					break; 
					case 3://check if a turtle can give birth
					for (int i=0; i<numTurtles; i++)
						{
						if (turtles[i]->getAge()>=3)
						  {
						   mother = 3;	
						   birth = true; 
						  }
						}
					number= number-2; //number should now be 1
					check--;
				}
		}


		if (birth == false)
		 {
		  cout << "No animal is old enough to give birth." << endl;
		 }

		else //birth is true, at least one animal is old enough to give birth
		 {
	           //declare pointer to hold temporary arrays
	           Tiger**tempTiger;
	           Penguin**tempPenguin;
	           Turtle**tempTurtle;

	           switch (mother)
		    {
		     case 1: //tiger gives birth, add 1 to population
		     cout << "A tiger will give birth, +1 to tiger population." << endl;
		     if (numTigers%10 ==0)//need to resize the array
			{
		          //copy contents of array into a temporary array
		          tempTiger= new Tiger*[numTigers];
	                  for (int i=0; i<numTigers; i++)
			   {
			     tempTiger[i] = tigers[i];	
			   }
		          //delete memory and then resize old array
		          arraySizeTiger = arraySizeTiger+10; 
		          delete [] tigers;
		          tigers = new Tiger*[arraySizeTiger];
		          //reassign the values, but don't add the new member yet
		          for (int i=0; i<(numTigers); i++)
			    {
			      tigers[i] = tempTiger[i];
		 	    }
			  //increment the number of tigers by 1
			  numTigers++;
	                  tigers[numTigers-1] = new Tiger; //this is the baby tiger
			  spotsTiger+10-1; 
			}
	             else
			{
			  //increment the number of tigers by 1
			  numTigers++;
			  tigers[numTigers-1] = new Tiger; //this is the baby tiger
			  spotsTiger--;
			}

                    break;

  		  case 2: //penguin gives birth, add 5 to population
	 	    cout << "A penguin will give birth, +5 to penguin population. " << endl;
		    if ( (arraySizePenguin-numPenguins) <5 ) //there are fewer than 5 spots left in the penguin array so we must add more spots  
		     {	                    
			//copy contents of array into a temporary array
		        tempPenguin= new Penguin*[numPenguins];
	                for (int i=0; i<numPenguins; i++)
			  {
			    tempPenguin[i] = penguins[i];	
			  }
		        //delete memory and then resize old array
		        delete [] penguins;
			arraySizePenguin = arraySizePenguin+10;
		        penguins = new Penguin*[arraySizePenguin];
		        //reassign the values
		        for (int i=0; i<(numPenguins); i++)
			  {
			    penguins[i] = tempPenguin[i];
			  }
			//increment the population by 5
			numPenguins=numPenguins+5;
		        //now assign the 5 new members
		        for (int i=(numPenguins-6); i<numPenguins; i++)
			 {
		  	  penguins[i] = new Penguin;
			 }
			spotsPenguin=spotsPenguin+10-5;
		     }
		    else
		     {
			//increment the population by 5
			numPenguins=numPenguins+5;
		        //now assign the 5 new members
		        for (int i=(numPenguins-6); i<numPenguins; i++)
			  {
		  	  penguins[i] = new Penguin;
			  }
			spotsPenguin=spotsPenguin-5;
                     }	
		    break;

		  case 3: //turtle gives birth, add 10 to population
		    cout << "A turtle will give birth, +10 to turtle population. " << endl;
		    if ( (arraySizeTurtle-numTurtles) <10)	//not enough space to add 10, must resize array	  
 		     {
                       //copy contents of array into a temporary array
		       tempTurtle= new Turtle*[numTurtles];
	               for (int i=0; i<numTurtles; i++)
		 	 {
			   tempTurtle[i] = turtles[i];	
			 } 
		       //delete memory and then resize old array
		       delete [] turtles;
		       arraySizeTurtle = arraySizeTurtle+10;
		       turtles = new Turtle*[arraySizeTurtle];
		       //reassign the values, but don't add the new members yet
		       for (int i=0; i<(numTurtles-11); i++)
			 {
			   turtles[i] = tempTurtle[i];
			 }
		       //increment number of turtles by 10
		       numTurtles= numTurtles+10;
		       //now assign the last 10 members
		       for (int i=(numTurtles-11); i<numTurtles; i++)
			 {
		    	   turtles[i] = new Turtle;
			 }
		       //don't do anything to spotsTurtle because 10-10=0 
		     }

		    else
		     {
			//increment number of turtles by 10
		       numTurtles= numTurtles+10;
		       //now assign the last 10 members
		       for (int i=(numTurtles-11); i<numTurtles; i++)
			 {
		    	   turtles[i] = new Turtle;
			 }
			spotsTurtle=spotsTurtle-10;

		     }	

		 }

	    }

          //update on array spaces remaining
	  cout << "There are " << spotsTiger << " spots remaining for tigers." << endl;
	  cout << "There are " << spotsPenguin << " spots remaining for penguins." << endl;
	  cout << "There are " << spotsTurtle << " spots remaining for turtles." << endl;
	  cout << endl;

	}
