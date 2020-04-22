/*
-------------------------Question:

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

/*
-------------------------My Approaches:

While I was able to obtain all possible answers to this problem including the duplicates in 
O(n^2) time complexity using the two-sum approach, I wasn't able to get the answer to this specific
problem where the duplicates can't occur in the final result. Hence my answer will not be valid
here.

To elaborate here, I was unable to solve this particular problem but have only included in 
My Approaches the approach I used to generate all possible solutions including duplicates.
*/

/*
-------------------------Other approaches

1. Using 2Sum approach[Best]

This approach also utilized the two sum approach as I utilized. However, the difference was that
the two sum approach that was used was slightly different than the original hashmap apporach to
twoSum. The hashmap approach in the two sum approach allowed us to find a unique solution in O(n)
time compelxity with O(n) space compelxity. The other way we could have solved twoSum was to sort
the array and to have a begin and end pointer to calculate the sum. Since the elements in the array
are sorted, there are one of 3 possibilities with respect to the sum of the begin and end element:

	a. If the sum equals the target we are lookign for, we have basically obtained the solutions,
	so we find the index of the begin and end elemnt in the original array and return it.
	b. If the sum is less than the target, we move the begin forward as the array is sorted and
	incrementing the begin is a move to a bigger sum.
	If the sum if greater than the target, we move the end backward as the array is sorted and 
	decrementing the end is a move to a smaller sum.

Using this approach taken O(nlogn) time. While in 2sum it might not tbe the most efficient 
approach, for the 3sum problem, this approach provides the most efficient solution. Basically,
for each value in the array we employ the two sum approach(after soring the array) to find all 
possible solutions that are not duplicates and continue that till the end of the array.


Since duplicates can be involved in the solution, we want to make sure to avoid them. This is a
2 step process. At the beginning, we want to make sure that the array element that we are selectiing
is not the same as the prvious element since if it was, all possible solutions of the current 
duplicate would have already been covered by the previous elemnt. The secondary check comes in
during the two sum approach to make sure we are not covering duplicate values cause those solutions
would have already been covered by previous selections. Depending on the sum, we either move
begin or end and register the solution into the array when we obtain the target sum.


Time complexity: O(n^2) + O(nlogn) => O(n^2)
Space complexity: O(1)


While this is the standard approach, we can improve it at certain points to help improve the 
practical runtime by a bit.



2. Improving upon Other Approaches(1)

We can improve upon Other Apporaches(1) by removing certain bottlenecks. For example, if the 
number in the outer loop is ever greater than the target, we can stop the looping since
the array is sorted and any element from the current element will only be greater than or eqal to
the current element, which means it will always be greater than the target.

Time complexity: O(n^2)
Space compelxity: O(1)
*/



// Other Approaches(1)
class Solution {
public:
    
    void getResults(vector<int> & nums, int target, vector<vector<int>> & results){
        // cout<<"Nums size: "<< nums.size() -2;
        sort(nums.begin(), nums.end());
        for(int i= 0 ;i < int(nums.size()) - 2; i++){
            if(i == 0 || (nums[i] != nums[i-1])){
                int targetSum = target - nums[i];
                int begin = i + 1, end = nums.size() - 1;
                while(begin < end){
                    int currentSum = nums[begin] + nums[end];
                    if(currentSum == targetSum){
                        vector<int> combination {nums[i], nums[begin], nums[end]};
                        results.push_back(combination);
                        
                        while(begin < end && nums[begin] == nums[begin+1])
                            begin++;
                        while(begin < end && nums[end] == nums[end-1])
                            end--;
                        
                        begin++; end--;
                    }
                    
                    else if(currentSum < targetSum)
                        begin++;
                    else
                        end--;
                }
            }
        }
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        vector<vector<int>> results;
        getResults(nums, target, results);
        return results;
    }
};



// My Approaches(2)
class Solution {
public:
    
    void getResults(vector<int> & nums, int target, vector<vector<int>> & results){
        // cout<<"Nums size: "<< nums.size() -2;
        sort(nums.begin(), nums.end());
        for(int i= 0 ;i < int(nums.size()) - 2 && nums[i] <= target; i++){
            if(i == 0 || (nums[i] != nums[i-1])){
                int targetSum = target - nums[i];
                int begin = i + 1, end = nums.size() - 1;
                while(begin < end){
                    int currentSum = nums[begin] + nums[end];
                    if(currentSum == targetSum){
                        vector<int> combination {nums[i], nums[begin], nums[end]};
                        results.push_back(combination);
                        
                        while(begin < end && nums[begin] == nums[begin+1])
                            begin++;
                        while(begin < end && nums[end] == nums[end-1])
                            end--;
                        
                        begin++; end--;
                    }
                    
                    else if(currentSum < targetSum)
                        begin++;
                    else
                        end--;
                }
            }
        }
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        vector<vector<int>> results;
        getResults(nums, target, results);
        return results;
    }
};