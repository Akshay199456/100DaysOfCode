/*
Problem statement:

Design a class that simulates a Stack data structure, implementing the following two operations:

push(int num): Pushes the number ‘num’ on the stack.
pop(): Returns the most frequent number in the stack. If there is a tie, return the number which was pushed later.
Example:

After following push operations: push(1), push(2), push(3), push(2), push(1), push(2), push(5)

1. pop() should return 2, as it is the most frequent number
2. Next pop() should return 1
3. Next pop() should return 2
*/

/*
-------------------------    My Approaches:
1. Tp K elements pattern

    to get the most frequent number, we can make use of a stack. for the condition of the tie, we need somehting unique that will allow us to lkeep track of which element was inerted the last so we make use of
    a count. we also use a custome comparator function and make use of tuple in the priority queuet to store each element.

    Time complexity: O(logn) for push and O(logn) for pop
    Space complexity: O(n) where n is the no of elements inserted
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes


    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)

using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

class FrequencyStack {
 public:
  struct valueCompare{
    char operator()(const tuple<int,int,int> &x, const tuple<int,int,int> &y){
      if(get<0>(y) == get<0>(x))
        return get<2>(y) > get<2>(x);
      return get<0>(y) > get<0>(x);
    }
  };


  priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, valueCompare> pq;
  unordered_map<int,int> frequencyCount;
  int count = 0;

  virtual void push(int num) {
    // TODO: Write your code here
    frequencyCount[num]++;
    pq.push(make_tuple(frequencyCount[num], num, count++));
  }

  virtual int pop() {
    // TODO: Write your code here
    tuple<int,int,int> tuplePair = pq.top();
    pq.pop();
    frequencyCount[get<1>(tuplePair)]--;
    return get<1>(tuplePair);
  }
};

int main(int argc, char *argv[]) {
  FrequencyStack frequencyStack;
  frequencyStack.push(1);
  frequencyStack.push(2);
  frequencyStack.push(3);
  frequencyStack.push(2);
  frequencyStack.push(1);
  frequencyStack.push(2);
  frequencyStack.push(5);
  cout << frequencyStack.pop() << endl;
  cout << frequencyStack.pop() << endl;
  cout << frequencyStack.pop() << endl;
}


//  Other Approaches(1)
