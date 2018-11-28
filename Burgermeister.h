//Programmers: Carson Ripple, Marshall Vacarro	//Date: 12/05/2018
//File: Burgermeister.h 
//Purpose: To simulate a burger eating contest and determine a winner.

#ifndef BURGERMEISTER_H
#define BURGERMEISTER_H

#include <iostream>
using namespace std;

const string BURGERMEISTER_NAME = "Krusty";
const int BURGERMEISTER_MONEY = 100;

class Burgermeister
{
  public:
    Burgermeister(const string name, const float money);
    friend void operator +=(Burgermeister & lhs, const float & rhs);
    friend void operator -=(Burgermeister & lhs, const float & rhs);
  
  private:
    string m_name;
    float m_money;
};

#endif
