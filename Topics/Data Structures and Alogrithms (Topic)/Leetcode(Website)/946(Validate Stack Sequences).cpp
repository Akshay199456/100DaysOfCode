/*
-------------------------Question:

Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.

 

Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
Example 2:

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.
 

Constraints:

0 <= pushed.length == popped.length <= 1000
0 <= pushed[i], popped[i] < 1000
pushed is a permutation of popped.
pushed and popped have distinct values.

*/

/*
-------------------------    My Approaches:
1. Using a stack and set

We can use a stack and a set to solve this problem. Since we know that popped is a permutation of pushed, we need to align the elemnts such that we can check that the permutation can be created. We keep inserting elements into the stack
and set till the element at the top of the stack is th epopped element in the vector. At this point, we pop the element from the stack and move th epopped Ptr forward. As we are going through this process, if the element at the top of the
stack when we find that the popped elemnt has been inserted is not ht epopped elemnt in the array we return false. Similarly, we have already crossed the end of the pushed array and we are trying to insert an element since we can't fid 
the popped lement, we must return false as well. 

Time complexity: O(n)
Space complexity: O(n)
*/

/*
-------------------------    Other approaches:

*/

// My Approahces(1)
class Solution {
public:
    bool checkSequence(vector<int> pushed, vector<int> popped){
        unordered_set<int> elementSet;
        stack<int> elementStack;
        int pushedPtr = 0, poppedPtr = 0;
        while(poppedPtr < popped.size()){
            if(elementSet.find(popped[poppedPtr]) == elementSet.end()){
                if(pushedPtr == pushed.size())
                    return false;
                else{
                    elementSet.emplace(pushed[pushedPtr]);
                    elementStack.push(pushed[pushedPtr]);
                    pushedPtr++;
                }
            }
            else{
                if(elementStack.top() != popped[poppedPtr])
                    return false;
                else{
                    elementStack.pop();
                    poppedPtr++;   
                }
            }
        }
        return true;
    }
    
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(!pushed.size())
            return true;
        return checkSequence(pushed, popped);
    }
};