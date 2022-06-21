/*
Problem statement:

Given a string and a number ‘K’, find if the string can be rearranged such that the same characters are at least ‘K’ distance apart from each other.

Example 1:

Input: "mmpp", K=2
Output: "mpmp" or "pmpm"
Explanation: All same characters are 2 distance apart.
Example 2:

Input: "Programming", K=3
Output: "rgmPrgmiano" or "gmringmrPoa" or "gmrPagimnor" and a few more
Explanation: All same characters are 3 distance apart.
Example 3:

Input: "aab", K=2
Output: "aba"
Explanation: All same characters are 2 distance apart.
Example 4:

Input: "aappa", K=3
Output: ""
Explanation: We cannot find an arrangement of the string where any two 'a' are 3 distance apart.
*/

/*
-------------------------    My Approaches:
1. top k patterns approach + utilizing knowledge form pb 89 grok

    we did fillow the top k patterns approach by storing the count fo the characters based on the frequency into a max heap very simular to the pb 89 grok.
    however, the main differencebetween this problem and the previous one was that in the previous one, we can think about the problem with k=2 and so we just used a 
    variable to keep track of when to put the value back into the heap. however, here k can be any value so you want something that can keep track of the characters in the wiatlist ot eb inserted into the heap
    as well as maintains order. the best candidate for it was therefore a queue which we used to fill with a tuple of three values: the character,
    its reamining count and the last index this character was seen. once the character crosses the k barrier we insert it into th heap again
    so that we can make use fo that information in order to decide which would be the next character based on their count.

    As a resilt, during every execution, we check of the quue is empty or not. if it is, we get the elemtns from the ehap and push it into the quue depending on the dondition.
    if it is not empty, we then check if the top of the queue can be inserted back into the heap
    or if we cant fill the string further in which case we return an empty string.

    as a result, this problem is very similar to the preivous problem (pb 89 grok) with the main difference that we use a queue to keep track of when to insert back elements back
    into the heap.


    Time complexity: O(n + nlogn + O(nlogn)) = O(nlogn)
    Space complexity: O(n) where n is the total no of characters in the string
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
#include <vector>

class RearrangeStringKDistanceApart {
 public:
     static void createMap(unordered_map<char,int> & frequencyCount, const string &str){
          for(char ch: str)
               frequencyCount[ch]++;
     }

     static void fillHeap(unordered_map<char,int> & frequencyCount , priority_queue<pair<int,char>> & pq){
          for(auto it = frequencyCount.begin(); it!= frequencyCount.end(); it++){
               pq.push(make_pair(it->second, it->first));
          }

     }

     static string obtainString(priority_queue<pair<int,char>> & pq, const string &str, int k){
          string resultString = "";
          int count = 0;
          queue<tuple<char,int,int>> waitList;

          while(!pq.empty() || !waitList.empty()){
               if(!waitList.empty()){
                    tuple<char,int,int> tuplePair = waitList.front();
                    if(get<2>(tuplePair) + k == count){
                         pq.push(make_pair(get<1>(tuplePair), get<0>(tuplePair)));
                         waitList.pop();
                    }
                    else if(get<2>(tuplePair) + k > count && pq.empty()){
                         return "";
                    }
               }

               pair<int, char> currentEntry = pq.top();
               pq.pop();
               resultString += currentEntry.second;
               if(currentEntry.first > 1)
                    waitList.push(make_tuple(currentEntry.second, currentEntry.first-1, count));
               count += 1;
          }
          return count == str.size() ? resultString : "";
     }

     static string reorganizeString(const string &str, int k) {
     // TODO: Write your code here

     if(k <= 1)
          return str;
    
     unordered_map<char,int> frequencyCount;
     priority_queue<pair<int,char>> pq;

     createMap(frequencyCount, str);
     fillHeap(frequencyCount, pq);
     return obtainString(pq, str, k);
  }
};

int main(int argc, char *argv[]) {
  cout << "Reorganized string: "
       << RearrangeStringKDistanceApart::reorganizeString("aap", 0) << endl;
  cout << "Reorganized string: "
       << RearrangeStringKDistanceApart::reorganizeString("aap", 1) << endl;
  cout << "Reorganized string: "
       << RearrangeStringKDistanceApart::reorganizeString("aapa", 2) << endl;
  cout << "Reorganized string: " << RearrangeStringKDistanceApart::reorganizeString("abcdef", 3)
       << endl;
}



//  Other Approaches(1)
