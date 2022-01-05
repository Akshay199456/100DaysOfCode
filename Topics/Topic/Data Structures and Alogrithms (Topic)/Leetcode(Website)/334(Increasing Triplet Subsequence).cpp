/*
-------------------------Question:

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

Example 1:

Input: [1,2,3,4,5]
Output: true
Example 2:

Input: [5,4,3,2,1]
Output: false
*/

/*
-------------------------My Approaches:

1. Brute force appraoch

The brute force appraoch is pretty simple. We check each subsequence pair depending and if the pair meets
the condition, we return true.

Time complexity: O(n^3)
Space complexity: O(1)

*/

/*
-------------------------Other approaches

1. Using a big and small value storage

This is a very interesting approach. We use variables to store the smallest and secondsmallest values
we have seen. One thing to remember there is that biggerThanSmall always gets set after small, whether the
small is the current small which gave rise to the current biggerThanSmall or a previous small which gave
rise to the current biggerThanSmall.

Also, The reason the approach works here as follows. Since element > current biggerThanSmall, the current
biggerThanSmall could be set either by the current small or by a pervious small. 

A. If it has been set by the current small, we know that the current small < current biggerThanSmall. So, 
if the current biggerThanSmall < element, we know that element > current small and hence we have found
a solution that matches the condition in the subsequence.

B. If it has been set by a previous small, we know that the current biggerThanSmall is greater than the 
current small. Since the current small was less than the previous small which set the current biggerThanSmall,
current small < previous small. As the current biggerThanSmall was set by the previous small, this means
that current biggerThanSmall is greater than previous small as well. So 
current small < previous small < current biggerThanSmall. And since the element > current biggerThanSmall
, it means that current small < previous small < current biggerThanSmall < element. Hence, we still have
a valid solution in this case as well as it follows the condition.


Now, the small and biggerThanSmall each have a couple of scenarios occur:

1A. Small
    1. Gets set before biggerThanSmall
    2. Gets set after biggerThanSmall

1B. biggerThanSmall
    1. Gets set before small
    2. Gets set after small

Since each variable has a couple of scenarios that occur independently, there are 2*2 = 4 scenarios that 
occur when the variables are combined together. There are one of 4 situations that can occur in this 
scenario which I will explain the solutions to using examples:

2A. Small -> gets set before biggerThanSmall; biggerThanSmall -> gets set before small

Example: [1,6,4,-1,8]

Order of operations:

1. small = 1       
2. biggerThanSmall = 6
3. biggerThanSmall = 4
4. small = -1
5. Return true since 8 > 4.

Here, the current big gets set by a previous small.


2B. small -> gets set before biggerThanSmall; big -> gets set after small

eg: [1,6,8]

Order of operations:

1. small = 1
2. biggerThanSmall = 6
3. Return true because 8 > 6.

This is a easy case. Since the current big gets set by the current small, if the element is greater than
the current biggerThanSmall, it will follow (A) from the explanation


2C. Small - > gets set after biggerThanSmall, biggerThanSmall -> gets set before small

eg: [1,6,4,-1,8]

Order of operations:

1. small = 1
2. biggerThanSmall = 6
3. biggerThanSmall = 4
4. small = -1
5. return true since 8 > 4.

This is a valid solution since it follows (B) from the explanation


2D. small -> gets set after biggerThanSmall; biggerThanSmall -> gets set after small

eg: [1,6,-1,8]

Order of operations:

1. small = 1
2. biggerThanSmall = 6
3. small = -1
4. Returns true since 8 > 6

This is a valid solution since it follows (B) from the explanation



Since the approach works for all possible scenarios that occur, it is a valid approach that helps in
identifying a subsequence that matches the condition in O(n) time complexity and O(1) space complexity.

Time complexity: O(n)
Space complexity: O(1)


*/

// My Approaches(1)
class Solution {
public:
    bool checkIncreasingTriplet(vector<int> nums){
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                for(int k = j+1; k < nums.size(); k++){
                    if(nums[i] < nums[j] && nums[j] < nums[k])
                        return true;
                }
            }
        }
        return false;
    }
    
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3)
            return false;
        else
            return checkIncreasingTriplet(nums);
    }
};


// Other Approaches(1)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small = INT_MAX, biggerThanSmall = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= small)
                small = nums[i];
            else if(nums[i] <= biggerThanSmall)
                biggerThanSmall = nums[i];
            else
                return true;
        }
        return false;
    }
};