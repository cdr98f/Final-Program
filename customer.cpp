//Programmers: Carson Ripple, Marshall Vacarro	//Date: 12/05/2018
//File: customer.cpp
//Purpose: To simulate a burger eating contest and determine a winner.

#include "customer.h"
#include <iostream>
#include <fstream>
using namespace std;

//constructor
Customer :: Customer()
{
  static int count = 0; //increments every time a cust is made
  int loop = 0;
  ifstream fin;
  fin.open("simpson_names.dat");
  
  //Increasing the number of times a customer is created every time ensures
  //unique names.
  getline(fin, m_custName);
  while(!fin.eof() && loop < count)
  {
    getline(fin, m_custName);
	loop++;
  }
  
  //program will exit if it goes off the file
  if(loop > count)
  {
	cout << "No more names! You've tried to create too many customers";
	exit(3);
  }
  
  fin.close();
  
  m_wallet = static_cast <float> (rand() % ((MAX_WALLET - MIN_WALLET + 1) * 
        100)) / 100 + MIN_WALLET;
  
  m_weight = (rand() % (MAX_POUNDS - MIN_POUNDS + 1)) + MIN_WALLET;
  
  m_chol = (rand() % (MAX_CHOL - MIN_CHOL + 1)) + MIN_CHOL;
	
  m_health = (rand() % (MAX_HEALTH - MIN_HEALTH + 1)) + MIN_HEALTH;
	
  m_isContestant = true;
  
  m_weightGain = 0;
  
  count++;
}

//insertion
ostream & operator << (ostream & os, const Customer & cust)
{
  os << cust.m_custName << " has $" << cust.m_wallet
     << ", weighs " << cust.m_weight << " lbs, and has "  
     << cust.m_chol << " IBU, ";
	 
  if (cust.m_isAlive)
    os << "ALIVE";
  else
    os << "DEAD";
  return os;
}

void Customer::eat(const Burger & b1, bool & vomit)
{ 
  if(b1.getVirus())
  {
    if((rand() % 101 + 1) > m_health))
    {
      m_health = 0;
      m_isAlive = false;
      m_isContestant = false;
    }
    else
    {
      vomit = true;
      m_health = m_health/2;
    }
  }
  
  m_chol += 2.5 * b1.getBacon() + (PI/2)*b1.getPatties() 
         + static_cast <float> (m_weight)/((b1.getPickles() + 1) * 10);
		
  m_weight += 0.5*b1.getPatties() * b1.getPatties() + .125 * b1.getBacon()
           * b1.getBacon() - static_cast <float> (b1.getPickles())/4 
           + CHEESEGAIN + SAUCEGAIN;
	
  m_weightGain += 0.5*b1.getPatties() * b1.getPatties() + .125 * b1.getBacon()
           * b1.getBacon() - static_cast <float> (b1.getPickles())/4 
           + CHEESEGAIN + SAUCEGAIN;	
  m_wallet = m_wallet - b1.getPrice();
  m_health -= 2;
  return;
} 

void Customer::turn(Customer people[], Burgermeister & Krusty,
 const int index)
{
  int i = index;
  bool ifVomit;
  bool continueChain = true;
  Burger newBurger;
  if ((m_wallet > newBurger.getPrice()) && m_isAlive && m_isContestant)
  {
    Krusty += newBurger.getPrice();
    eat(newBurger, ifVomit);
    m_isAlive = checkAlive();
    if (!m_isAlive)
      Krusty -= FUNERAL_FEE;
  }
  if (ifVomit && (index < AMNT_CUSTOMERS - 1) && (m_isAlive))
  {
    do
    {
      continueChain = vomit(people, index + 1);
      index++;
    }
    while ((continueChain) || (index < AMNT_CUSTOMERS));
    do
    {
      continueChain = vomit(people, i - 1);
      i--;
    }
    while ((continueChain) || (i >= 0));
  }
    
  
  return;
}
	
bool checkAlive()
{
  bool alive = true;
  if ((m_health <= DEATH_HEALTH) || (m_chol > MAX_CHOL) 
   || (m_weightGain > MAX_WEIGHT_GAIN))
    alive = false;
    
  return alive;
}

const bool getAlive()
{
  return m_isAlive;
}

bool vomit(const Customer people[], const int index)
{
  bool contVomit = false
  if (rand()%2 == 1 && people[index].getAlive())
    contVomit = true;
  else if ((rand() % 10) < 7 && people[index].getAlive())
    people[index].toss(index);
            
  return contVomit;
}

void toss(Customer contestants[], const int place)
{
  int personHit;
  
  personHit = rand() % (AMNT_CUSTOMERS + 1);
  
  if (personHit == KRUSTY_NUM)
  {
    m_isContestant = false;
    Krusty += m_wallet;
  }
  else if (((rand() % 10) < 8) && (personHit != place))
    contestants[personHit].toss(personHit);
        
  return;
}