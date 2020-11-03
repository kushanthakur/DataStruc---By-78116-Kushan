#include <iostream>
using namespace std;

template <class T>
class DiaMat
{
private:
  int size = 10;
  T *d;

public:
  DiaMat(int size)
  {
    this->size = size;
    if (size > 0)
    {
      d = new T[size];
      for (int i = 0; i < size; i++)
      {
        d[i] = 0;
      }
    }
    else
    {
      d = 0;
    }
  }

  ~DiaMat()
  {
    delete[] d;
  }
  void store(int i, int j)
  {
    if ((i <= size) && (j <= size))
    {
      if (i == j)
      {
        T x = 0;
        cout << "\n enter value :";
        cin >> x;
        d[i - 1] = x;
      }
    }
    else
    {
      cout << "\n Out of Bound.";
      return;
    }
  }

  int retrieve(int i, int j)
  {
    if (i <= size && j <= size)
    {
      if (i == j)
      {
        return d[i - 1];
      }
    }
    return 0;
  }

  void print()
  {
    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {
        if (i == j)
        {
          cout << d[i] << " ";
        }
        else
        {
          cout << 0 << " ";
        }
      }
      cout << "\n";
    }
  }
};

int main()
{
  int size;
  int ch;
  cout << "\n Please enter size of the matrix  ";
  cin >> size;
  DiaMat<int> *D = new DiaMat<int>(size);
  do
  {
    int i = 0;
    int j = 0;
    cout << "\n 1. Insert";
    cout << "\n 2. Retrieve";
    cout << "\n 3. Print Matrix";
    cout << "\n 4. Exit";
    cout << "\n Please Enter your choice: ";
    cin >> ch;
    switch (ch)
    {
    case 1:
      cout << "\n Enter Index ";
      cin >> i >> j;
      D->store(i, j);
      break;
    case 2:
      cout << "\n Enter Index ";
      cin >> i >> j;
      D->retrieve(i, j);
      break;
    case 3:
      D->print();
      break;
    default:
      if (ch != 4)
        cout << "\n Invalid choice";
      break;
    }
  } while (ch != 4);
  return 0;
}