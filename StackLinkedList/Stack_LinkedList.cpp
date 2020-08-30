#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

class Node
{
public:
  int data;
  Node *next, *nextNode;

  Node(int data = 0, Node *next = 0)
  {
    this->data = data;
    this->next = next;
  }
};

class Stack_using_LinkedList
{
  Node *top, *temp;
  int No_nodes;

public:
  Stack_using_LinkedList()
  {
    top = temp = 0;
    No_nodes = 0;
  }
  ~Stack_using_LinkedList()
  {
    temp = top;
    Node *nextNode;
    while (temp != 0)
    {
      nextNode = temp->next;
      delete temp;
      temp = nextNode;
    }
  }

  void Push(int x)
  {
    temp = new Node(x, 0);
    if (top == 0)
    {
      top = temp;
    }
    else
    {
      temp->next = top;
      top = temp;
    }
    temp = 0;
    No_nodes++;
  }

  void Pop()
  {
    if (top != 0)
    {
      temp = top;
      top = top->next;
      delete temp;
      temp = 0;
      No_nodes--;
    }
    else
      cout << "\n Empty Stack";
  }

  void Clear()
  {
    cout << "\n Deleting the stack ";
    temp = top;
    Node *nextNode;
    while (temp != 0)
    {
      nextNode = temp->nextNode;
      delete temp;
      temp = nextNode;
    }
    top = temp = 0;
    No_nodes--;
  }

  void Display()
  {
    if (No_nodes > 0)
    {
      temp = top;
      while (temp != 0)
      {
        cout << temp->data << " ";
        temp = temp->next;
        cout << endl;
      }
    }
    else
      cout << "\n Empty Stack. ";
  }
};

int main()
{
  Stack_using_LinkedList *S = new Stack_using_LinkedList();
  int ch;
  do
  {
    system("clear");
    cout << setw(40) << setfill(' ') << "\n Singly Linked List ";
    cout << "\n Hello There!";
    cout << "\n Stack Operations using Linked List " << endl;
    cout << endl;
    S->Display();
    cout << "\n--- What Stack Operation do you want to Perform? Select Option Number.";
    cout << "\n 1. Push ";
    cout << "\n 2. Pop ";
    cout << "\n 3. Clean ";
    cout << "\n 4. Display ";
    cout << "\n 5. Quit ";
    cout << "\n Please enter your choice ";
    cin >> ch;
    switch (ch)
    {
    case 1:
      int x;
      cout << "\n Please enter the element ";
      cin >> x;
      S->Push(x);
      cout << "Push Stack Function Called - " << endl;
      break;
    case 2:
      S->Pop();
      cout << "Pop Stack Function Called - " << endl;
      break;
    case 3:
      cout << "Clean Stack Function Called - " << endl;
      S->Clear();
      break;
    case 4:
      cout << "Display Function Called - " << endl;
      S->Display();
      break;
    case 5:
      exit(0);
    default:
      cout << "\n Invalid Option ";
    }
  } while (ch != 4);
  delete S;
  return 0;
}

// Code written by Kushan Thakur
// the noob shinobi of CS
