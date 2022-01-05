/*
-------------------------Question:

Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.
*/

/*
-------------------------    My Approaches:
`1. Using map and heap

We can use a map to store the count of each character as we are going along and then use a heap with a comparator to order it accordingly.

Time complexity: O(n log n)
Space complexity: O(n)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    // define a comparator to make the comparison
        // note here: comparator in priority heap reverses the condition passed to it since it looks for a strcit weak ordering
    struct compareCondition{
        bool operator()(pair<int, string> lhs, pair<int, string> rhs) const{
            if(lhs.first == rhs.first)
                return lhs.second.compare(rhs.second) > 0;
            else
                return lhs.first < rhs.first;
        }
    };
    
    void fillMap(unordered_map<string, int> & elementMap, vector<string> words){
        for(int i=0; i<words.size(); i++){
            auto it = elementMap.find(words[i]);
            if(it == elementMap.end())
                elementMap[words[i]] = 1;
            else
                elementMap[words[i]]++;
        }
    }
    
    void fillHeap(unordered_map<string, int> elementMap, priority_queue<pair<int,string>, vector<pair<int,string>>, compareCondition> & topKQueue){
        for(auto it = elementMap.begin(); it != elementMap.end(); it++){
            topKQueue.push(make_pair(it->second, it->first));
        }
    }
    
    vector<string> getTopK(priority_queue<pair<int,string>, vector<pair<int,string>>, compareCondition> topKQueue, int k){
        vector<string> result;
        for(int i=1; i<=k; i++){
            pair<int,string> topPair = topKQueue.top(); 
            result.push_back(topPair.second);
            topKQueue.pop();
        }
        return result;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>, vector<pair<int,string>>, compareCondition> topKQueue;
        unordered_map<string, int> elementMap;
        
        // store the elements into a hashmap based on count
        fillMap(elementMap, words);
        
        // push the values into the prioity queue
        fillHeap(elementMap, topKQueue);
        
        // get top k elements from prioity queue
        return getTopK(topKQueue, k);
    }
};