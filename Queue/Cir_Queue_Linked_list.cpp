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
  Node(int data, Node *next)
  {
    this->data = data;
    this->next = next;
  }
  //destructor
  ~Node()
  {
    cout << " Deleted " << this->data << "\n";
  }
};

class CirQue
{
private:
  Node *front, *rear, *temp;
  int No_nodes;

public:
  //constructor
  CirQue()
  {
    front = rear = temp = 0;
    No_nodes = 0;
  }
  //destructor
  ~CirQue()
  {
    temp = front;
    Node *nextPtr = 0;
    while (temp->next != front)
    {
      nextPtr = temp->next;
      delete temp;
      temp = nextPtr;
    }
    temp = nextPtr = 0;
    cout << "Complete\n";
  }
  //Functions
  //Enqueue element in stack
  void Enqueue(int x);
  void Dequeue();
  void Front();
  int Empty();
  void Display();
};

int CirQue ::Empty()
{
  if (No_nodes == 0)
    return 1;
  return 0;
}

//Functions
//Enqueue element in stack
void CirQue ::Enqueue(int x)
{
  temp = new Node(x, 0);
  if (rear == 0)
  {
    front = rear = temp;
    rear->next = front;
  }
  else
  {
    rear->next = temp;
    rear = temp;
    temp->next = front;
  }
  temp = 0;
  No_nodes++;
}

// Dequeue first element in a queue
void CirQue ::Dequeue()
{
  if (Empty())
  {
    cout << "\n Queue is Empty";
  }
  else
  {
    if (front == rear)
    {
      temp = front;
      front = rear = 0;
    }
    else
    {
      temp = front;
      front = front->next;
      rear->next = front;
    }
    delete temp;
    temp = 0;
    No_nodes--;
  }
}

void CirQue ::Front()
{
  if (!Empty())
  {
    cout << front->data << "\n";
  }
}

void CirQue ::Display()
{
  if (!Empty())
  {
    temp = front;
    do
    {
      cout << temp->data << " ";
      temp = temp->next;
    } while (temp != front);
    cout << "\n";
    temp = 0;
  }
  else
  {
    cout << "\n Queue is empty";
  }
}

//Menu function
//Main function
int main()
{
  CirQue *Q = new CirQue();
  int ch;
  char c;
  do
  {
    cout << setw(40) << setfill(' ') << "\n--- Circular Queue Using Linked List";
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
