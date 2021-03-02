/*
-------------------------Question:

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
 

Follow up: The overall run time complexity should be O(log (m+n)).

*/

/*
-------------------------    My Approaches:
1. MErging into new array and calulating median [Doesn't satisfy the follow up condition]

We can merge the two sorted arrays into a new array and then find the median from that new array

Time complexity: O(m+n)
Space complexity: O(m+n)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    void mergeArrays(vector<int> & result, vector<int> nums1, vector<int> nums2){
        int nums1Ptr = 0, nums2Ptr = 0;
        while(nums1Ptr < nums1.size() && nums2Ptr < nums2.size()){
            if(nums1[nums1Ptr] < nums2[nums2Ptr])
                result.push_back(nums1[nums1Ptr++]);
            else
                result.push_back(nums2[nums2Ptr++]);
        }
        
        while(nums1Ptr < nums1.size())
            result.push_back(nums1[nums1Ptr++]);
        
        while(nums2Ptr < nums2.size())
            result.push_back(nums2[nums2Ptr++]);
    }
    
    double calculateMedian(vector<int> result){
        double average = 0;
        int resultSize = result.size();
        // if odd, return middle element
        if(resultSize % 2 != 0)
            return(result[resultSize/2]);
        
        // else return average of middle and middle+1
        average = (double) (result[resultSize/2] + result[(resultSize/2) - 1]) /2;
        return(average);
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        
        // merge the two arrays into 1
        mergeArrays(result, nums1, nums2);
            
        // find the median of the result array
        return calculateMedian(result);
    }
};