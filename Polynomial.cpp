#include <iostream>
using namespace std;

//Define the node
typedef struct CreatePolynomial
{
  double coefficient;
  double index;
  struct CreatePolynomial *next;
} Polynomial;

//Create a linked list
Polynomial *createPoly(int n)
{
  //Create head node
  Polynomial *head = new Polynomial;
  Polynomial *pre = head;
  for (int i = 0; i < n; i++)
  {
    //Create a new node
    Polynomial *poly = new Polynomial;
    //Assign a value to the node
    cout << "Please enter the coefficient and exponent of the term:";
    //The index entered by default is sorted from small to large
    cin >> poly->coefficient;
    cin >> poly->index;
    pre->next = poly;
    pre = poly;
    poly->next = NULL;
  }
  return head;
}

//Calculate the number of nodes (except the head node)
int lengthPolynomial(Polynomial *head)
{
  Polynomial *p = new Polynomial;
  int count = 0;
  p = head->next;
  while (p != NULL)
  {
    count++;
    p = p->next;
  }
  return count;
}

//Addition of two polynomials
Polynomial *addpolylist(Polynomial *poly1, Polynomial *poly2) //polynomial: polynomial
{
  int temp;
  Polynomial *first, *second, *third;
  //Store the sum of the polynomials in the first polynomial, so the final return is the head node of the first polynomial;
  first = poly1->next;
  second = poly2->next;
  third = poly1;
  while (first && second)
  {
    if (first->index < second->index)
    {
      third->next = first;
      first = first->next;
      third = third->next;
    }
    else if (first->index == second->index)
    {
      temp = first->coefficient + second->coefficient;
      if (temp)
      {
        first->coefficient = temp;
        third->next = first;
        first = first->next;
        second = second->next;
        third = third->next;
      }
      else
      {
        first = first->next;
        second = second->next;
      }
    }
    else
    {
      third->next = second;
      second = second->next;
      third = third->next;
    }
  }
  third->next = (first ? first : second);
  return poly1;
}

//Output the data field of each node
void display(Polynomial *head)
{
  Polynomial *p = head->next;
  while (p != NULL)
  {
    if (p->next != NULL)
    {
      if (p->next->coefficient < 0)
      {
        cout << p->coefficient << "x^" << p->index;
      }
      else
      {
        cout << p->coefficient << "x^" << p->index << "+";
      }
    }
    else
    {
      cout << p->coefficient << "x^" << p->index << endl;
    }
    p = p->next;
  }
}

//Main function entry
int main()
{
  Polynomial *poly1 = createPoly(2);
  Polynomial *poly2 = createPoly(2);
  cout << "The first polynomial is:" << endl;
  display(poly1);
  cout << "The second polynomial is:" << endl;
  display(poly2);
  Polynomial *poly = addpolylist(poly1, poly2);
  cout << "The result of polynomial addition is:" << endl;
  display(poly);
  return 0;
}
