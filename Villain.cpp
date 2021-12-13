// ***********************************************
// file: Villain.cpp
// author: prof Dixon & Kirtan Thakkar
// date: 11/7/2021
// class: CMSC 202 (FA21) sec 21
// desc: Creates villain wizards for Harry Potter game
// student ID: k238 (XS90456)
// *************************************************
#include "Villain.h"

using namespace std;

  //Name: Villain (default constructor)
  //Precondition: None
  //Postcondition: Creates a Villain wizard object
  Villain::Villain(){

    m_name = "";
    m_desc = "";
    m_hp = 0;
    m_combat = 0;
    m_rarity = 0;
  }
  //Name: Villain (Overloaded constructor)
  //Precondition: None
  //Postcondition: Creates a Villian wizard object
  Villain::Villain(string name, string desc, int hp, int combat, int rarity){

    m_name = name;
    m_desc = desc;
    m_hp = hp;
    m_combat = combat;
    m_rarity = rarity;

  }
  //Name: GetCombat()
  //Precondition: None
  //Postcondition: Returns the combat value of the Villain wizard
  int Villain::GetCombat(){

    return m_combat;
  }
  //Name: GetHp()
  //Precondition: None
  //Postcondition: Returns the hit points of the Villain wizard
  int Villain::GetHp(){

    return m_hp;
  }
  //Name: GetRarity()
  //Precondition: None
  //Postcondition: Returns the rarity of the Villain wizard
  int Villain::GetRarity(){

    return m_rarity;
  }
  //Name: GetName()
  //Precondition: None
  //Postcondition: Returns the name of the Villain wizard
  string Villain::GetName(){

    return m_name;
  }
  //Name: GetDesc()
  //Precondition: None
  //Postcondition: Returns the description of the Villain wizard
  string Villain::GetDesc(){

    return m_desc;
  }

  //Name: SetHp()
  //Precondition: None
  //Postcondition: Sets the hp of the Villain
  void Villain::SetHp(int newHp){

    m_hp = newHp;
  }
  //Name: SetCombat()
  //Precondition: None
  //Postcondition: Sets the combat value of the Villain
  void Villain::SetCombat(int newCombat){

    m_combat = newCombat;
  }
  //Name: Attack()
  //Precondition: Existing Villain
  //Postcondition: Displays attack details
  void Villain::Attack(){

    cout << "waves their wand and screams \"Sectumsempra\"!" << endl;

  }
  //Name: operator<< (overloaded <<)
  //Precondition: Existing Villain
  //Postcondition: Prints information about the object
  ostream& operator<< (ostream& os, Villain &myVillain){

    os << myVillain.m_name << " (hp:" << myVillain.m_hp << " combat:" << myVillain.m_combat << ")" << endl;
    
    return os;
  }
