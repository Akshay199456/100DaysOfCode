/*
-------------------------Question:

Given a number n, write a function that generates and prints all binary numbers with decimal values from 1 to n. 

Examples: 

Input: n = 2
Output: 1, 10

Input: n = 5
Output: 1, 10, 11, 100, 101

*/

/*
-------------------------    My Approaches:

*/

/*
-------------------------    Other approaches:
1. Uisng a queue

We can use a queue to generate the sequence. If we observe, all there is to this is to keep adding "0" and "1" to each number and push and pop from the queue. This way, when we get to each  number, we are filling for numbers in the next layer
(adding another digit) while the current queu contians numbers in this layer which we can use to print out in order. We add the "0" before the "1" because "0" occurs first before "1" in each number.

Time complexity: O(n)
Space complexity: O(n)
*/

// Other Approaches(1)
#include <iostream>
#include <queue>
using namespace std;

void generateNumbers(int n){
  queue<string> elements;
  elements.push("1");

  for(int i=1; i<=n; i++){
    cout<<"Number: "<<i<<" Binary rep: "<<elements.front()<<endl;
    elements.push(elements.front() + "0");
    elements.push(elements.front() + "1");
    elements.pop();
  }
}

int main() {
  std::cout << "Hello World!\n";
  int n =16;
  generateNumbers(n);
}