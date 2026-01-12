#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int> &st) {
        stack<int> aux;
        
        while(!st.empty()){
            int temp = st.top(); //Toma el elemento superior de la pila original
            st.pop(); //Lo elimina de la pila original
            
            // Mueve elementos menores de aux de vuelta a st
            while(!aux.empty() && aux.top() < temp){
                st.push(aux.top());
                aux.pop();
            }
            
            aux.push(temp); // Coloca temp en su posición correcta en aux
            
        }
        
        while(!aux.empty()){
            cout<<aux.top()<<" ";
            aux.pop();
        }
}


int main()
{
    stack<int> input;
    input.push(34);
    input.push(3);
    input.push(31);
    input.push(98);
    input.push(92);
    input.push(23);
    
    sortStack(input);

}