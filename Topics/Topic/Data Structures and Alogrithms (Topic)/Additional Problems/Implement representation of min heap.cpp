/*
-------------------------Question:

Write a heap class that represents a minimum heap using an array. Implement the insert method for this min heap class.

min_heap = MinHeap()
min_heap.insert(2)
min_heap.insert(4)
min_heap.insert(1)
# Underlying array should look like: [1, 4, 2]
If time permits, implement the delete_min() method.
*/

/*
-------------------------    My Approaches:

1. Using a vector:

We can use a vector to implement the functionality

Time complexity: O(log n)
Space complexity: O(log n)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
#include <iostream>
#include <vector>

using namespace std;

class MinHeap{
public:
  vector<int> elements;
  
  MinHeap(){
  }

  void insert(int value){
    elements.push_back(value);
    int currentIndex = elements.size()-1;
    while(currentIndex -1 >= 0 && elements[(currentIndex - 1)/2] > elements[currentIndex]){
      swap(elements[(currentIndex - 1)/2], elements[currentIndex]);
      currentIndex = (currentIndex - 1) /2;
    }
  }

  int deleteMin(){
    int value = elements[0], currentIndex = 0;
    bool isEnd = false;

    swap(elements[0], elements[elements.size()-1]);
    elements.pop_back();

  /*
     to fill down we will need to check with children. Chidlren fo 3 tyoes:
      1. 2 children
      2. 1 child (left)
      3. no child
    */
  while(!isEnd){
    int leftChild = 2*currentIndex + 1, rightChild = 2*currentIndex + 2;
    if(leftChild < elements.size() && rightChild < elements.size()){
      int minElement, minIndex;
      
      // get teh index and value of teh smallest child
      if(elements[leftChild] < elements[rightChild]){
        minElement = elements[leftChild];
        minIndex = leftChild;
      }
      else{
        minElement = elements[rightChild];
        minIndex = rightChild;
      }

      // swap the min with the root if it is smaller 
      if(minElement < elements[currentIndex]){
        swap(elements[minIndex], elements[currentIndex]);
        currentIndex = minIndex;
      }
      else
        isEnd = true;
    }

    else if(leftChild < elements.size()){
      if(elements[leftChild] < elements[currentIndex]){
        swap(elements[leftChild], elements[currentIndex]);
        currentIndex = leftChild;
      }
      else
      isEnd = true;
    }

    else
      isEnd = true;
  }

    return value;
  }

  void printHeap(){
    cout<<"Printing heap: "<<endl;
    for(int i=0; i<elements.size(); i++){
      cout<<elements[i]<<" ";
    }
    cout<<endl;
  }
};

int main() {
  std::cout << "Hello World!\n";
  int value = -1;
  MinHeap * minObject = new MinHeap();
  minObject->insert(1);
  minObject->printHeap();
  value  = minObject->deleteMin();
  cout<<"Min element: "<<value<<endl;
  minObject->printHeap();
}