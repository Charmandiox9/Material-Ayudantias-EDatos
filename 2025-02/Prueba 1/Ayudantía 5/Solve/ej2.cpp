#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> reverseQueue(queue<int> &q) {
        stack<int> aux;
        
        do {
            aux.push(q.front());
            q.pop();
        } while(!q.empty());
        
        while(!aux.empty()){
            q.push(aux.top());
            aux.pop();
        }
        
        
        return q;
}


int main() {
    queue<int> q;
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);
    q.push(25);
   
    reverseQueue(q);
    
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}