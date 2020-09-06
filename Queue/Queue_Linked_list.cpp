#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

// Define node pointer
class Node
{
public:
  int data;
  Node *next;
  //constructor
  Node(int data, Node *nextNode)
  {
    this->data = data;
    this->next = nextNode;
  }
  //destructor
  ~Node()
  {
    cout << "deleting" << this->data;
  }
};

class Queue
{
private:
  Node *head, *tail, *temp;
  int No_nodes;

public:
  //constructor
  Queue()
  {
    head = tail = temp = 0;
    No_nodes = 0;
  }

  //destructor
  ~Queue()
  {
    temp = head;
    Node *nextPtr = 0;
    while (temp != 0)
    {
      nextPtr = temp->next;
      delete temp;
      temp = nextPtr;
    }
    temp = nextPtr = 0;
  }

  //Functions
  //Enqueue element in stack
  void Enqueue(int x)
  {
    temp = new Node(x, 0);
    if (tail == 0)
    {
      head = tail = temp;
    }
    else
    {
      tail->next = temp;
      tail = temp;
    }
    temp = 0;
    No_nodes++;
  }

  // Dequeue first element in a queue
  void Dequeue()
  {
    if (No_nodes == 0)
    {
      cout << "\n Queue is Empty";
    }
    else
    {
      if (head == tail)
      {
        temp = head;
        head = tail = 0;
      }
      else
      {
        temp = head;
        head = head->next;
      }
      cout << temp->data;
      delete temp;
      temp = 0;
      No_nodes--;
    }
  }

  //Display the data
  void Display()
  {
    if (No_nodes > 0)
    {
      temp = head;
      while (temp != 0)
      {
        cout << temp->data << " ";
        temp = temp->next;
      }
      cout << endl;
      temp = 0;
    }
    else
    {
      cout << "\n Queue is empty";
    }
  }
};

//Menu function
//Main function
int main()
{
  Queue *Q = new Queue();
  int ch;
  char c;
  do
  {
    cout << setw(40) << setfill(' ') << "\n--- Linear Queue Using Linked List";
    cout << "\n Hello There!";
    cout << "\n--- What operation do you want to perform? Select Option Number.";
    cout << "\n 1. Enter Queue Data";
    cout << "\n 2. Delete Queue Data";
    cout << "\n 3. Display Queue Data";
    cout << "\n 4. Quit";
    cout << "\n    Please enter your choice";
    cin >> ch;
    switch (ch)
    {
    case 1:
      int temp;
      cout << "Enter value to be stored in queue: ";
      cin >> temp;
      Q->Enqueue(temp);
      cout << "Enqueue Function Called - " << endl;
      break;

    case 2:
      Q->Dequeue();
      cout << "Dequeue Function Called - " << endl;
      break;

    case 3:
      Q->Display();
      cout << "Display Function Called - " << endl;
      break;
    case 4:
      exit(0);
    default:
      cout << "\n Enter a valid choice!";
      break;
    }
    cout << "\n Again(y/n)";
    cin >> c;
  } while (c == 'y');
  delete Q;
  return 0;
}

// Code written by Kushan Thakur
// the noob shinobi of CS