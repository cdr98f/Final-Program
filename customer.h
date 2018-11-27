//Programmers: Carson Ripple, Marshall Vacarro	//Date: 12/05/2018
//File: customer.h
//Purpose: To simulate a burger eating contest and determine a winner.


#ifndef DEBATE_H
#define DEBATE_H

#include "burger.h"
#include "Burgermeister.h"
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
const int DEATH_HEALTH = 0;
const int MIN_HEALTH = 1; //This is just for use in constructor
const int MAX_HEALTH = 100;
const int AMNT_CUSTOMERS = 15;
const int MAX_WEIGHT_GAIN = 80;
const int KRUSTY_NUM = 15; //Denotes whether Krusty is hit with a burger
const float PI = 3.14;
const float CHEESEGAIN = 1.2;
const float SAUCEGAIN = 2.1;
const float FUNERAL_FEE = 35;
const float VOMIT_FEE = 5;

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
    void toss(Customer contestants[], const int place);
    void turn(Customer people[], Burgermeister & Krusty, 
    const int index);
    bool checkAlive();
    bool vomit(const Customer people[], const int index);
    friend ostream & operator<< (ostream & os, const Customer & cust);
    bool getAlive() const;
     
  private:
    string m_custName;
    float m_wallet;
    short m_weight;
    short m_weightGain;
    short m_chol;
    bool m_isAlive;
    bool m_isContestant;
    short m_health;
};
#endif
