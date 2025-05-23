/*
-------------------------Question:

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.

 

Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
 

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.
*/

/*
-------------------------    My Approaches:
1. Using two stacks.

We can use two stacks to perform the operation in O(1) amortized time. Push and empty operations are easy. We only push to the primary stack while fro empty, we must check if both the stacks are empty.

For pop, if the secondary stack is empty, we pop all the elemnents from the primary stack and push it into the secondary stack so that the nexdt pop operations can be done from the seconbdary stack. 

For peek, it's kind of the same thing. When we want to peek and the secondary stack is empty, we empty the primary stack into the secondary stack and give the elemnt at the top of the secondary stack.

Time complexity of operations: O(1)
Space complexity: O(1)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class MyQueue {
public:
    stack<int> primaryStack, secondaryStack;
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        primaryStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(secondaryStack.empty())
            adjustStacks(primaryStack, secondaryStack);
        
        int value = secondaryStack.top();
        secondaryStack.pop(); 
        return value;
    }
    
    /** Get the front element. */
    int peek() {
        if(secondaryStack.empty())
            adjustStacks(primaryStack, secondaryStack);
        
        return secondaryStack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return primaryStack.empty() && secondaryStack.empty();
    }
    
    void adjustStacks(stack<int> & primaryStack, stack<int> & secondaryStack){
        while(!primaryStack.empty()){
            secondaryStack.push(primaryStack.top());
            primaryStack.pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */