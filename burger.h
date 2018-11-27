//Programmer: Marshall Vaccaro		Date: 11/9/2018
//File: burgClass.h
//Purpose: To define and test customer and burger classes
//         and their functions

#ifndef BURGCLASS_H
#define BURGCLASS_H

#include <iostream>
using namespace std;

//Constants
//Limits on random burger assingments
const short MIN_PICKLES = 0;
const short MAX_PICKLES = 4;
const short MIN_BACON = 0;
const short MAX_BACON = 4;
const short MIN_PATTIES = 1;
const short MAX_PATTIES = 4;

//Burger name variables
const string PATTY1 = "Single";
const string PATTY2 = "Double";
const string PATTY3 = "Triumph";
const string PATTY4 = "Monster";
const string BACON0 = "Health-Master";
const string BACON1 = "Bacon";
const string BACON2 = "Wilbur";
const string BACON3 = "Klogger";
const string BACON4 = "Wild";
const string PICKLE0 = "Tasteless";
const string PICKLE1 = "Pickly";
const string PICKLE2 = "Garden-Fresh";
const string PICKLE3 = "Kermit";
const string PICKLE4 = "Veggie";
const string W_SAUCE = "Saucy";
const string WO_SAUCE = "Dry";
const string W_CHEESE = "Cheesy";
const string WO_CHEESE = "Lactose-Intolerant";

//Special burger variables
const string MORE_PICKLES = "Krusty Veggie Burger"; 
const string MEAT6PICKLES1 = "Krusty Koronary Burger"; 

//Price values
const float PATTYCOST = .75;  
const float BACONCOST = .5; 
const float PICKLECOST = .25; 
const float BUNCOST = .5; 
const float CHEESECOST = .25; 
const float SAUCECOST = .1; 


//getPatties(), public
//Description: getPatties() returns the number of patties of the calling
//object
//Pre: none
//Post: The num of patties is returned

//getBacon(), public
//Description: getBacon() returns the number of bacons of the calling
//object
//Pre: none
//Post: The num of bacons is returned

//getPickles(), public
//Description: getPickles() returns the number of pickles of the calling
//object
//Pre: none
//Post: The num of pickles is returned
	
//getPrice(), public
//Description: getPrice() returns the price of the calling object
//Pre: none
//Post: The price is returned
	
//getVirus(), public
//Description: getVirus() returns the value of m_virus
//Pre: none
//Post: Whether a virus is in the burger is returned	

//setPrice(), private
//Description: setPrice() determines the price of the burger by it's defined
//  contents
//Pre: none
//Post: The price of the burger is set 

//setName(), private
//Description: setName() sets the name of the burger based on
//  its contents
//Pre: none
//Post: The name of the burger is set

//setPatties(), private
//Description: setPatties() checks the value of patties passed to it
//   and assigns the value of m_patties if it is in the correct range or 
//   exits the program
//Pre: none
//Post: the burger object's variable m_patties was assigned, or the program 
//   was stopped
	
//setPickles(), private
//Description: setPickles() checks the value of pickles passed to it and	
//   assigns the value to m_pickles if it is in the correct range or
//   exits the program
//Pre: none
//Post: the burger object's variable m_pickles was assigned, or the 
//   program was stopped

//setBacon(), private
//Description: setBacon() checks the value of bacon passed to it and
//   assigns the value to m_bacon is it is in the correct rang or it exits 
//   the program
//Pre: none
//Post: the burger object's variable m_bacon was assigned, or the 
//   program was stopped
	
class Burger
{
  public:
    //Constructors
    Burger();
    Burger(const int patties, const int bacon, const int pickles,
	const bool cheese, const bool sauce, const bool virus);
	
   //Overloading
    friend ostream& operator << (ostream& o, const Burger& burg);
    
    //Getters
    int getPatties() const {return m_patties;};
    int getBacon() const {return m_bacon;};
    int getPickles() const {return m_pickles;};
    float getPrice() const {return m_price;}; 
    bool getVirus() const {return m_virus;};

  private:
    //Variables
    int m_patties;
    int m_bacon;
    int m_pickles;
    float m_price;
    bool m_cheese;
    bool m_sauce;
    bool m_virus;
    string m_name;
	
    //Setters
    void setPrice();
    void setName();
    void setPatties(int pat);
    void setBacon(int bacon);	
    void setPickles(int pick);
};

#endif
