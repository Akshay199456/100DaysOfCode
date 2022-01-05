/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/

/*
-------------------------My Approaches:

1. Using a queue to store the elements in the right order

This approach uses a queue. Based on the ordering of the elements, they are inserted into the queue
and once all elements from both the vectors have been put into the queue, we start filling
nums1 with the elements of the queue.

Time complexity: O(m+n)
Space complexity: O(m+n)
*/

/*
-------------------------Other approaches

1. Using two pointers and filling the array from the end of the first array[Best]

While we have solved problems where we use two pointers to compare elements at the beginning of the
arrays and then increment them based on the condition, in this problem it is slightly different but
we can apply the same approach. Since we have empty space at the end of the first array to insert
elements, we will need to adopt our approach to insert elements at the end of the array. This means
that we must compare elements which are the greater of the two and then insert them into the end
of the first array. We must do this till we have inserted all the elements of the second array into
the first or have placed all the elements of the first array which exist at the end. If it's the 
latter, we then add in the remainging elements from the second array into the first


Time complexity: O(m+n)
Space complexity: O(1)
*/

// My Approaches(1)
class Solution {
public:
    void fillVector(vector<int> & nums1, queue<int> numbers){
        int i = 0;
        while(!numbers.empty()){
            nums1[i++] = numbers.front();
            numbers.pop();
        }
    }
    
    void fillQueue(vector<int> nums1, int m, vector<int> nums2, int n, queue<int> & numbers){
        int i = 0, j = 0;
        while(i < m && j < n){
            if(nums1[i] <= nums2[j])
                numbers.push(nums1[i++]);
            else
                numbers.push(nums2[j++]);
        }
        
        if( i == m )
            while(j < n)
                numbers.push(nums2[j++]);
        else
            while(i < m)
                numbers.push(nums1[i++]);
    }
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        queue<int> numbers;
        if(n != 0){
            fillQueue(nums1, m , nums2, n, numbers);
            fillVector(nums1, numbers);
        }     
    }
};


// Other Approaches(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m +n - 1;
        while(i >= 0 && j >=0){
            if(nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
            
        while( j>= 0)
            nums1[k--] = nums2[j--];
    }
};