/*
-------------------------Question:
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

 

Constraints:

intervals[i][0] <= intervals[i][1]
*/

/*
-------------------------My Approaches:
1. Sortign intervals and two pointer approach

If we sketch the problem and try to understand the brute force approach, this is basically a scheduling problem at the end
of the day.Right. Think about it. If you had a bunch of classes, how would you organize your scehdule. You would list
the classes in the order of their start time and fuse them together if they extend each other else skip it if one
is composed within the other. we apply the same strategy here. As a result, it's important to sort the array to have
that ability to fuse intervals together.

We pass in our own comparator to just sort the arrays based on the begin index.

Time complexity: O(nlogn)
Space complexity: O(1)
*/

/*
-------------------------Other approaches
1. Using a graph and solving brute force

If we think of the brute force approach, this is more of a grap h problem. We can connect each interval to the next
based on whether they are overlapping. At the end, the interals will be connected eaither directly or indirrectly. we
then need to generate connections between the connected components and find the overall interval corresponding to a 
connection.

Time complexity: O(n^2)
Space complexity: O(n^2)
*/

// My Approaches(1)
class Solution {

public:
    static bool comparator(vector<int> interval1, vector<int> interval2){
       return interval1[0] < interval2[0];
    }
    
    void mergeIntervals(vector<vector<int>> intervals, vector<vector<int>> & result){
        int beg = intervals[0][0], end = intervals[0][1];
        for(int i = 1; i< intervals.size(); i++){
            if(intervals[i][0] <= end){
                if(intervals[i][1] > end)
                    end = intervals[i][1];
            }
            else{
                vector<int> list{beg, end};
                result.push_back(list);
                beg = intervals[i][0];
                end = intervals[i][1];
            }
        }
        
        vector<int> list{beg, end};
        result.push_back(list);
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if(intervals.size() == 0 || intervals.size() == 1)
            return intervals;
        
        sort(intervals.begin(), intervals.end(), comparator);
        mergeIntervals(intervals, result);
        return result;
    }
};


// Other Approaches(1)
struct hash_pair{
    template<class T> size_t operator()(const vector<T> & p) const{
        auto hash1 = hash<T>{}(p[0]);
        auto hash2 = hash<T>{}(p[1]);
        return hash1 ^ hash2;
    }
};

class Solution {
public:
    unordered_map<vector<int>,vector<vector<int>>, hash_pair> graph;
    unordered_map<int, vector<vector<int>>> connectedComponents;
    unordered_set<vector<int>, hash_pair> visited;
    
    bool isOverLapping(vector<int> interval1, vector<int> interval2){
        return interval2[0] >= interval1[0] && interval2[0] <= interval1[1];
    }
    
    void generateGraph(vector<vector<int>> intervals){
        for(int i = 0; i < intervals.size(); i++){
            vector<vector<int>> dummy;
            graph[intervals[i]] = dummy;
        }
        
        for(int i = 0 ; i < intervals.size(); i++){
            for(int j = 0; j < intervals.size(); j++){
                if(i!=j && isOverLapping(intervals[i], intervals[j])){
                    graph[intervals[i]].push_back(intervals[j]);
                    graph[intervals[j]].push_back(intervals[i]);
                }
            }
        }
    }
    
    void printGraph(){
        for(auto it = graph.begin(); it!=graph.end(); it++){
            vector<int> key = it->first;
            vector<vector<int>> value = it->second;
            cout<<"Key: "<<key[0]<<" "<<key[1]<<endl;
            for(int i = 0; i <value.size(); i++){
                cout<<"\tValue: "<< value[i][0]<<" "<<value[i][1]<<endl;
            }
        }
    }
    
    void printConnectedComponents(){
        for(int i = 0; i < connectedComponents.size(); i++){
            cout<<"Index: "<<i<<endl;
            for(int j = 0; j < connectedComponents[i].size(); j++){
                cout<<connectedComponents[i][j][0]<<","<<connectedComponents[i][j][1]<<"->";
            }
            cout<<endl;
        }
    }
    
    void bfs(vector<int> key,int count){
        stack<vector<int>> s;
        s.push(key);
        vector<vector<int>> value;
        connectedComponents[count] = value;
        
        while(!s.empty()){
            vector<int> current = s.top();
            s.pop();
            if(visited.find(current) == visited.end()){
                value = graph[current];
                connectedComponents[count].push_back(current);
                for(int i = 0; i < value.size(); i++){
                    s.push(value[i]);
                }
                visited.emplace(current);
            }
        }
    }
    
    void generateConnectedComponents(){
        int count = 0;
        for(auto it = graph.begin(); it!=graph.end(); it++){
            if(visited.find(it->first) == visited.end()){
                bfs(it->first, count);
                ++count;
            }
        }  
    }
    
    void mergeConnectedComponents(vector<vector<int>> & results){
        for(auto it = connectedComponents.begin(); it!=connectedComponents.end(); it++){
            // finding min
            int minimum = (it->second)[0][0];
            for(int i = 1; i < (it->second).size(); i++)
                minimum = min(minimum, (it->second)[i][0]);
            
            // finding max
            int maximum = (it->second)[0][1];
            for(int i = 1; i < (it->second).size(); i++)
                maximum = max(maximum, (it->second)[i][1]);
            
            // pushing it into results array
            vector<int> temp{minimum, maximum};
            results.push_back(temp);
        }
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0 || intervals.size() == 1)
            return intervals;
        else{
            vector<vector<int>> results;
            generateGraph(intervals);
            //printGraph();
            //cout<<"\n----------------------------------\n";
            generateConnectedComponents();
            //printConnectedComponents();
            mergeConnectedComponents(results);
            return results;
        }
    }
};