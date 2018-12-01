//Programmers: Carson Ripple, Marshall Vacarro	//Date: 12/05/2018
//File: Contest.cpp
//Purpose: To simulate a burger eating contest and determine a winner.

#include "customer.h"
#include "Burgermeister.h"
#include <iostream>

using namespace std;

int main()
{ 
  const int AMNT_OF_PEOPLE = 15;
  Customer contestants[AMNT_OF_PEOPLE];
  Burgermeister Krusty(BURGERMEISTER_NAME,BURGERMEISTER_MONEY);
  
  do
  {
    for(int i = 0; i < AMNT_OF_PEOPLE; i++)
    
      contestants[1].turn(contestants, Krusty, 1);
    
   
   
  } while ();
  return 0;
}
