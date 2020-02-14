/*
-------------------------Question:

Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]

Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
Note:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/

/*
-------------------------My Approaches:

1.

    This initial appraoch which uses a map to keep track of the index of the element in the array and the 
    element itself gets the solution but is not the most optimum solution
    Time complexity: O(n)
    Space Complexity: O(n)
*/

/*
-------------------------Other approaches

1. (Better)

    If you notice the solution of rotating an array, it involves basically two subarrays
    which are swapped to give you the final solution.
    n=7 , k=3
    Input               Output
    [1,2,3,4,5,6,7] -> [(5,6,7),(1,2,3,4)]

    As you can see this output is basically the input divided into 2 subarrays of length
    n-k and k and then swapped to give you the output. By swapping each of the subarrays in place
    and then swapping the whole array, we get the solution as the elements are put into their positions.

    Reversing in place and then reversing the whole array swaps the subarrays and puts them into their place.
    
    Time complexity: O(n)
    Space complexity: O(1)
*/

// My approach(1)
class Solution {
public:
    void rotateArray(vector<int> & nums, unordered_map<int,int> indexMap, int k){
        for(auto it = indexMap.begin(); it!=indexMap.end(); it++){
            nums[(it->first + k) % nums.size()] = it->second;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        unordered_map<int,int> indexMap;
        for(int index = 0; index<nums.size(); index++){
            indexMap[index] = nums[index];
        } 
        rotateArray(nums, indexMap, k);
    }
};


// Better approach(1)
class Solution {
public:
    void displayVector(vector<int> nums){
        cout<<"\n Displaying the vector: \n";
        for(int i = 0; i<nums.size(); i++){
            cout<<nums[i]<<" ";
        }
        cout<<"\n";
    }
    void rotateInPlace(vector<int> &nums, int k){
        reverse(nums.begin(), nums.begin()+nums.size()-k);
        // displayVector(nums);
        reverse(nums.end() - k, nums.end());
        // displayVector(nums);
        reverse(nums.begin(), nums.end());
    }
    
    void rotate(vector<int>& nums, int k) {
        if((nums.size() == 0) || (nums.size() == 1)){
            
        }
        else{
            k = k % nums.size();
            rotateInPlace(nums, k);
        }
    }
};