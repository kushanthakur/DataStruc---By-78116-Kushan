#include <iostream>
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
            cout << "\n No Data ";
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

void Postfix_Eval(string s)
{
    Stack<int> S;
    for (int i = 0; i < s.length(); ++i)
    {
        if (isdigit(s[i]))
        {
            S.Push((int)s[i] - 48);
        }
        else if (s[i] == ' ')
        {
            i++;
            string temp;
            while (s[i] != ' ')
            {
                char c = s[i];
                temp += c;
                i++;
            }
            S.Push(stoi(temp));
        }
        else
        {
            int n1 = S.Pop();
            int n2 = S.Pop();
            switch (s[i])
            {
            case '+':
                S.Push(n2 + n1);
                break;
            case '-':
                S.Push(n2 - n1);
                break;
            case '*':
                S.Push(n2 * n1);
                break;
            case '/':
                S.Push(n2 / n1);
                break;
            }
        }
    }
    cout << S.Pop();
}

int main()
{
    cout << "\n Hello There!";
    cout << "\n Postfix Evaluation ";
    cout << endl;
    cout << "\n to enter more than one number press space instead of enter";
    string s;
    cout << "\n Please enter your expression ";
    getline(cin, s);
    Postfix_Eval(s);
    return 0;
}

// Code written by Kushan Thakur
// the noob shinobi of CS