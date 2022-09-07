/*
Problem statement:

Given a sequence originalSeq and an array of sequences, write a method to find if originalSeq can be uniquely reconstructed from the array of sequences.

Unique reconstruction means that we need to find if originalSeq is the only sequence such that all sequences in the array are subsequences of it.

Example 1:

Input: originalSeq: [1, 2, 3, 4], seqs: [[1, 2], [2, 3], [3, 4]]
Output: true
Explanation: The sequences [1, 2], [2, 3], and [3, 4] can uniquely reconstruct   
[1, 2, 3, 4], in other words, all the given sequences uniquely define the order of numbers 
in the 'originalSeq'. 
Example 2:

Input: originalSeq: [1, 2, 3, 4], seqs: [[1, 2], [2, 3], [2, 4]]
Output: false
Explanation: The sequences [1, 2], [2, 3], and [2, 4] cannot uniquely reconstruct 
[1, 2, 3, 4]. There are two possible sequences we can construct from the given sequences:
1) [1, 2, 3, 4]
2) [1, 2, 4, 3]
Example 3:

Input: originalSeq: [3, 1, 4, 2, 5], seqs: [[3, 1, 5], [1, 4, 2, 5]]
Output: true
Explanation: The sequences [3, 1, 5] and [1, 4, 2, 5] can uniquely reconstruct 
[3, 1, 4, 2, 5].

*/

/*
-------------------------    My Approaches:
1. Topologcial sort

    we can solve this problmem using the topolgical sort aglortih,. the only additional check we will
    need to add is to check if there are more than one entry in the queue. cause if there is, then we wont have a unique solution and there will be multiple solutions to
    the problem so we return false. other than that, everything is the same as that of  a normal topological sort algorithm

    Time complexity: O(v+e)
    Space complexity: O(v+e)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
since each sequence in the given array defines teh ordering of some numbers, we need to combine all these ordering rules to find two things:
    1. is it possible to construct the originalSeq from all these rules?
    2. are these ordering rules not sufficient enough to define the unique ordering of all the numbers in the originalSeq?? in other words
    can these rules result in more than one sequencfe?

take example
    originalSeq: [1, 2, 3, 4], seqs:[[1, 2], [2, 3], [3, 4]]

the first sequence tells us that '1' comes before '2'; the second sequence tells us that '2' comes before '3';
the third sequence tells us that '3' comes before '4'. combining these sequences will result
in a uniqueu sequence: [1,2,3,4]

the above explanation tells us that we are actually asked to find the toopoloigical ordering of all the numbers and also to verify that
there is onyl one topoloigical ordernig of the numbers possible fromt he given array of the sequences.

this mmakes the current problem similar to tasks scheduling order with two differences:
    1. we need to buld the graph of the numbers by compairing each pair of numbers in the given array of sequences.
    2. we must perform teh topological sort for the graph to determine two things:
        1. can the topolgoical ordering construct the originalSeq?
        2. that there ois only one topolgical ordering of the numbers possible. this can be confirmed if we do not have more than one source at any time while
        finding the topological ordering of the numbers

    Time complexity: O(v+n)
    Space complexity: O(v+n)
*/



//  My approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class SequenceReconstruction {
 public:
  static void createGraph(unordered_map<int, unordered_set<int>> & graph, const vector<int> &originalSeq, const vector<vector<int>> &sequences){
    // initlaize graph to 0
    for(int i=0; i< originalSeq.size(); i++){
      graph[originalSeq[i]] = unordered_set<int>();
    }

    // initialzie graph based on sequences
    for(int i=0; i < sequences.size(); i++){
      vector<int> list = sequences[i];
      for(int j=0; j < list.size() - 1; j++){
        int currElement = list[j], nextElement = list[j+1];
        // cout<<"Curr element: "<<currElement<<" next element: "<<nextElement<<endl;
        if(!graph[currElement].count(nextElement)){
          graph[currElement].emplace(nextElement);
        }
      }
    }
  }

  static void getParentCount(unordered_map<int, int> & parentCount, unordered_map<int, unordered_set<int>> & graph){
    // initilaize all parents to 0
    for(auto it = graph.begin(); it!= graph.end(); it++){
      parentCount[it->first] = 0;
    }

    // initialize parents based on graph
    for(auto it = graph.begin(); it!= graph.end(); it++){
      unordered_set<int> set = it->second;
      for(auto iter = set.begin(); iter!= set.end(); iter++){
        parentCount[*iter] += 1;
      }
    }
  }

  static void printList(vector<int> & result){
    cout<<"printing list: "<<endl;
    for(int i=0; i< result.size(); i++)
      cout<<result[i]<<" ";
    cout<<endl;
  }

  static bool getTopSort(unordered_map<int, int> & parentCount, unordered_map<int, unordered_set<int>> & graph, const vector<int> &originalSeq){
    queue<int> elementQueue;
    vector<int> result;

    // push all aprents with 0
    for(auto it = parentCount.begin(); it!= parentCount.end(); it++){
      if(!it->second)
        elementQueue.push(it->first);
    }
    
    // push rest of parents depending on queue
    while(!elementQueue.empty()){
      if(elementQueue.size() > 1)
        return false;
      
      int topElement = elementQueue.front();
      result.push_back(topElement);
      elementQueue.pop();

      unordered_set<int> set = graph[topElement];
      for(auto it = set.begin(); it != set.end(); it++){
        parentCount[*it] -= 1;
        if(!parentCount[*it])
          elementQueue.push(*it);
      }
    }

    // printList(result);
    return result == originalSeq;
  }

  static void printResult(unordered_map<int, int> & parentCount){
    for(auto it = parentCount.begin(); it!= parentCount.end(); it++){
      cout<<"element: "<<it->first<<" count: "<<it->second<<endl;
    }
  }

  static void printGraph(unordered_map<int, unordered_set<int>> & graph){
    for(auto it = graph.begin(); it!= graph.end(); it++){
      unordered_set<int> set = it->second;
      cout<<"Element :"<<it->first<<endl;
      for(auto iter = set.begin(); iter!= set.end(); iter++){
        cout<<*iter<<" ";
      }
      cout<<endl;
    }
  }

  static bool canConstruct(const vector<int> &originalSeq, const vector<vector<int>> &sequences) {
    unordered_map<int, unordered_set<int>> graph;
    unordered_map<int, int> parentCount;

    // TODO: Write your code here
    createGraph(graph, originalSeq, sequences);
    // printGraph(graph);
    getParentCount(parentCount, graph);
    // printResult(parentCount);
    return getTopSort(parentCount, graph, originalSeq);
  }
};

int main(int argc, char *argv[]) {
  bool result = SequenceReconstruction::canConstruct(
      vector<int>{1, 2, 3, 4},
      vector<vector<int>>{vector<int>{1, 2}, vector<int>{2, 3}, vector<int>{3, 4}});
  cout << "Can we uniquely construct the sequence: " << result << endl;

  result = SequenceReconstruction::canConstruct(
      vector<int>{1, 2, 3, 4},
      vector<vector<int>>{vector<int>{1, 2}, vector<int>{2, 3}, vector<int>{2, 4}});
  cout << "Can we uniquely construct the sequence: " << result << endl;

  result = SequenceReconstruction::canConstruct(
      vector<int>{3, 1, 4, 2, 5},
      vector<vector<int>>{vector<int>{3, 1, 5}, vector<int>{1, 4, 2, 5}});
  cout << "Can we uniquely construct the sequence: " << result << endl;
}



//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class SequenceReconstruction {
 public:
  static bool canConstruct(const vector<int> &originalSeq, const vector<vector<int>> &sequences) {
    vector<int> sortedOrder;
    if (originalSeq.size() <= 0) {
      return false;
    }

    // a. Initialize the graph
    unordered_map<int, int> inDegree;       // count of incoming edges for every vertex
    unordered_map<int, vector<int>> graph;  // adjacency list graph
    for (auto seq : sequences) {
      for (int i = 0; i < seq.size(); i++) {
        inDegree[seq[i]] = 0;
        graph[seq[i]] = vector<int>();
      }
    }

    // b. Build the graph
    for (auto seq : sequences) {
      for (int i = 1; i < seq.size(); i++) {
        int parent = seq[i - 1], child = seq[i];
        graph[parent].push_back(child);
        inDegree[child]++;
      }
    }

    // if we don't have ordering rules for all the numbers we'll not able to uniquely construct the
    // sequence
    if (inDegree.size() != originalSeq.size()) {
      return false;
    }

    // c. Find all sources i.e., all vertices with 0 in-degrees
    queue<int> sources;
    for (auto entry : inDegree) {
      if (entry.second == 0) {
        sources.push(entry.first);
      }
    }

    // d. For each source, add it to the sortedOrder and subtract one from all of its children's
    // in-degrees if a child's in-degree becomes zero, add it to the sources queue
    while (!sources.empty()) {
      if (sources.size() > 1) {
        return false;  // more than one sources mean, there is more than one way to reconstruct the
                       // sequence
      }
      if (originalSeq[sortedOrder.size()] != sources.front()) {
        return false;  // the next source (or number) is different from the original sequence
      }
      int vertex = sources.front();
      sources.pop();
      sortedOrder.push_back(vertex);
      vector<int> children =
          graph[vertex];  // get the node's children to decrement their in-degrees
      for (auto child : children) {
        inDegree[child]--;
        if (inDegree[child] == 0) {
          sources.push(child);
        }
      }
    }

    // if sortedOrder's size is not equal to original sequence's size, there is no unique way to
    // construct
    return sortedOrder.size() == originalSeq.size();
  }
};

int main(int argc, char *argv[]) {
  bool result = SequenceReconstruction::canConstruct(
      vector<int>{1, 2, 3, 4},
      vector<vector<int>>{vector<int>{1, 2}, vector<int>{2, 3}, vector<int>{3, 4}});
  cout << "Can we uniquely construct the sequence: " << result << endl;

  result = SequenceReconstruction::canConstruct(
      vector<int>{1, 2, 3, 4},
      vector<vector<int>>{vector<int>{1, 2}, vector<int>{2, 3}, vector<int>{2, 4}});
  cout << "Can we uniquely construct the sequence: " << result << endl;

  result = SequenceReconstruction::canConstruct(
      vector<int>{3, 1, 4, 2, 5},
      vector<vector<int>>{vector<int>{3, 1, 5}, vector<int>{1, 4, 2, 5}});
  cout << "Can we uniquely construct the sequence: " << result << endl;
}
