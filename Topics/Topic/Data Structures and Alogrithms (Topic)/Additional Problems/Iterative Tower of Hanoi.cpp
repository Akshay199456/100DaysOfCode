/*
-------------------------Question:

Tower of Hanoi is a mathematical puzzle. It consists of three poles and a number of disks of different sizes which can slide onto any poles. The puzzle starts with the disk in a neat stack in ascending order of size in one pole, the smallest at the top thus making a conical shape. The objective of the puzzle is to move all the disks from one pole (say ‘source pole’) to another pole (say ‘destination pole’) with the help of the third pole (say auxiliary pole).

The puzzle has the following two rules:
      1. You can’t place a larger disk onto smaller disk 
      2. Only one disk can be moved at a time

We’ve already discussed recursive solution for Tower of Hanoi. We have also seen that, for n disks, total 2n – 1 moves are required. 
*/

/*
-------------------------    My Approaches:

*/

/*
-------------------------    Other approaches:

If n is even, we need to swap the destinmation stack and aux stack as following the rules for odd would deposit the final result into the aux stack.
If the remainder is 1, we swap discs between source and destination stack. For remainder 2, change between source and auxiliary and for remainderd 0, change between aux and destination stack.

Time complexity: O(n)
Space complexity: O(n) 
*/

// Other Approaches(1)
#include <iostream>
#include <stack>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int getTotalMoves(int n){
  return (int) pow(2,n) - 1;
}

void shiftDiscs(stack<int> & firstStack, stack<int> & secondStack, char firstName, char secondName){
  if(firstStack.top() < secondStack.top()){
    secondStack.push(firstStack.top());
    firstStack.pop();
    cout<<"Moving from "<<firstName<<" to "<<secondName<<endl;
  }
  else{
    firstStack.push(secondStack.top());
    secondStack.pop();
    cout<<"Moving from "<<secondName<<" to "<<firstName<<endl;
  }
}

void performTower(stack<int> & source, stack<int> & aux, stack<int> & destination, int totalMoves){
  for(int i=1; i<=totalMoves; i++){
    if(i%3 == 1)
      shiftDiscs(source, destination,'S', 'D');
    else if(i%3 == 2)
      shiftDiscs(source, aux, 'S', 'A');
    else
      shiftDiscs(aux, destination, 'A', 'D');
  }
}

void displayDestination(stack<int> destination){
  vector<int> list;

  // disply stack till size is not 1
  while(destination.size() != 1){
    cout<<destination.top()<<" ";
    destination.pop();
  }
  cout<<endl;
}

void fillSource(stack<int> & source, int n){
  for(int i=n; i>=1; i--)
    source.push(i);
}

int main() {
  stack<int> source, aux, destination;
  int n = 3;
  int totalMoves = getTotalMoves(n);

  cout<<"Number of discs: "<<n<<" Total number of moves: "<<totalMoves<<"\n\n";
  
  // fill with values initially to make it easy to compare stacks
  source.push(INT_MAX);
  aux.push(INT_MAX);
  destination.push(INT_MAX);
  
  // fill source with all discs 
  fillSource(source, n);
  // perform tower of hanoi
  performTower(source, aux, destination, totalMoves);

  // swap aux and destination if n is even as our result will be stored on the aux instead  
  if(n % 2 == 0)
    swap(aux, destination);

  // display destination and total number of moves
  cout<<"\nDisplaying destination stack"<<endl;
  displayDestination(destination);

  return 0;
}