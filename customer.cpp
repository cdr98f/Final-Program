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
    if((rand() % 101 + 1) > m_health)
    {
      m_health = 0;
      m_isAlive = false;
      m_isContestant = false;
      cout << m_custName << " just died!" << endl;
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

//Output done here
//I made index constant. It should be so you keep track of the center of the loops
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
    m_isAlive = checkAlive(); //not sure it this is necessary since you checked in eat
    if (!m_isAlive)
      Krusty -= FUNERAL_FEE;
  }
  
  //vomit sequence
  if(ifVomit)
    cout << m_custName << " has vomited." << endl;
  //can you explain the use of index here
  if (ifVomit && (index < AMNT_CUSTOMERS - 1) && (m_isAlive)) //Idk if you need m_isAlive
  {
    do
    {
      continueChain = vomit(people, i + 1, Krusty);
      if (continueChain)
        cout << people[i+1] << " has vomited. "<< endl;
      i++; //may walk off this array in line above
    }
    while ((continueChain) || (index < AMNT_CUSTOMERS));
    i = index;
    do
    {
      continueChain = vomit(people, i - 1, Krusty);
      if (continueChain)
        cout << people[i-1] << " has vomited." << endl;
      i--;
    } //again this may walk off array
    while ((continueChain) || (i >= 0));
  }
    
  
  return;
}
	
bool Customer::checkAlive()
{
  bool alive = true;
  if ((m_health <= DEATH_HEALTH) || (m_chol > MAX_CHOL) 
   || (m_weightGain > MAX_WEIGHT_GAIN))
    alive = false;
    
  return alive;
}

bool Customer::getAlive() const 
{
  return m_isAlive;
}

//no need for output, vomit loop is taken care of elsewhere
bool Customer:: vomit(Customer people[], const int index, Burgermeister & Krusty)
{
  bool contVomit = false;
  if (rand()%2 == 1 && people[index].getAlive())
    contVomit = true;
  else if ((rand() % 10) < 7 && people[index].getAlive())
    people[index].toss(people, index, Krusty);
  
  return contVomit;
}

//have output for food fight now
void Customer:: toss(Customer contestants[], const int place, Burgermeister & Krusty)
{
  //calling customer threw the burger
  int personHit;
  burger thrownBurg;
  bool isThrown = (rand() % 10) < 8)
  
  personHit = rand() % (AMNT_CUSTOMERS + 1);
  
  //if the thrown burger hit krusty
  if (personHit == KRUSTY_NUM && m_isAlive && isThrown)
  {
    cout << m_custName << " has thrown a burger at Krusty!" << endl;
    cout << m_custName << " is disqualified." << endl;
    m_isContestant = false;
    Krusty += m_wallet; 
  }
  //if the 
  else if (personHit != place && isAlive && isThrown)
  {
    cout << m_custName << " has thrown a burger at " << contestants[personHit].m_custName;
    Krusty += thrownBurg.getPrice(); //Not sure on this function
    m_wallet -= thrownBurg.getPrice(); //Transaction for the burgers
    contestants[personHit].toss(contestants, personHit, Krusty);
  }
  else if (personHit == place && isAlive && isThrown)// so user knows the fight ended
  {
    m_wallet -= thrownBurg.getPrice(); //Transaction for the burgers
    cout << m_custName << " threw a burger on themself." << endl;
  }
  else if (!isAlive)
  {
    cout << m_custname << " is dead and can't participate." << endl;
  }
  else
    cout << m_custName << " chose not to throw." << endl;
  
  return;
}
