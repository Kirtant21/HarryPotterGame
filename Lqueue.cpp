// ***********************************************
// file: Lqueue.cpp
// author: prof Dixon & Kirtan Thakkar
// date: 11/7/2021
// class: CMSC 202 (FA21) sec 21
// desc: data structure for Harry Potter Game
// student ID: k238 (XS90456)
// *************************************************
#ifndef LQUEUE_CPP
#define LQUEUE_CPP
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Templated Node class used in templated linked list
template <class T>
class Node {
   public:
  Node( const T& data ); //Constructor
  T& GetData(); //Gets data from node
  void SetData( const T& data ); //Sets data in node
  Node<T>* GetNext(); //Gets next pointer
  void SetNext( Node<T>* next ); //Sets next pointer
private:
  T m_data;
  Node<T>* m_next;
};

//Overloaded constructor for Node
template <class T>
Node<T>::Node( const T& data ) {
   m_data = data;
   m_next = NULL;
}

//Returns the data from a Node
template <class T>
T& Node<T>::GetData() {
   return m_data;
}

//Sets the data in a Node
template <class T>
void Node<T>::SetData( const T& data ) {
   m_data = data;
}

//Gets the pointer to the next Node
template <class T>
Node<T>* Node<T>::GetNext() {
   return m_next;
}

//Sets the next Node
template <class T>
void Node<T>::SetNext( Node<T>* next ) {
   m_next = next;
}

template <class T>
class Lqueue {
 public:
  // Name: Lqueue() (Linked List Queue) - Default Constructor
  // Desc: Used to build a new linked queue (as a linked list)
  // Preconditions: None
  // Postconditions: Creates a new lqueue where m_head and m_tail point to nullptr
  Lqueue();
  // Name: ~Lqueue() - Destructor
  // Desc: Used to destruct a Lqueue
  // Preconditions: There is an existing lqueue with at least one node
  // Postconditions: An lqueue is deallocated (including dynamically allocated nodes)
  //                 to have no memory leaks!
 ~Lqueue();
  // Name: Lqueue (Copy Constructor)
  // Preconditions: Creates a copy of existing LQueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
  Lqueue(const Lqueue&);
  // Name: operator= (Overloaded Assignment Operator)
  // Preconditions: Copies an Lqueue into an existing Lqueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
  Lqueue<T>& operator= (Lqueue&);
  // Name: Push
  // Preconditions: Takes in data. Creates new node. 
  //                Requires a Lqueue
  // Postconditions: Adds a new node to the end of the lqueue.
  void Push(const T&);
  // Name: Pop
  // Preconditions: Lqueue with at least one node. 
  // Postconditions: Removes first node in the lqueue, returns data from first node.
  T Pop();
  // Name: Display
  // Preconditions: Outputs the lqueue.
  // Postconditions: Displays the data in each node of lqueue
  void Display();
  // Name: Front
  // Preconditions: Requires a populated lqueue
  // Postconditions: Returns whatever data is in front 
  T Front();
  // Name: IsEmpty
  // Preconditions: Requires a lqueue
  // Postconditions: Returns if the lqueue is empty.
  bool IsEmpty();
  // Name: size
  // Preconditions: Requires a lqueue
  // Postconditions: Returns m_size
  int size();
  // Name: Find()
  // Preconditions: Requires a lqueue
  // Postconditions: Iterates through lqueue and if it finds the thing, returns index, else -1
  int Find(T&);
  // Name: Swap(int)
  // Preconditions: Requires a lqueue
  // Postconditions: Swaps the nodes at the index with the node prior to it.
  void Swap(int);
  // Name: Clear
  // Preconditions: Requires a lqueue
  // Postconditions: Removes all nodes in a lqueue
  void Clear();
  //Name: Overloaded [] operator
  //Precondition: Existing Lqueue
  //Postcondition: Returns object from Lqueue using []
  //Desc: Iterates to node x and returns data from Lqueue
  T& operator[] (int x);//Overloaded [] operator to pull data from Lqueue
private:
  Node <T> *m_head; //Node pointer for the head
  Node <T> *m_tail; //Node pointer for the tail
  int m_size; //Number of nodes in queue
};

//***********IMPLEMENT LQUEUE HERE***********************




  // Name: Lqueue() (Linked List Queue) - Default Constructor
  // Desc: Used to build a new linked queue (as a linked list)
  // Preconditions: None
  // Postconditions: Creates a new lqueue where m_head and m_tail point to nullptr
template <class T>
Lqueue<T>::Lqueue(){

  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
}
  // Name: ~Lqueue() - Destructor
  // Desc: Used to destruct a Lqueue
  // Preconditions: There is an existing lqueue with at least one node
  // Postconditions: An lqueue is deallocated (including dynamically allocated nodes)
  //                 to have no memory leaks!
template <class T>
Lqueue<T>::~Lqueue(){

  Clear();
}
  // Name: Lqueue (Copy Constructor)
  // Preconditions: Creates a copy of existing LQueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
  template <class T>
  Lqueue<T>::Lqueue(const Lqueue& source){

    m_head = nullptr;
    m_tail = nullptr;

    for(Node<T>* curr = source.m_head; curr != nullptr; curr = curr->GetNext())
      {
	Push(curr->GetData());
      }
  }
  // Name: operator= (Overloaded Assignment Operator)
  // Preconditions: Copies an Lqueue into an existing Lqueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
template <class T>
Lqueue<T>& Lqueue<T>::operator= (Lqueue& source){

  Node<T>* curr;
  
    if(this != &source)
      {
	Clear(); 	
        m_head = nullptr; //source.m_head;
	m_size = 0;
	curr = source.m_head;
	
    while(curr != nullptr)
      {
	Push(curr->GetData());
	curr = curr->GetNext();
      }    
    }

    return *this;
 }
  // Name: Push
  // Preconditions: Takes in data. Creates new node.
  //                Requires a Lqueue
  // Postconditions: Adds a new node to the end of the lqueue.
template <class T>
void Lqueue<T>::Push(const T& data){

  Node<T>* temp = new Node<T>(data);
  
    if(m_head == nullptr)
      {
	m_head = temp;
	m_tail = temp;	
      }else{
      m_tail->SetNext(temp);
      m_tail = temp;
    }
    
    m_size++; 
}
  // Name: Pop
  // Preconditions: Lqueue with at least one node.
  // Postconditions: Removes first node in the lqueue, returns data from first node.
template <class T>
T Lqueue<T>::Pop()
  {
    Node<T>* curr = m_head;    
    T data = curr->GetData();

    if(m_head->GetNext() == nullptr)
      {
	delete curr;
	m_head = nullptr;
	m_tail = nullptr;

      }else{

    m_head = curr->GetNext();
    delete curr;
    }

    m_size--;
    
    return data;
}
  
  // Name: Display
  // Preconditions: Outputs the lqueue.
  // Postconditions: Displays the data in each node of lqueue
template <class T>
void Lqueue<T>::Display(){

  for(Node<T>* curr = m_head; curr != nullptr; curr = curr->GetNext())
    {
      cout << curr->GetData() << "->";
    }
    cout << endl;
}
  
  // Name: Front
  // Preconditions: Requires a populated lqueue
  // Postconditions: Returns whatever data is in front
template <class T>
T Lqueue<T>::Front(){

  return m_head->GetData();
}
  // Name: IsEmpty
  // Preconditions: Requires a lqueue
  // Postconditions: Returns if the lqueue is empty.
template <class T>
bool Lqueue<T>::IsEmpty(){

 if(m_head != nullptr)
   {
     return false;
   }
  return true;
}
  // Name: size
  // Preconditions: Requires a lqueue
  // Postconditions: Returns m_size
template <class T>
int Lqueue<T>::size(){
    
    return m_size;
}

  
// Name: Find()
// Preconditions: Requires a lqueue
// Postconditions: Iterates through lqueue and if it finds the thing, returns index, else -1
template <class T>
int Lqueue<T>::Find(T& theThing){

  Node<T>* curr = m_head;
  int idx = 0;
  
  while(curr != nullptr)
    {
      if(curr->GetData() == theThing)
	{
	  return idx;
	}
      
      curr = curr->GetNext();
      idx++;
    }    
    return -1;
}
// Name: Swap(int)
// Preconditions: Requires a lqueue
// Postconditions: Swaps the nodes at the index with the node prior to it.
template <class T>
void Lqueue<T>::Swap(int idx){
  
  Node<T>* curr = m_head, *prev = nullptr, *temp = nullptr, *next = nullptr;
  
  if(m_head != nullptr)
    {	
      for(int i = 1; i < idx - 1; i++)// goes to the node before the idx
	{
	  prev = curr; // node 2 nodes prior to idx 
	  curr = curr->GetNext();// node before idx  
	}
      
      
      temp = curr->GetNext(); //idx
      
      if(temp->GetNext() != nullptr)
	{
	  next = temp->GetNext(); // node after idx
	  temp->SetNext(curr);
	  prev->SetNext(temp);
	  curr->SetNext(next);
	}else{
	
	temp->SetNext(curr); // idx to curr
	prev->SetNext(temp); 
	curr->GetNext() = nullptr;
      }
    }
  
}
// Name: Clear
// Preconditions: Requires a lqueue
// Postconditions: Removes all nodes in a lqueue
template <class T>
void Lqueue<T>::Clear(){

  Node<T>* curr = m_head;

  while(m_head != nullptr)
    {
      m_head = curr->GetNext();
      delete curr;
      curr = m_head;
    }

  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;

}
//Name: Overloaded [] operator
//Precondition: Existing Lqueue
//Postcondition: Returns object from Lqueue using []
//Desc: Iterates to node x and returns data from Lqueue
template <class T>
T& Lqueue<T>::operator[] (int x){
  
  Node<T>* curr = m_head;
  
  for(int i = 0; i < x; i++)
    {
      curr = curr->GetNext();
    }
  
  return curr->GetData();
  
  
}

#endif
