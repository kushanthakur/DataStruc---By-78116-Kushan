#include <iostream>
using namespace std;

template <class T>
class LowTri
{
private:
    int size;
    T *l;

public:
    LowTri(int size)
    {
        this->size = size;
        if (size > 0)
        {
            size = ((size + 1) * size) / 2;
            l = new T[size];
            for (int i = 0; i < size; i++)
            {
                l[i] = 0;
            }
        }
        else
        {
            l = 0;
        }
    }
    ~LowTri()
    {
        delete[] l;
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            for (int j = 1; j <= size; j++)
            {
                if (i >= j)
                {
                    int k = (i * (i - 1)) / 2 + j;
                    cout << l[k - 1] << " ";
                }
                else
                {
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
    }

    void insert(int i, int j)
    {
        if ((i <= size) && (j <= size))
        {
            if (i >= j)
            {
                T x = 0;
                cout << "Enter value : ";
                cin >> x;
                int k = (i * (i - 1)) / 2 + j;
                l[k - 1] = x;
            }
        }
        else
        {
            cout << "Out of Bound.\n";
            return;
        }
    }

    int retrieve(int i, int j)
    {
        if (i <= size && j <= size)
        {
            if (i >= j)
            {
                int k = (i * (i - 1)) / 2 + j;
                return l[k - 1];
            }
        }
        return 0;
    }
};

int main()
{
    int size;
    int ch;
    cout << "\n------Lower Triangle------";
    cout << "\n Please enter size of matrix ";
    cin >> size;
    LowTri<int> *L = new LowTri<int>(size);
    do
    {
        int i = 0;
        int j = 0;
        cout << "\n 1. Insert ";
        cout << "\n 2. Retrieve ";
        cout << "\n 3. Print Matrix ";
        cout << "\n 4. Exit";
        cout << "\n Please enter your choice ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\n Enter Index ";
            cin >> i >> j;
            L->insert(i, j);
            break;
        case 2:
            cout << "\n Enter Index ";
            cin >> i >> j;
            L->retrieve(i, j);
            break;
        case 3:
            L->print();
            break;
        default:
            if (ch != 4)
                cout << "\n Invalid choice";
            break;
        }
    } while (ch != 4);
    return 0;
}
