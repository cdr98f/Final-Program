//Programmers: Carson Ripple, Marshall Vacarro	//Date: 12/05/2018
//File: Burgermeister.h 
//Purpose: To simulate a burger eating contest and determine a winner.

#ifndef BURGERMEISTER_H
#define BURGERMEISTER_H

class Burgermeister
{
  public:
    Burgermeister(const string name, const float money);
    friend float operator +=(Burgermeister & lhs, const float & rhs);
  
  private:
    string name;
    float money;
};

#endif
