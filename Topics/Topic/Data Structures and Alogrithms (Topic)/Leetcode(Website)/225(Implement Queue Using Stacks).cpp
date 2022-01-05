/*
-------------------------Question:

Implement a last in first out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal queue (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue), as long as you use only a queue's standard operations.
 

Example 1:

Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
 

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, top, and empty.
All the calls to pop and top are valid.
 

Follow-up: Can you implement the stack such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer. You can use more than two queues.
*/

/*
-------------------------    My Approaches:
1. usign two queues

we can use two queues in order to implement the functionaliy of a stack. since we can only pop from the front of the queue, we will need to completely empty it till we have the size 1 which is the element we will need to pop and return.
As a result, pop has O(n) for its time complexity while the rest have O(1) time complexity.

Time complexity: O(1) except O(n) for pop
Space complexity: O(n)
*/

/*
-------------------------    Other approaches:

*/

// MY Approaches(1)
class MyStack {
public:
    queue<int> primaryQueue, secondaryQueue;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(!primaryQueue.empty())
            primaryQueue.push(x);
        else
            secondaryQueue.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(!primaryQueue.empty())
            return transferElements(primaryQueue, secondaryQueue);
        else
            return transferElements(secondaryQueue, primaryQueue);
    }
    
    /** Get the top element. */
    int top() {
        if(!primaryQueue.empty())
            return primaryQueue.back();
        else
            return secondaryQueue.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return primaryQueue.empty() && secondaryQueue.empty();
    }
    
    int transferElements(queue<int> & mainQueue, queue<int> & sideQueue){
        while(mainQueue.size() != 1){
            sideQueue.push(mainQueue.front());
            mainQueue.pop();
        }
        
        int value = mainQueue.front();
        mainQueue.pop();
        return value;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */