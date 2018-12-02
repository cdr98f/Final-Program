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
  string nextStep;
  int rounds = 1;
  bool eaten1;
  //for determining winners, we just need to see to it that no one
  //ate a burger for the entire round, and then just print all the
  //contestants that are still in
  
  for (int j = 0; j < 10; j++)
  {
    eaten1 = false;
    cout << "---------- Round " << rounds << "----------" << endl;
    for(int i = 0; i < AMNT_OF_PEOPLE; i++)
      contestants[i].turn(contestants, Krusty, 1, eaten1);
    cin << nextStep; //this is just to slow things down for now
    rounds++;
    if(!eaten1)
      //print winners
  } //obviously this will need to be changed back into a do while
   
  return 0;
}
