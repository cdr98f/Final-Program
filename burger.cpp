//Programmers: Carson Ripple, Marshall Vacarro	//Date: 12/05/2018
//File: burger.cpp
//Purpose: To simulate a burger eating contest and determine a winner.

#include "burger.h"
using namespace std;

//Constrctors
Burger::Burger()
{
  m_patties = (rand() % (MAX_PATTIES + 1 - MIN_PATTIES)) + MIN_PATTIES;
  m_bacon = (rand() % (MAX_BACON + 1 - MIN_BACON)) + MIN_BACON;
  m_pickles = (rand() % (MAX_PICKLES + 1 - MIN_PICKLES)) 
        + MIN_PICKLES;
  
  m_cheese = rand() % 2;
  m_sauce = rand() % 2; 
  m_virus = ((rand() % 10) == 0);
  
  setPrice();
  setName(); 
}

Burger::Burger(const int patties, const int bacon, const int pickles,
        const bool cheese, const bool sauce, const bool virus)
{
  setPatties(patties);
  setBacon(bacon);
  setPickles(pickles);
  
  m_cheese = cheese;
  m_sauce = sauce;
  m_virus = virus;
  
  setPrice();
  setName();
}

//insertion
ostream& operator<<(ostream & os, const Burger & b1)
{
  os << b1.m_name << endl <<"     (" << b1.m_patties << ", " << b1.m_bacon 
    << ", " <<  b1.m_pickles << ", ";
  
  if(b1.m_cheese)
	os << "true, ";
  else
	os << "false, ";
  
  if(b1.m_sauce)
	os << "true, ";
  else
	os << "false, ";

  if (b1.m_virus)
	os << "true";  
  else 
	os << "false";

  os << ") $" << b1.m_price;
  return os;
}

//setters
void Burger::setPrice()
{
  m_price = m_patties * PATTYCOST + m_bacon * BACONCOST
       + m_pickles * PICKLECOST + m_cheese * CHEESECOST
	   + m_sauce * SAUCECOST;
  return;
}

void Burger::setName()
{
  m_name = "Krusty's ";

  switch (m_patties)
  {    
    case 1:
      m_name += PATTY1 + " ";
      break;

    case 2:
      m_name += PATTY2 + " "; 
      break; 

    case 3: 
      m_name += PATTY3 + " ";
      break; 

    case 4: 
      m_name += PATTY4 + " ";
      break;
  } 

  switch (m_bacon) 
  { 
    case 0: 
      m_name += BACON0 + " "; 
      break; 
   
    case 1: 
      m_name += BACON1 + " "; 
      break; 

    case 2: 
      m_name += BACON2 + " ";
      break; 

    case 3:
      m_name += BACON3 + " "; 
      break;
 
    default:
      m_name += BACON4 + " ";	  
  } 

  switch (m_pickles) 
  {
    case 0: 
      m_name += PICKLE0 + " "; 
      break; 

    case 1: 
      m_name += PICKLE1 + " "; 
      break; 

    case 2: 
      m_name += PICKLE2 + " "; 
      break; 

    case 3: 
      m_name += PICKLE3 + " "; 
      break;

    default:
      m_name += PICKLE4 + " "; 
  } 

  m_name += "Burger, ";
  
  //this replaces the first part of the name if the conditions are met
  if(m_pickles >= (m_patties + m_bacon)) 
    m_name = MORE_PICKLES + " "; 

  if (((m_patties + m_bacon) == 6) && (m_pickles < 2))
    m_name = MEAT6PICKLES1 + " ";

  //Cheese
  if (m_cheese)
    m_name += W_CHEESE + " and ";
  else
    m_name += WO_CHEESE + " and ";

  //Sauce
  if (m_sauce)
    m_name += W_SAUCE;
  else
    m_name += WO_SAUCE;
  return;
}

void Burger::setPatties(int pat)
{
  if(pat < MIN_PATTIES || pat > MAX_PATTIES)
  {
    cout << "Invalid number of patties." << endl;
    exit(2);
  }
  
  m_patties = pat;
  return;
}

void Burger::setBacon(int bacon)
{
  if(bacon < MIN_BACON || bacon > MAX_BACON)
  {
    cout << "Invalid number of bacons." << endl;
    exit(2);
  }
  
  m_bacon = bacon;
  return;
}

void Burger::setPickles(int pickles)
{
  if(pickles < MIN_PICKLES || pickles > MAX_PICKLES)
  {
    cout << "Invalid number of pickles." << endl;
    exit(2);
  }
  
  m_pickles = pickles;
  return;
}
