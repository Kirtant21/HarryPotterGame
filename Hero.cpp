// ***********************************************
// file: Hero.cpp
// author: prof Dixon & Kirtan Thakkar
// date: 11/7/2021
// class: CMSC 202 (FA21) sec 21
// desc: Creates hero for Harry Potter game
// student ID: k238 (XS90456)
// *************************************************
#include "Hero.h"

  //Name: Hero (default constructor)
  //Precondition: None
  //Postcondition: Creates a Hero object
 Hero::Hero(){

    m_name = "";
    m_desc = "";  
    m_hp = 0;
    m_combat = 0;
    m_rarity = 0;
      

  }
  //Name: Hero (Overloaded constructor)
  //Precondition: None
  //Postcondition: Creates a Hero object
  Hero::Hero(string name, string desc, int hp, int combat, int rarity){

    m_name = name;
    m_desc = desc;
    m_hp = hp;
    m_combat = combat;
    m_rarity = rarity;
	  
  }
  //Name: GetCombat()
  //Precondition: None
  //Postcondition: Returns the combat value of the Hero
  int Hero::GetCombat(){

    return m_combat;
  }
  //Name: GetHp()
  //Precondition: None
  //Postcondition: Returns the hit points of the Hero
  int Hero::GetHp(){

    return m_hp;
  }
  //Name: GetRarity()
  //Precondition: None
  //Postcondition: Returns the rarity of the Hero
  int Hero::GetRarity(){

    return m_rarity;
  }
  //Name: GetName()
  //Precondition: None
  //Postcondition: Returns the name of the Hero
  string Hero::GetName(){

    return m_name;
  }
  //Name: GetDesc()
  //Precondition: None
  //Postcondition: Returns the description of the Hero
  string Hero::GetDesc(){

    return m_desc;
  }

  //Name: SetHp()
  //Precondition: None
  //Postcondition: Sets the hp of the Hero
  void Hero::SetHp(int newHp){

    m_hp = newHp;
  }
  //Name: SetCP()
  //Precondition: None
  //Postcondition: Sets the combat value of the Hero
  void Hero::SetCombat(int newCombat){

    m_combat += newCombat;
  }

  //Name: Train()
  //Precondition: Existing Hero
  //Postcondition: Increases the combat value of the Hero by 10
  void Hero::Train(){

    SetCombat(10);
  }
  //Name: Attack()
  //Precondition: Existing Hero
  //Postcondition: Displays attack details
  void Hero::Attack(){
 
    cout << "waves their wand and screams \"Sectumsempra\"!" << endl;

  }
  //Name: operator<< (overloaded <<)
  //Precondition: Existing Hero
  //Postcondition: Prints information about the object
ostream& operator<< (ostream& os, Hero &myHero){

  os << myHero.m_name << " (hp:" << myHero.m_hp << " combat:" << myHero.m_combat << ")" << endl;

    return os;
  }
