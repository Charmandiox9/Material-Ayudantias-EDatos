#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

class Solution {
public:
    class Queue {
    private:
        stack<int> input;
        stack<int> output;

        void _shift() {
            if (output.empty()) {
                while (!input.empty()) {
                    output.push(input.top());
                    input.pop();
                }
            }
        }

    public:
        void enqueue(int val) {
            input.push(val);
        }

        int dequeue() {
            _shift();
            if (output.empty()) {
                throw runtime_error("Queue is empty");
            }
            int val = output.top();
            output.pop();
            return val;
        }

        int peek() {
            _shift();
            if (output.empty()) {
                throw runtime_error("Queue is empty");
            }
            return output.top();
        }

        bool isEmpty() {
            return input.empty() && output.empty();
        }
    };
};

int main() {
    Solution::Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Peek: " << q.peek() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl; 
    cout << "Peek: " << q.peek() << endl;       

    return 0;
}