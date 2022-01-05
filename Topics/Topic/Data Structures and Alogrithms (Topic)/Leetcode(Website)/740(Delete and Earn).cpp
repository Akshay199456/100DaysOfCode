/*
-------------------------Question:
Given an array nums of integers, you can perform operations on the array.

In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.

You start with 0 points. Return the maximum number of points you can earn by applying such operations.

 

Example 1:

Input: nums = [3,4,2]
Output: 6
Explanation: Delete 4 to earn 4 points, consequently 3 is also deleted.
Then, delete 2 to earn 2 points.
6 total points are earned.
Example 2:

Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: Delete 3 to earn 3 points, deleting both 2's and the 4.
Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
9 total points are earned.
 

Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i] <= 104
*/

/*
-------------------------    My Approaches:
1. Backtracking approach

We can use the backcracking approach in order to solve this problem. We follow each step of the problem and remove the numbers as required. This approach will identify all possiblel solutions and then give the best solution out of it.

Time complexity: O(n^n)
Space omplexity: O(n)
*/

/*
-------------------------    Other approaches:
1. Dynamic Programming approach

We can approach upon this solution by using DP. This problem can acutally be considered as a form of the robbing houese, jumping houses/game DP problem. If we distribute the different numbers into buckets where each number is put into 
a bucket correponding to that number, this problem is basically asking us to select buckets in the maximized manner. If we select bucket i, then we can't select bucket i-1 and i+1 as those numbers will be removed. As a result, what we can
do is create a list which stores the sum of each of those buckets and fill our dp array based on the maximized condition of those buckets. At each stage, we can make one of 2 choices: either skip this bucket(i) and taking whatever was the 
max we had till i-1 or consider this bucket(i) and extend the max that we had from i-2. The max of these two gives the solution for dpList[i].

Time complexity: O(c) where c is a constant representing the total range of numbers
Space complexdity: O(c)
*/

// My Approaches(1)
class Solution {
public:
    vector<int> removeElement(int value, vector<int> & nums, int & nRemoved, unordered_map<int, vector<int>> & elementMap){
        vector<int> indexList = elementMap[value];
        vector<int> result;
        for(int i=0; i<indexList.size(); i++){
            if(nums[indexList[i]] != -1){
                nRemoved++;
                nums[indexList[i]] = -1;
                result.push_back(indexList[i]);
            }
        }
        return result;
    }
    
    vector<vector<int>> removeNeighbors(int previousValue, vector<int> & nums, int & nRemoved, unordered_map<int, vector<int>> & elementMap){
        vector<int> leftList, rightList;
        // look for previousValue - 1
        if(elementMap.find(previousValue - 1) != elementMap.end())
            leftList = removeElement(previousValue - 1, nums, nRemoved, elementMap);
            
        
        // look for previousValue + 1
        if(elementMap.find(previousValue + 1) != elementMap.end())
            rightList = removeElement(previousValue + 1, nums, nRemoved, elementMap);
        
        // return vector of left and right list
        vector<vector<int>> outputList{leftList, rightList};
        return outputList; 
    }
    
    void fixNeighbors(vector<vector<int>> & removedNeighborIndexes, vector<int> & nums, int value){
        // left list
        for(int i=0; i< removedNeighborIndexes[0].size(); i++)
            nums[removedNeighborIndexes[0][i]] = value-1;
        
        // right list
        for(int i=0; i< removedNeighborIndexes[1].size(); i++)
            nums[removedNeighborIndexes[1][i]] = value+1;
    }
    
    void getMaxPoints(vector<int> nums, int &maxTotal, int total, int nOps, unordered_map<int, vector<int>> & elementMap){
        if(nOps == nums.size())
            maxTotal = max(total, maxTotal);
        else{
            for(int i=0; i<nums.size(); i++){
                if(nums[i] != -1){
                    int previousValue = nums[i], nRemoved = 0;
                    nums[i] = -1;
                    vector<vector<int>> removedNeighborIndexes = removeNeighbors(previousValue, nums, nRemoved, elementMap);
                    getMaxPoints(nums, maxTotal, total + previousValue, nOps+1+nRemoved, elementMap);
                    nums[i] = previousValue;
                    fixNeighbors(removedNeighborIndexes, nums, previousValue);
                }
            }
        }
    }
    
    void generateMap(vector<int> & nums, unordered_map<int, vector<int>> & elementMap){
        for(int i=0; i<nums.size(); i++){
            if(elementMap.find(nums[i]) == elementMap.end()){
                vector<int> list{i};
                elementMap[nums[i]] = list;
            }
            else
                elementMap[nums[i]].push_back(i);
        }
    }
    
    int deleteAndEarn(vector<int>& nums) {
        int maxTotal = 0, total = 0, nOps = 0;
        unordered_map<int, vector<int>> elementMap;
        generateMap(nums, elementMap);
        getMaxPoints(nums, maxTotal, total, nOps, elementMap);
        return maxTotal;
    }
};



// Other approaches(1)
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> dpList(n, 0), tempList(n,0);
        
        // fill tempList
        for(int num: nums)
            tempList[num] += num;
        
        
        dpList[1] = tempList[1]; 
        // fill dpList 
        for(int i=2; i<n; i++){
            dpList[i] = max(dpList[i-1], dpList[i-2] + tempList[i]);
        }
        
        return dpList[n-1];
    }
};