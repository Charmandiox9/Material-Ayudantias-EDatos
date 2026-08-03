#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool validateParentheses(const char* expr) {
        stack<char> s;

        for (const char* curr = expr; *curr != '\0'; ++curr) {
            char c = *curr;

            switch (c) {
                case '(': case '[': case '{':
                    s.push(c);
                    break;

                case ')':
                    if (s.empty() || s.top() != '(') return false;
                    s.pop();
                    break;
                case ']':
                    if (s.empty() || s.top() != '[') return false;
                    s.pop();
                    break;
                case '}':
                    if (s.empty() || s.top() != '{') return false;
                    s.pop();
                    break;

                default:
                    break;
            }
        }

        return s.empty();
    }
};


int main() {
    Solution sol;

    char expr1[] = "(3 + [4 * {2 - 1}])";
    char expr2[] = "([)]";
    char expr3[] = "{[()]}";

    cout << sol.validateParentheses(expr1) << endl;
    cout << sol.validateParentheses(expr2) << endl;
    cout << sol.validateParentheses(expr3) << endl;
    return 0;
}
