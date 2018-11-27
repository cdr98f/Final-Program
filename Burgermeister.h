//Programmers: Carson Ripple, Marshall Vacarro	//Date: 12/05/2018
//File: Burgermeister.h 
//Purpose: To simulate a burger eating contest and determine a winner.

#ifndef BURGERMEISTER_H
#define BURGERMEISTER_H

const string BURGERMEISTER_NAME = "Krusty";

class Burgermeister
{
  public:
    Burgermeister(const string name, const float money);
    friend float operator +=(Burgermeister & lhs, const float & rhs);
  
  private:
    string m_name;
    float m_money;
};

#endif
