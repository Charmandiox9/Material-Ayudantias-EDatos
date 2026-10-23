#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool coincide(char apertura, char cierre)
{
    return (apertura == '(' && cierre == ')') ||
           (apertura == '[' && cierre == ']') ||
           (apertura == '{' && cierre == '}');
}

bool esApertura(char c)
{
    return c == '(' || c == '[' || c == '{';
}

bool esCierre(char c)
{
    return c == ')' || c == ']' || c == '}';
}

bool parentesisBalanceados(const string &expr)
{
    stack<char> pila;
    for (char c : expr)
    {
        if (esApertura(c))
        {
            pila.push(c);
        }
        else if (esCierre(c))
        {
            if (pila.empty())
                return false;
            char tope = pila.top();
            pila.pop();
            if (!coincide(tope, c))
                return false;
        }
    }
    return pila.empty();
}

int main()
{
    cout << parentesisBalanceados("(a+b)*(c-d)") << endl; // 1
    cout << parentesisBalanceados("((a+b)") << endl;      // 0
    cout << parentesisBalanceados("a(b[c]d)e") << endl;   // 1
    cout << parentesisBalanceados("(a+b]") << endl;       // 0
    cout << parentesisBalanceados("") << endl;            // 1

    return 0;
}
