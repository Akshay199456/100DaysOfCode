/*
-------------------------Question:

Given an array of integers nums, sort the array in ascending order.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
 

Constraints:

1 <= nums.length <= 50000
-50000 <= nums[i] <= 50000
*/

/*
-------------------------My Approaches:
1. Quick sort

The first approach I apply is the quick sort approach. This is a divide and conquer approach where we sort the pivot element
into its position and then do the same for the left and right halves.

Time complexity: O(n^2) worst case, O(nlogn) avg case
Space complexity: O(logn)


2. Merge sort

Time complexity: O(nlogn)
Space complexity: O(logn)
*/

/*
-------------------------Other approaches

*/

// My Approaches(1)
class Solution {
public:
    int conquerArray(vector<int> & nums, int beg, int end){
        int pivot = nums[end];
        int partitionIndex = beg;
        while(beg < end){
            if(nums[beg] < pivot){
                swap(nums[beg], nums[partitionIndex]);
                partitionIndex++;
            }
            beg++;
        }
        swap(nums[end], nums[partitionIndex]);
        return partitionIndex;
    }
    
    void divideArray(vector<int> & nums, int beg, int end){
        if(beg >= end){
            
        }
        else{
            int partitionIndex = conquerArray(nums, beg, end);
            divideArray(nums, beg, partitionIndex-1);
            divideArray(nums, partitionIndex+1, end);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        if(!(nums.size() == 0 || nums.size() == 1))
            divideArray(nums, 0, nums.size() - 1);
        return nums;
    }
};


// My Approaches(2)
class Solution {
public:
    void conquerArray(vector<int> & nums, int beg, int mid, int end){
        vector<int> temp;
        int mid1 = mid, mid2 = mid+1, tempBeg = beg;
        while(beg <= mid1 && mid2 <= end){
            if(nums[beg] < nums[mid2])
                temp.push_back(nums[beg++]);
            else
                temp.push_back(nums[mid2++]);
        }
        
        while(beg <= mid1)
            temp.push_back(nums[beg++]);
        
        while(mid2 <= end)
            temp.push_back(nums[mid2++]);
        
        for(int i = 0; i < temp.size();i++)
            nums[tempBeg+i] = temp[i];
    }
    
    void divideArray(vector<int> & nums, int beg, int end){
        if(beg >= end){
            
        }
        else{
            int mid = (beg + end)/2;
            divideArray(nums, beg, mid);
            divideArray(nums, mid+1, end);
            // cout<<"before conquer: "<<endl;
            // printArray(nums, beg, end);
            conquerArray(nums, beg, mid, end);
            // cout<<"after conquer: "<<endl;
            // printArray(nums, beg, end);
        }
    }
    
    void printArray(vector<int> nums, int beg, int end){
        cout<<"Beg: "<<beg<<" End: "<<end<<"->";
        for(int i= 0; i < nums.size(); i++)
            cout<<nums[i]<<" ";
        cout<<endl;
    }
    
    vector<int> sortArray(vector<int>& nums) {
        if(!(nums.size() == 0 || nums.size() == 1))
            divideArray(nums, 0, nums.size() - 1);
        return nums;
    }
};