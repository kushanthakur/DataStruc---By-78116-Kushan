#include <iostream>
#include <iomanip>
using namespace std;

template <class T>

class Node
{
public:
  int data;
  Node *next;

  Node(T data = 0, Node *next = 0)
  {
    this->data = data;
    this->next = next;
  }
  ~Node()
  {
    this->data;
  }
};

template <class T>

class CircularLinkedList
{
private:
  Node<T> *head, *temp;
  int No_nodes;

public:
  CircularLinkedList()
  {
    head = temp = 0;
    No_nodes = 0;
  }
  ~CircularLinkedList()
  {
    temp = head;
    Node<T> *nextptr;
    cout << "\n Deleting the Linked List";
    while (temp->next != head)
    {
      nextptr = temp->next;
      delete temp;
      temp = nextptr;
    }
  }
  //Functions for Linked list
  void appendNode();
  void prependNode();
  void insertNode();
  void del_end_Node();
  void del_begg_Node();
  void del_at_loc();
  void traverseNode();                   //to print the Linked List
  void locateNode();                     //to locate the Linked List
  void invertNode();                     //to reverse the Linked List
  int totalNode();                       // to count the total no. of nodes
  void operator+(CircularLinkedList &s); //concatenation using operator overloading
};

// Prepend Node - Attach a node at the start
template <class T>

void CircularLinkedList<T>::prependNode()
{
  temp = new Node<T>();
  cout << "\n Enter the data for new node ";
  cin >> temp->data;
  if (head == 0)
  {
    head = temp;
    head->next = head;
    temp = 0;
  }
  else
  {
    Node<T> *tail = head;
    while (tail->next != head)
    {
      tail = tail->next;
    }
    temp->next = head;
    head = tail;
    tail->next = head;
    temp = tail = 0;
  }
  No_nodes++;
}

// Append a node to the list
template <class T>

void CircularLinkedList<T>::appendNode()
{
  temp = new Node<T>();
  cout << "\n Enter the data for new node ";
  cin >> temp->data;
  if (head == 0)
  {
    head = temp;
    head->next = head;
    temp = 0;
  }
  else
  {
    Node<T> *tail = head;
    while (tail->next != head)
    {
      tail = tail->next;
    }
    tail->next = temp;
    tail->next->next = head;
    temp = tail = 0;
  }
  No_nodes++;
}

// Insert a Node after a particular node in the list
template <class T>

void CircularLinkedList<T>::insertNode()
{
  //taking location input
  int loc;
  cout << "\n Enter the location ";
  cin >> loc;
  temp = new Node<T>();
  cout << "\n Enter the data for new node ";
  cin >> temp->data;
  temp->next = 0;
  if (loc < 0 || loc > No_nodes)
  {
    cout << "\n Invalid Location ";
  }
  else if (loc == 1)
  {
    Node<T> *tail = head;
    while (tail->next = 0)
    {
      tail = tail->next;
    }
    temp->next = head;
    head = temp;
    tail->next = head;
    tail = temp = 0;
    No_nodes++;
  }
  else
  {
    int pointer = 1;
    Node<T> *reqNode = head;
    //jumping to the node of given location
    while (pointer != (loc - 1))
    {
      reqNode = reqNode->next;
      pointer++;
    }
    //connecting to temp in the list
    temp->next = reqNode->next;
    reqNode->next = temp;
    reqNode = temp = 0;
    No_nodes++;
  }
}

// Delete node at Beginning
template <class T>

void CircularLinkedList<T>::del_begg_Node()
{
  if (No_nodes > 0)
  {
    if (head->next == head)
    {
      temp = head;
      delete temp;
      head = temp = 0;
    }
    else
    {
      Node<T> *tail = head;
      while (tail->next != head)
      {
        tail = tail->next;
      }
      temp = head;
      head = head->next;
      tail->next = head;
      delete temp;
      temp = 0;
    }
    No_nodes--;
  }
  else
    cout << "\n No Data to Delete ";
}

// Delete node at End
template <class T>

void CircularLinkedList<T>::del_end_Node()
{
  if (No_nodes > 0)
  {
    if (head->next == head)
    {
      temp = head;
      delete temp;
      head = temp = 0;
    }
    else
    {
      temp = head;
      while (temp->next->next != head)
      {
        temp = temp->next;
      }
      delete temp->next;
      temp->next = head;
      temp = 0;
    }
    No_nodes--;
  }
  else
  {
    cout << "\n No data to delete";
  }
}

// Delete node at Location
template <class T>

void CircularLinkedList<T>::del_at_loc()
{
  int loc;
  //taking location input
  cout << "\n Enter the location address you want to delete the node at";
  cin >> loc;
  if (loc < 0 || loc > No_nodes)
  {
    cout << "\n Invalid Location address ";
  }
  else if (loc == 1)
  {
    temp = head;
    Node<T> *tail = head;
    while (tail->next != head)
    {
      tail = tail->next;
    }
    if (No_nodes == 1)
    {
      head = 0;
    }
    else
    {
      head = head->next;
      tail->next = head;
    }
    delete temp;
    No_nodes--;
  }
  else
  {
    int pointer = 1;
    Node<T> *reqNode = head;
    //jumping to the node of given location
    while (pointer != (loc - 1))
    {
      reqNode = reqNode->next;
      pointer++;
    }
    temp = reqNode->next;
    if (temp->next == head)
    {
      reqNode->next = head;
    }
    reqNode->next = temp->next;
    delete temp;
    temp = reqNode = 0;
    No_nodes--;
  }
}

// traverse Node
template <class T>

void CircularLinkedList<T>::traverseNode()
{
  if (head == 0)
  {
    cout << "\n Empty List ";
  }
  else
  {
    cout << "\n Here's the List : ";
    temp = head;
    do
    {
      cout << temp->data << "  ";
      temp = temp->next;
    } while (temp != head);
    cout << endl;
    temp = 0;
  }
}

// locate Node
template <class T>

void CircularLinkedList<T>::locateNode()
{
  if (No_nodes > 0)
  {
    int value;
    int pointer = 1;
    cout << "\n Enter the Node data you want to search ";
    cin >> value;
    temp = head;
    do
    {
      if (temp->data == value)
      {
        cout << "\n Data at  - " << pointer;
        return;
      }
      temp = temp->next;
      pointer++;
    } while (temp != head);
    cout << "\n Data not Found ";
  }
  else
  {
    cout << "\n Empty List ";
  }
}

// Reverse Node
template <class T>

void CircularLinkedList<T>::invertNode()
{
  if (No_nodes > 0)
  {
    temp = head;
    Node<T> *prev = 0;
    Node<T> *next2 = 0;
    do
    {
      next2 = temp->next;
      temp->next = prev;
      prev = temp;
      temp = next2;
    } while (temp != head);
    head->next = prev;
    head = prev;
    temp = 0;
  }
  else
  {
    cout << "\n Empty List ";
  }
}

int main()
{
  system("clear");
  CircularLinkedList<int> *C = new CircularLinkedList<int>();

  char ch;
  int a;
  do
  {
    system("clear");

    cout << setw(40) << setfill(' ') << "\n Circular Linked List ";
    cout << "\n Hello There!";
    cout << "\n--- What operation do you want to perform? Select Option Number.";
    cout << "\n 1.  Prepend Node ";
    cout << "\n 2.  Append Node ";
    cout << "\n 3.  Insert at location ";
    cout << "\n 4.  Delete at start of list ";
    cout << "\n 5.  Delete at end of list ";
    cout << "\n 6.  Delete at some location of list ";
    cout << "\n 7.  Reverse the list ";
    cout << "\n 8.  Search data in the list ";
    cout << "\n 9.  Traverse ";
    cout << "\n 10. Quit ";
    cout << "\n Please enter your choice: ";
    cin >> a;

    switch (a)
    {
    case 1:
      cout << "Prepend Node Operation" << endl;
      C->prependNode();
      break;
    case 2:
      cout << "Append Node Operation" << endl;
      C->appendNode();
      break;
    case 3:
      cout << "Insert Node Operation" << endl;
      C->insertNode();
      break;
    case 4:
      cout << "Delete Node Operation" << endl;
      C->del_begg_Node();
      break;
    case 5:
      cout << "Delete Node Operation" << endl;
      C->del_end_Node();
      break;
    case 6:
      cout << "Delete Node Operation" << endl;
      C->del_at_loc();
      break;
    case 7:
      cout << "Invert Node Operation" << endl;
      C->invertNode();
      break;
    case 8:
      cout << "Locate Node Operation" << endl;
      C->locateNode();
      break;
    case 9:
      cout << "Traverse Node Operation" << endl;
      C->traverseNode();
      break;
    case 10:
      cout << "Exiting :D \n";
      exit(0);
    }
    cout << "\n Do you want to enter another data? (y/n) ";
    cin >> ch;
    if (ch == 'n')
      cout << "\n Exiting :D";
  } while (ch == 'y');
  delete C;
  return 0;
}

// Code written by Kushan Thakur
// the noob shinobi of CS
