/*
-------------------------Question:

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

/*
-------------------------My Approaches:

1. Using quick sort in a divide and conquer approach

We can use the divide and conquer technique and imnplement quick sort to find the solution to the problem. Here, we choose
the pivot as the end element. At each conquer step, we are insserting the element into its position. We then check if
this is the index that is requested by the problem. If it its, we return the element at that index. Else, we go left or
right and repeat the divide approach till we find a solution.

Time complexity: O(nlogn)
Space complexity: O(log n)

*/

/*
-------------------------Other approaches

*/

// My Approaches(1)
class Solution {
public:
    int partitionList(vector<int> & nums, int beg, int end){
        int pivot = nums[end], pivotIndex = beg;
        for(int i = beg; i < end; i++){
            if(nums[i] <= pivot){
                swap(nums[i], nums[pivotIndex]);
                pivotIndex++;
            }
        }
        swap(nums[pivotIndex], nums[end]);
        return pivotIndex;
    }
    
    int getKthLargest(vector<int> nums, int beg, int end, int k){
        // cout<<"beg: "<<beg<<" end: "<<end<<" k: "<<k<<endl;
        if(beg == end)
            return nums[beg];
        else{
            int partitionIndex = partitionList(nums, beg, end);
            // cout<<"Partition index: "<<partitionIndex<<endl;
            if(partitionIndex == nums.size() - k)
                return nums[partitionIndex];
            else if(nums.size() - k < partitionIndex)
                return getKthLargest(nums, beg, partitionIndex-1,k);
            else
                return getKthLargest(nums, partitionIndex+1, end, k);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return getKthLargest(nums, 0, nums.size()-1,k);
    }
};