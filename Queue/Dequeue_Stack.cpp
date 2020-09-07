#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "stack.h"
using namespace std;

class Queue
{
public:
  int *q;
  int size, front, rear;
  Stack<int> *s1;
  Stack<int> *s2;
  Queue(int size = 10)
  {
    front = rear = -1;
    this->size = size;
    s1 = new Stack<int>();
    s2 = new Stack<int>();
  }
  ~Queue()
  {
    delete s1;
    delete s2;
  }

  // Enqueue
  void Enqueue(int x)
  {
    if (rear == (size - 1))
    {
      cout << "\n Queue is full";
    }
    else if (front == -1 && rear == -1)
    {
      s1->push(x);
      front++;
      rear++;
    }
    else
    {
      s1->push(x);
      rear++;
    }
  }

  // Dequeue
  void Dequeue()
  {
    if (front == -1 && rear == -1)
    {
      cout << "\n Empty";
    }
    else if (front == rear)
    {
      front = rear = -1;
      cout << "\n Deleting " << s1->pop();
    }
    else
    {
      cout << "\n Deleting ";
      front++;
      while (s1->Top() != -1)
      {
        s2->push(s1->pop());
      }
      cout << s2->pop();
      while (s2->Top() != -1)
      {
        s1->push(s2->pop());
      }
    }
  }

  void Display()
  {
    cout << "\n Queue is -  ";
    s1->show();
  }
};

//Menu function
//Main function
int main()
{
  Queue *Q = new Queue();
  int ch;
  do
  {
    cout << setw(40) << setfill(' ') << "\n--- DeQueue Operations";
    cout << "\n Hello There!";
    cout << "\n--- What operation do you want to perform? Select Option Number.";
    cout << "\n 1. Enter Queue Data";
    cout << "\n 2. DeQueue Data";
    cout << "\n 3. Display Queue Data";
    cout << "\n 4. Quit";
    cout << "\n    Please enter your choice";
    cin >> ch;
    switch (ch)
    {
    case 1:
      int x;
      cout << "Enter value to be stored in queue: ";
      cin >> x;
      Q->Enqueue(x);
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
    default:
      cout << "\n Enter a valid choice!";
      break;
    }
  } while (ch != 4);
  delete Q;
  return 0;
}

// Code written by Kushan Thakur
// the noob shinobi of CS