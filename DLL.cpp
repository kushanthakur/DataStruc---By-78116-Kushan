#include <iostream>
#include <iomanip>
using namespace std;

template <class T>

class Node
{
public:
  int data;
  Node *next, *prev;

  Node(T data = 0, Node *next = 0, Node *prev = 0)
  {
    this->data = data;
    this->next = next;
    this->prev = prev;
  }
  ~Node()
  {
    this->data;
  }
};

template <class T>

class DoublyLinkedList
{
private:
  Node<T> *head, *tail, *temp;
  int No_nodes;

public:
  DoublyLinkedList()
  {
    head = tail = temp = 0;
    No_nodes = 0;
  }
  ~DoublyLinkedList()
  {
    temp = head;
    Node<T> *nextptr;
    cout << "\n Deleting the Linked List";
    while (temp != 0)
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
  void traverseNode();                 //to print the Linked List
  void locateNode();                   //to locateNode the Linked List
  void invertNode();                   //to reverse the Linked List
  int totalNode();                     // to count the total no. of nodes
  void operator+(DoublyLinkedList &s); //concatenation using operator overloading
};

template <class T>

int DoublyLinkedList<T>::totalNode()
{
  if (No_nodes == 0)
    return 0;
  else
    return No_nodes;
}

// Prepend Node - Attach a node at the start
template <class T>

void DoublyLinkedList<T>::prependNode()
{
  temp = new Node<T>();
  cout << "\n Enter the data for new node ";
  cin >> temp->data;
  temp->next = 0;
  if (head != 0)
  {
    head->prev = temp;
    temp->next = head;
    head = temp;
  }
  else
  {
    head = tail = temp;
  }
  temp = 0;
  No_nodes++;
}

// Append a node to the list
template <class T>

void DoublyLinkedList<T>::appendNode()
{
  temp = new Node<T>();
  cout << "\n Enter the data for new node ";
  cin >> temp->data;
  if (head != 0)
  {
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
  }
  else
  {
    head = tail = temp;
  }
  temp = 0;
  No_nodes++;
}

// Insert a Node after a particular node in the list
template <class T>

void DoublyLinkedList<T>::insertNode()
{
  //taking location input
  int loc;
  cout << "\n Enter the location ";
  cin >> loc;
  temp = new Node<T>();
  cout << "\n Enter the data for new node ";
  cin >> temp->data;
  if (loc < 0 || loc > No_nodes)
  {
    cout << "\n Invalid Location ";
  }
  else if (loc == 1)
  {
    head->prev = temp;
    temp->next = head;
    head = temp;
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
    temp->prev = reqNode;
    reqNode->next->prev = temp;
    reqNode->next = temp;
    No_nodes++;
  }
  temp = 0;
}

// Delete node at Beginning
template <class T>

void DoublyLinkedList<T>::del_begg_Node()
{
  if (No_nodes > 0)
  {
    temp = head;
    head = head->next;
    head->prev = 0;
    delete temp;
    temp = 0;
    No_nodes--;
  }
  else
    cout << "\n No Data to Delete ";
}

// Delete node at End
template <class T>

void DoublyLinkedList<T>::del_end_Node()
{
  if (No_nodes > 0)
  {
    if (head == tail)
    {
      delete head;
      head = tail = temp = 0;
      No_nodes--;
    }
    else
    {
      temp = tail;
      tail = tail->prev;
      tail->next = 0;
      temp = 0;
      No_nodes--;
    }
  }
  else
  {
    cout << "\n No data to delete";
  }
}

// Delete node at Location
template <class T>

void DoublyLinkedList<T>::del_at_loc()
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
    if (No_nodes == 1)
    {
      head = tail = 0;
    }
    else
    {
      head = head->next;
      head->prev = 0;
    }
    delete temp;
    temp = 0;
    No_nodes--;
  }
  else
  {
    int pointer = 1;
    temp = head;
    while (pointer != loc)
    {
      temp = temp->next;
      pointer++;
    }
    if (temp == tail)
    {
      tail = temp->prev;
      tail->next = 0;
    }
    else
    {
      temp->prev->next = temp->next;
      temp->next->prev = temp->prev;
    }
    delete temp;
    temp = 0;
    No_nodes--;
  }
}

// traverse Node
template <class T>

void DoublyLinkedList<T>::traverseNode()
{
  if (head == 0)
  {
    cout << "\n Empty List ";
  }
  else
  {
    cout << "\n Here's the List : ";
    temp = head;
    while (temp != 0)
    {
      cout << temp->data << "  ";
      temp = temp->next;
    }
    cout << endl;
    temp = 0;
  }
}

// locate Node
template <class T>

void DoublyLinkedList<T>::locateNode()
{
  if (totalNode() > 0)
  {
    int value;
    int pointer = 1;
    cout << "\n Enter the Node data you want to search ";
    cin >> value;
    temp = head;
    while (temp != 0)
    {
      if (temp->data == value)
      {
        cout << "\n Data at  - " << pointer;
        return;
      }
      temp = temp->next;
      pointer++;
    }
    cout << "\n Data not Found ";
  }
  else
  {
    cout << "\n Empty List ";
  }
}

// Reverse Node
template <class T>

void DoublyLinkedList<T>::invertNode()
{
  if (totalNode() > 0)
  {
    temp = head;
    Node<T> *next2 = 0;
    while (temp != 0)
    {
      next2 = temp->next;
      temp->next = temp->prev;
      temp->prev = next2;
      temp = next2;
    }
    temp = tail;
    tail = head;
    head = temp;
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
  DoublyLinkedList<int> *D = new DoublyLinkedList<int>();

  char ch;
  int a;
  do
  {
    system("clear");

    cout << setw(40) << setfill(' ') << "\n Doubly Linked List ";
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
      D->prependNode();
      break;
    case 2:
      cout << "Append Node Operation" << endl;
      D->appendNode();
      break;
    case 3:
      cout << "Insert Node Operation" << endl;
      D->insertNode();
      break;
    case 4:
      cout << "Delete Node Operation" << endl;
      D->del_begg_Node();
      break;
    case 5:
      cout << "Delete Node Operation" << endl;
      D->del_end_Node();
      break;
    case 6:
      cout << "Delete Node Operation" << endl;
      D->del_at_loc();
      break;
    case 7:
      cout << "Invert Node Operation" << endl;
      D->invertNode();
      break;
    case 8:
      cout << "Locate Node Operation" << endl;
      D->locateNode();
      break;
    case 9:
      cout << "Traverse Node Operation" << endl;
      D->traverseNode();
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
  delete D;
  return 0;
}

// Code written by Kushan Thakur
// the noob shinobi of CS