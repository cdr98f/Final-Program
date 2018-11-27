//Programmer: Marshall Vaccaro		Date: 11/9/2018
//File: custClass.cpp
//Purpose: To define and test customer and burger classes
//         and their functions

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

void Customer::eat(const Burger & b1)
{
  if(b1.getVirus())
    m_isAlive = false;
  
  m_chol += 2.5 * b1.getBacon() + (PI/2)*b1.getPatties() 
         + static_cast <float> (m_weight)/((b1.getPickles() + 1) * 10);
		
  m_weight += 0.5*b1.getPatties() * b1.getPatties() + .125 * b1.getBacon()
           * b1.getBacon() - static_cast <float> (b1.getPickles())/4 
           + CHEESEGAIN + SAUCEGAIN;
		
  m_wallet = m_wallet - b1.getPrice();
  return;
} 
