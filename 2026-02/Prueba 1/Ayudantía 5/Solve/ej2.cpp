#include <iostream>
#include <string>
#include <queue>

using namespace std;

char primerNoRepetido(const string &s)
{
    int conteo[26] = {0};
    queue<char> q;

    for (char c : s)
    {
        if (c >= 'a' && c <= 'z')
        {
            conteo[c - 'a']++;
            q.push(c);
        }
    }

    while (!q.empty())
    {
        char c = q.front();
        q.pop();
        if (conteo[c - 'a'] == 1)
        {
            return c;
        }
    }
    return '0';
}

int main()
{
    cout << primerNoRepetido("holaamigo") << endl; // h
    cout << primerNoRepetido("aabbc") << endl;     // c
    cout << primerNoRepetido("aabb") << endl;      // 0 (ninguno)

    return 0;
}
