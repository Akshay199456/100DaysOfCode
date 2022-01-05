/*
-------------------------Question:

Huffman coding is a lossless data compression algorithm. 
The idea is to assign variable-length codes to input characters, 
lengths of the assigned codes are based on the frequencies of corresponding characters. 

The most frequent character gets the smallest code and the least frequent character gets the largest code.
*/

/*
-------------------------    My Approaches:

*/

/*
-------------------------    Other approaches:
1. Using Greedy Approach to generate huffman coding.

In this greedy approach, the character that occurs the most is the one with the shortest code while the one which occurs the least is the one with the longest code. We can then use the code generated to compress the data more effectively
and can get back the data from the code using the encoding.

We use a min heap to store the frequency of characters and a tree to hold the order of nodes starting with the node that occurs the most at the top of the tree.

Check [Helping Images] for more info.

Time complexity: O(nlog n)
Space complexity: O(n)
*/

// Other Approaches(1)
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct MinHeapNode{
  char data;
  int frequency;
  MinHeapNode * left, *right;

  MinHeapNode(char data, int frequency, MinHeapNode * leftChild, MinHeapNode * rightChild){
    this->data = data;
    this->frequency = frequency;
    this->left = leftChild;
    this->right = rightChild;
  }
};

struct compare{
  bool operator()(MinHeapNode * left, MinHeapNode * right){
    return (left->frequency > right->frequency);
  }
};

priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> huffmanCodes(vector<char> letters, vector<int> frequency){
  priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;
  
  // create minHeap from letters and frequency given
  for(int i=0; i<letters.size(); i++){
    MinHeapNode * tempNode = new MinHeapNode(letters[i], frequency[i], NULL, NULL);
    minHeap.push(tempNode);
  }

  // Continue this till only one node remains in min heap.
  while(minHeap.size() != 1){
    
    // Extract 2 nodes with min frequency
    MinHeapNode * leftChild = minHeap.top();
    minHeap.pop();

    MinHeapNode * rightChild = minHeap.top();
    minHeap.pop();
    
    // Create new internal node whose sum frequency sum is sum of the two previous nodes with min frequency. This internal node will have '#' as the data
    // Push it back into minHeap
    minHeap.push(new MinHeapNode('#',leftChild->frequency + rightChild->frequency, leftChild, rightChild));
  }

  return minHeap;
}

void printCodes(MinHeapNode * node, string code){
  if(node){
    if(node->data != '#')
      cout<<"Character: "<<node->data<<" Code: "<<code<<endl;
    printCodes(node->left, code + "0");
    printCodes(node->right, code + "1");
  }
}

void printHeap(MinHeapNode * node){
  if(node){
    cout<<"Character: "<<node->data<<" Frequency: "<<node->frequency<<endl;
    printHeap(node->left);
    printHeap(node->right);
  }
}

int main()
{
  vector<char> letters = {'a','b','c','d','e','f'};
  vector<int> frequency = {5,9,12,13,16,45};
  MinHeapNode * topNode;
  priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap = huffmanCodes(letters,frequency);
  // printHeap(minHeap.top());
  printCodes(minHeap.top(), "");
  return 0;
}