#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
class Stack
{
private:
  T S[10];
  int size = 10;
  int top = -1;

public:
  void Push(T x)
  {
    if (top != (size - 1))
    {
      top++;
      S[top] = x;
    }
    else
      cout << "\n Stack is full ";
  }

  T Pop()
  {
    if (top != -1)
      return S[top--];
    else
      cout << "\n Stack is empty ";
  }
  int Top()
  {
    return top;
  }

  void Display()
  {
    if (top != -1)
    {
      for (int i = 0; i <= top; ++i)
      {
        cout << S[i] << " ";
      }
    }
    else
    {
      cout << "No Data";
    }
  }
};

void Add(string x, string y)
{
  int carry = 0, sum = 0, i = 0;
  Stack<int> a, b;

  while (i != x.length())
  {
    string temp = "";
    temp += x[i];
    a.Push(stoi(temp));
    i++;
  }
  i = 0;
  while (i != y.length())
  {
    string temp = "";
    temp += y[i];
    b.Push(stoi(temp));
    i++;
  }
  Stack<int> c;
  while (a.Top() != -1 || b.Top() != -1)
  {
    sum = carry + a.Pop() + b.Pop();
    carry = sum / 10;
    sum = sum % 10;
    c.Push(sum);
    sum = 0;
  }
  if (carry != 0)
    c.Push(carry);
  while (c.Top() != -1)
  {
    i = c.Pop();
    cout << i;
  }
}

int main()
{
  system("clear");
  string x, y;

  cout << "\n Summation of two Big Integers " << endl;
  cout << "\n Please enter the first integer ";
  getline(cin, x);
  cout << "\n Please enter the second integer ";
  getline(cin, y);
  cout << "\n Summation of the given integers = ";
  Add(x, y);
  return 0;
}

// Code written by Kushan Thakur
// the noob shinobi of CS