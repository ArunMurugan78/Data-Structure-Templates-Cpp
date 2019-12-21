//by Arun
#ifndef iostream
#include<iostream>  //iostream required for input and output on standard output
#endif

template <class T>     //class linked list
class Linked_List
{
  struct node                    //node contains data and pointer for storing
  {                              // address of the next node in the linked list
    T data;
    node *nxt;
  } *head,*tail;

public:
  Linked_List(T data)                //paramaterised constructor
  {

    head = NULL;
    tail = NULL;
    add(data);
  }
  Linked_List()                     //default constructor
  {
    head = NULL;
    tail = NULL;
  }
  void print();
  void add();
  void del(T data);     //function for deleting node containing the passed data
  void add(T data);    //function for adding node containing the passed data
  ~Linked_List()       //destructor for deallocating memory
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
void Linked_List<T>::del(T data)
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
          tail = prev;
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
void Linked_List<T>::add()
{
  T data;
  std::cout<<"\nEnter data for the node :";
  std::cin>>data;
  if(!head)
  {
    node *temp = new node;
    temp->data = data;
    head = temp;
    tail = temp;
    tail->nxt = NULL;
  }
  else
  {
    node *temp = new node;
    temp->data = data;
    tail->nxt = temp;
    tail = temp;
    tail->nxt = NULL;
  }
}
template <class T>
void Linked_List<T>::print()
{
  node *temp = head;
  while(temp)
  {
    std::cout<<temp->data<<'\n';
    temp = temp->nxt;
  }
}
template <class T>
void Linked_List<T>::add(T data)
{

  if(!head)
  {

    node *temp = new node;
    temp ->data = data;
    head = temp;
    tail = temp;
    tail->nxt = NULL;
  }
  else
  {
    node *temp = new node;
    temp->data = data;
    tail->nxt = temp;
    tail = temp;
    tail->nxt = NULL;
  }
}
