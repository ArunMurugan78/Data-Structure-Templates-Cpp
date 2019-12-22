//by Arun
#ifndef iostream
#include<iostream>  //iostream required for input and output on standard output
#endif

template <class T>     //class stack
class stack
{
  struct node                    //node contains data and pointer for storing
  {                              // address of the next node in the stack
    T data;
    node *nxt;
  } *head;

public:
  stack(T data)                //paramaterised constructor
  {
    head = NULL;
    add(data);
  }
  stack()                     //default constructor
  {
    head = NULL;
  }
  void print();
  void add();
  void del(T data);     //function for deleting node containing the passed data
  void add(T data);    //function for adding node containing the passed data
  ~stack()       //destructor for deallocating memory
  {
    node *temp = head;
    while(head = head->nxt)
    {
      delete temp;
      temp = head;
    }
  }

};

template <class T>
void stack<T>::del(T data)
{
  node *temp = head;
  node *prev = NULL;
  while(temp)
  {
    if(temp->data == data)
    {
      if(prev)
      {
        if(temp->nxt == NULL)
        {
          prev->nxt = NULL;
        }
        else
        {
          prev->nxt = temp->nxt;
        }
      }
    else
    {
      head = head->nxt;
    }
    delete temp;
    return;
    }
  prev = temp;
  temp = temp->nxt;
  }
  std::cout<<"\nERROR : NODE NOT FOUND \n";
}

template <class T>
void stack<T>::add()
{
  static int j = 0;
  j++;
  T data;
  std::cout<<"\nEnter data for the node "<<j<<":";
  std::cin>>data;
  if(!head)
  {
    node *temp = new node;
    temp->data = data;
    head = temp;
    head->nxt = NULL;
  }
  else
  {
    node *temp = new node;
    temp->data = data;
    temp->nxt = head;
    head = temp;
  }
}
template <class T>
void stack<T>::print()
{
  node *temp = head;
  std::cout<<"Data stored in the Stack:\n";
  while(temp)
  {
    std::cout<<temp->data<<' ';
    temp = temp->nxt;
  }
}
template <class T>
void stack<T>::add(T data)
{
  if(!head)
  {
    node *temp = new node;
    temp->data = data;
    head = temp;
    head->nxt = NULL;
  }
  else
  {
    node *temp = new node;
    temp->data = data;
    temp->nxt = head;
    head = temp;
  }
}
