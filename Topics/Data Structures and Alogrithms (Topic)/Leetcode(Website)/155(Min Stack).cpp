/*
-------------------------Question:

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

*/

/*
-------------------------My Approaches:

1. Using 2 stacks.

We can use 2 stacks to perform the operations and retrieve the min element in the stack.


Overall time complexity: O(1)
Overall space complextity: O(n)

*/

/*
-------------------------Other approaches

*/




// My Approches(1)
class MinStack {
public:
    stack<int> elementStack, minStack;
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        elementStack.push(x);
        if(minStack.size() == 0 || x <= minStack.top())
            minStack.push(x);
    }
    
    void pop() {
        int poppedElement = elementStack.top();
        if(poppedElement == minStack.top())
            minStack.pop();
        elementStack.pop();
    }
    
    int top() {
        return elementStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */