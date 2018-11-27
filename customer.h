//Programmer: Marshall Vaccaro		Date: 11/9/2018
//File: custClass.h
//Purpose: To define and test customer and burger classes
//         and their functions


#ifndef DEBATE_H
#define DEBATE_H

#include "burger.h"
#include <iostream>
using namespace std;

//Constants:
//Limits on random customer assignments
const int MIN_WALLET = 25;
const int MAX_WALLET = 75;
const int MIN_POUNDS = 90;
const int MAX_POUNDS = 250;
const int MIN_CHOL = 30;
const int MAX_CHOL = 300;
const int MIN_HEALTH = 1; //This is just for use in constructor
const int MAX_HEALTH = 100;
const float PI = 3.14;
const float CHEESEGAIN = 1.2;
const float SAUCEGAIN = 2.1;

//eat():
//Description: eat() takes a burger object and uses variables 
//  describing the burger to change information about the calling customer
//Pre: none
//Post: information about the calling customer is changed 
//  according to the information associated with the burger argument

class Customer
{
  public:
    Customer ();
    void eat(const Burger & burg);
    int toss();
    void turn(const Burger & burg);
    friend ostream & operator<< (ostream & os, const Customer & cust);
     
  private:
    string m_custName;
    float m_wallet;
    short m_weight;
    short m_chol;
    bool m_isAlive;
    bool m_isContestant;
    short m_health;
};
#endif
