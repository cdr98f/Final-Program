//Programmers: Carson Ripple, Marshall Vacarro	//Date: 12/05/2018
//File: Burgermeister.h
//Purpose: To simulate a burger eating contest and determine a winner.

#include "Burgermeister.h"
#include <iostream>

using namespace std;

Burgermeister :: Burgermeister(const string name, const float money)
{
  m_name = name;
  if(money > 0)
  {
    m_money = money;
  }
  else
    exit(2);
}

void operator += (Burgermeister & lhs, const float & rhs)
{
  lhs.m_money += rhs;
  return;
}

void operator -= (Burgermeister & lhs, const float & rhs)
{
  if(rhs < lhs.m_money)
    lhs.m_money = 0; //so krusty can't run a deficit
  else
    lhs.m_money -= rhs;
  
  return;
}

