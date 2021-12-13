// ***********************************************
// file: Game.cpp
// author: prof Dixon & Kirtan Thakkar
// date: 11/7/2021
// class: CMSC 202 (FA21) sec 21
// desc: runs Harry Potter Game
// student ID: k238 (XS90456)
// *************************************************
#include "Game.h"

Game::Game(string f_fileName){

  m_fileName = f_fileName;
}

Game::~Game(){
  
   for (unsigned int i = 0; i < m_heroes.size(); i++)
    {
      delete m_heroes.at(i);   
    }

  for (unsigned int i = 0; i < m_villains.size(); i++)
    {
      delete m_villains.at(i);	
    }
}
  // Name: LoadFile
  // Precondition: m_fileName must be populated
  // Postcondition: populates both m_heroes and m_villians from a file
  // Should be: Heros loaded: 230 Villains Loaded: 94 Total Loaded: 324
void Game::LoadFile(){

  string title = "", name = "", desc = "", hp1 = "", com = "", rar = "";
  int hp = 0, combat = 0, rarity = 0, heroes = 0, villains = 0;
  ifstream file;

  file.open(m_fileName);

  if(file.is_open())
    {
      while(getline(file, title, '|') && getline(file, name, '|') && getline(file, desc, '|') && getline(file, hp1, '|') && getline(file, com, '|') && getline(file, rar, '\n'))
	{
	   hp = stoi(hp1);
	   combat = stoi(com);
	   rarity = stoi(rar);
	  
	  if(title == "HERO")
	    {
	      Hero* hero = new Hero(name, desc, hp, combat, rarity);
	      m_heroes.push_back(hero);
	      heroes++;
	    } else if(title == "VILLAIN"){
	    
		Villain* villain = new Villain(name, desc, hp, combat, rarity);
		m_villains.push_back(villain);
		villains++;
	      }
	}
      
    }else{

    cout << "Error: File loading unsucessful.. \nPlease check your file input" << endl;
  }
  
  file.close();

  cout << "Heros loaded: " << heroes << " Villains Loaded: " << villains << " Total Loaded: " << (heroes + villains) << endl;
    
}

  // Name: PrintHeroes
  // Precondition: m_heroes must be populated
  // Postcondition: prints all heroes in m_heroes
void Game::PrintHeroes(){


  //****** Under maintainance *******
  
  for(unsigned int i = 0; i < m_heroes.size(); i++)
    {
      cout << i+1 << ". " << *m_heroes[i] << endl;
    }

}
  // Name: PrintVillains
  // Precondition: m_villains must be populated
  // Postcondition: prints all villians in m_villians
void Game::PrintVillains(){

  //****** Under maintainance *******

  for(unsigned int i = 0; i < m_villains.size(); i++)
    {
      cout << i+1 << ". " <<  *m_myHeroes[i] << endl;
    }
}
  // Name: PrintMyHeroes();
  // Precondition: m_myHeroes must be populated
  // Postcondition: prints all heroes found in m_myHeroes
void Game::PrintMyHeroes(){

  if(!m_myHeroes.IsEmpty())
    {
      for(int i = 0; i < m_myHeroes.size(); i++)
	{
	  cout << i+1 << ". " << *m_myHeroes[i] << endl;
	}
      
    }else{
    cout << "you don't have any heros yet!" << endl;
  }

}
  // Name: AcquireHero
  // Pre-condition: Requires m_heroes vector to be populated
  // Post-condition: Prompts user for rarity (1-5) user would like to capture
  //          Based on rarity (1=65%, 2=45%, 3=25%, 4=10%, 5=1%) tries to find a random
  //          Hero based on that rarity.
  //          If a Hero is found, calls FoundHero else indicates no hero was found
void Game::AcquireHero(){

  int rarity = 0;
  int range = 1 + (rand()%100);

   
  cout << "How rare of a wizard would you like to recruit?:" << endl;
  cout << "1. Very Common (Very High Probability)" << endl;
  cout << "2. Common (High Probability) "<< endl;
  cout << "3. Uncommon (Normal Probability)" << endl;
  cout << "4. Rare (Low Probability)" << endl;
  cout << "5. Ultra Rare (Extremely Low Probability)"<< endl;
  cin >> rarity;

  cout << "You ask around to see if anyone would be willing to join you." << endl;
  if(RARITY[rarity-1] >= range)
    {
      FoundHero(rarity);

    }else{    

    cout << "No hero was found!" << endl;
    
  }
  
}
  // Name: FoundHero ()
  // Pre-condition: If a Hero is found in AcquireHero, rarity is passed to this function
  // Post-condition: Using rarity, a m_heroes is randomly searched for
  //                 a matching rarity also uses Lqueue.Find to make
  //                 sure that new wizard is unique (can only have one of each)
  //                 After an appropriate Hero is found
  //                 Adds new Hero to user's m_myHeroes
void Game::FoundHero(int rarity){

  int range = 0, maxRange = m_heroes.size();
  bool search = true;
  
  while(search)
    {      
      range = (rand() % maxRange);
      if(m_heroes[range]->GetRarity() == rarity) // randomly checks the heroes for rarity 
	{
	  if((m_myHeroes.Find(m_heroes[range])) == -1) // checks if the hero´s already been taken or not
	    {
	      m_myHeroes.Push(m_heroes[range]);
	      search = false; 
	    }
	}
    }

  cout << "With some amount of effort, " << m_heroes[range]->GetName() << " has agreed to join you!" << endl;
}
  // Name: MainMenu
  // Pre-condition: None
  // Post-condition: Calls a variety of functions based on user
void Game::MainMenu(){

  int input = 0;
  bool wizardLandOn = true;
  
  while(wizardLandOn)
    {
      do{
	cout << "What would you like to do?:" << endl;
	cout << "1. See All Heroes" << endl;
	cout << "2. See All Villains" << endl;
	cout << "3. See Your Heroes" <<endl;
	cout << "4. Try to Acquire a New Hero" << endl;
	cout << "5. Train a Hero" << endl;
	cout << "6. Enter a Wizard Battle" << endl;
	cout << "7. Exit" << endl;
	
	cin >> input;
	
      }while((input < 1) || input > 7 );
      
      switch(input)
	{
	case 1:
	  PrintHeroes();
	  break;
	case 2:
	  PrintVillains();
	  break;
	case 3:
	  PrintMyHeroes();
	  break;
	case 4:
	  AcquireHero();
	  break;
	case 5:
	  TrainHero();
	  break;
	case 6:
	  Battle();
	  break;
	case 7:
	  wizardLandOn = false;
	  break;
	default:  
	  cout << "Error: invalid input" << endl;
	}
    }
   cout << "Thank you for playing Harry Potter!" << endl;
}
  // Name: PrepareVillains
  // Pre-condition: Asks the user how many villians to battle (up to MAX_VILLAINS)
  //                Has the computer randomly add villians to send to battle to m_bVillains Tqueue
  // Post-condition: Battle continues
void Game::PrepareVillains(){

  int num = 0;
  int villainSearch = 0;

  if(!m_myHeroes.IsEmpty())
    {
      do{
	
	cout << "How many villains would you like to battle with?" << endl;
	cin >> num;

	if(num > MAX_VILLAINS)
	  {
	    cout << "you can only add upto " << MAX_VILLAINS << endl;
	  }
	
      }while((num < 1) || num > MAX_VILLAINS);
      
      
      for(int i = 0; i < num; i++)
	{
	  villainSearch = 1 + (rand()%m_villains.size());
	  m_bVillains.Push(m_villains[villainSearch]);      
	  
	}
           
      cout << endl;
      cout << SEP << endl;
      cout << "The enemy wizards stand ready to battle" << endl;
      
      for(int i = 0; i < m_bVillains.size(); i++)
	{
	  cout << *m_bVillains[i] << endl;
	}
      cout << SEP << endl;
    }else{
    cout << "***Request denied!***" << endl;
  }
}
  // Name: PrepareHeroes
  // Pre-condition: Populates m_bHeroes from myHeroes
  //                Can add up to MAX_HEROES heroes per battle
  //                Could add the SAME hero more than once to the battle queue (not checked)
  // Post-condition: Battle continues
void Game::PrepareHeroes(){

  int num = 0;

  do{

    cout << "Add from 1 to 5 heroes to your battle roster" << endl;
    cout << "Enter -1 when done" << endl;
    PrintMyHeroes();
    cin >> num;
    
    if(m_bHeroes.size() < MAX_HEROES)
      {	
	if(num > 0 && num < 5)
	  {
	    m_bHeroes.Push(m_myHeroes[num]);
	  }
      }else{

      cout << "you can only add up to 5 heroes, enter (-1) to continue battle! " << endl;
    }
  }while(num != -1);
	  
      // **** Analysis ****
  cout << SEP << endl;
  cout << "The hero wizards stand ready to battle" << endl;
  for(int i = 0; i < m_bHeroes.size(); i++)
    {
      cout << *m_bHeroes[i] << endl;
    }
  cout << SEP << '\n' << endl;
            
}
  // Name: Battle
  // Pre-condition: Calls PrepareVillains to populate m_bVillains
  //                Calls PrepareHeroes it populate m_bHeroes
  //                Hero attacks first then if villian still alive villian attacks
  //                If hp is below 0 then hero or villian is dequeued from their battle queue
  // Post-condition: Calls ResolveBattle to identify winner
void Game::Battle(){

  bool battleOn = true;

  if(!m_myHeroes.IsEmpty())
    {
      PrepareVillains();
      PrepareHeroes();    
      cout << "Done preparing heroes!" << endl;
  
      while(battleOn)
	{
	  cout << "running with heroes: " << m_bHeroes.size() << endl;
	  cout << m_bHeroes.Front()->GetName() << " vs " << m_bVillains.Front()->GetName() << endl;
	  
	  // ***** Hero Attacks *******

	  if(!m_bVillains.IsEmpty() && !m_bHeroes.IsEmpty())
	    {
	      if(m_bHeroes.Front()->GetHp() > 0)
		{
		  cout << m_bHeroes.Front()->GetName();
		  m_bHeroes.Front()->Attack(); // hero attacks
		  cout << endl;
		  m_bVillains.Front()->SetHp((m_bVillains.Front()->GetHp())-(m_bHeroes.Front()->GetCombat())); // reduces villain's hp by hero's combat
		  
		  if(m_bVillains.Front()->GetHp() < 1)
		    {
		      cout << m_bVillains.Front()->GetName() << " is defeated!" << endl;
		      m_bVillains.Pop(); // removes the defeated villain
		    }
		}
	    }
	  // ***** Villains Attacks *******

	  if(!m_bHeroes.IsEmpty() && !m_bVillains.IsEmpty())
	    {
	      if(m_bVillains.Front()->GetHp() > 0)
		{
		  
		  cout << m_bVillains.Front()->GetName();
		  m_bVillains.Front()->Attack(); // hero attacks
		  cout << endl;
		  m_bHeroes.Front()->SetHp((m_bHeroes.Front()->GetHp())-(m_bVillains.Front()->GetCombat())); // reduces hero's hp by the villain's combat
	      
		  
		  if(m_bHeroes.Front()->GetHp() < 1)
		    {
		      cout << m_bHeroes.Front()->GetName() << " is defeated!" << endl;
		      m_bHeroes.Pop(); // removes the defeated hero
		    }	  
		}   
	    }
	  
	  if(m_bHeroes.IsEmpty() || m_bVillains.IsEmpty())
	    {
	      battleOn = false;
	    }	  
	}
      
      ResolveBattle();
    }else{
    cout << "****Permission denied***" << endl;
    cout << "Not enough heroes for Wizard Battle!" << endl;
  }
}

  // Name: ResolveBattle  
  // Pre-condition: If m_bHeroes has heroes left, they win else villians win
  // Post-condition: None
void Game::ResolveBattle(){

  cout << SEP << endl;
  
  if(!m_bHeroes.IsEmpty())
    {
      cout << "The hero wizards win the battle!" << endl;
    }else{
    cout << "The villain wizards win the battle!" << endl;
  }

   cout << SEP << endl;
}
  // Name: TrainHero()
  // Pre-condition: User chooses hero from myHero to train
  // Post-condition: Calls Train member function that increases Combat by 10.
  //                 Updates hero's combat in m_myHeroes
void Game::TrainHero(){

  int input;

  if(!m_myHeroes.IsEmpty())
    {
      do{
	cout << "Which of your wizards would you like to train?:" << endl;
	PrintMyHeroes();
	cin >> input;
	input--;
      }while((input < 0) || input > m_myHeroes.size());
      
      m_myHeroes[input]->Train();
      cout << "your " << m_myHeroes[input]->GetName() << " trained" << endl;
      cout << "your combat is now " << m_myHeroes[input]->GetCombat() << endl;
    }else{
    cout << "**** Permission denied ****" << endl;
    cout << "you don't have any heros to train!" << endl;
  }
}
