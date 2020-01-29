// Stacks

#include<stack>
#include<vector>
using namespace std;

// Displays elements of the list
void displayList(vector<int> list){
    for(int element: list){
        cout<<"Element: "<<element<<"\n"; 
    }
}

// Pushes an element into the stack from the vector
void pushStack(vector<int> list, stack<int> & element_stack){
    cout<<"\n Pushing elements into the stack \n";
    for(int element: list){
        element_stack.push(element);
    }
}

// Displays the stack
void displayStack(stack<int> element_stack){
    cout<<"\n Displaying stack: \n";
    while(!element_stack.empty()){
        cout<<"Element: "<< element_stack.top()<<"\n";
        element_stack.pop();
    }
}

int main(){
    vector<int> list {1,2,3,5,6,7};
    stack<int> element_stack;
    displayList(list);
    pushStack(list, element_stack);
    displayStack(element_stack);
    return 0;
}
