/*
-------------------------Question:

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/

/*
-------------------------My Approaches:

1. Using map to store occurrences

We can use the map to store the number of occurences of each number in the vector. After every entry, we
check if it exceeds the threshold of n/2 and if it does, we return that element. Since the list is 
guarantted to have a solution, we don't have to worry about elsewise.

Time complexity: O(n)
Space complexity: O(n)

*/

/*
-------------------------Other approaches

1. Sorting the array[Worse]

We can sort the array and return the mid element. This will always guarantee to hold the element that
occurs more than n/2 as long as there is an element that exceeds it. Check 'Helping Images' for more info
on this approach. 

As can be seen in the 'Helping Images', if the majority element exists in the beginning of the array,
it will always exist at the mid and/or exceed it towards the end of the array. If the majority element
exists at the end of the array, it will always exist at the mid and/or exceed it towards the beginning of
the array. If it exists anywhere in between, the line will always cross over the middle and hence irrespective
of where the majorith element exists, it will always be in the middle of the array.

Time complexity:O(nlogn)
Space complexity: O(1)


2. Divide and Conquer[Worse]

We can use the divide and conquer approach to solve this problem. For the divide part, we keep dividing the
left and right subarray till we hit a single element. 

Once we hit a single element we can then compare the results we obtained from left and right. If they are 
the same, we know that the majority element will be the left/right from beg to end so we can return it. 
However, if they are not the same, we make the check in the array from beg to end to see which element 
occurred the max number of times and return that. This becomes the conquer approach.

Since we are dividing recursively and for each element running O(n) search on it, our time complexity is
O(nlogn) while our space complexity is O(log n) as the recusive call proceeds to O(log n) in depth.

Time complexity: O(nlogn)
Space complexity: O(logn) -> recursive call structure


3. Boyer Moore Voting Algorithm[Best]

This algorithm is very helpful in finding the majority element in a sequence in O(n) time and O(1) space.
The key thing to undestand about this approach is that it selects a suffix and makes check with a count
to determine if it's the majority element. Check out [Helping Images] for more info on this approach

Let's try to understand this approach with examples:

A. In this case, the candidate element initially chosen is the majority element

[7, 7, 5, 7, 5, 1 | 5, 7 | 5, 5, 7, 7 | 7, 7, 7, 7]

Let's assume that is our array, with the | used to indicate the points at which count drops to 0. In this
case 7 is the majority element. Since 7 is the first element, we select that as our candidate and keep
that as our candidate until the count of it hits 0. For any element that equals it we increment by 1 and
for any element that deosn't equal it, we decrement it by 1. At index 5, our count hits 0. As a result,
we use the next index as the candidate and make the same check till the end of the array. The reason we can
choose to ignore the previous candidate is because, if 7 is our majority element in general, we would be
getting rid of an equal number of majority and minority elemenets, the majority element will continue
to eb the majority element since we have removed an equal number. As a result, we can keep making the 
checks as we initially did till the end of the array cause at the end of the array we will always hit a 
majority element.

B. In this case, the candidate element initially chosen is not eh majority element

[7, 7, 5, 7, 5, 1 | 5, 7 | 5, 5, 7, 7 | 5, 5, 5, 5]

We continue the same procedure as last time. In this case, at the index 5, we have not removed more
majority elements than minority elements. As a result, even in this case where our candidate is not the 
majority element, we are not removing more majority elements than minoruty elements. This means the 
majority element will continue to be the majority element throughout the rest of thea rray.

This, irrespective of whether our candidate is the majority or the minority, we will always be either
removing more minority than majority or an equal number. Since the majority removed will never be more
than the minority removed, it means that at the end of the array, we will always have the element that is
the majority. 

Time complexity: O(n)
Space complexity: O(1)

We can also modify this algorithm to accomodate the condition if there is no element that is the majority
by running the final candidate after the array run through a loop and checking its count in the original
array. If it's less than n/2, there's no majority element in the array else the candidate is the majority
element.
*/


// My Approaches(1)
class Solution {
public:
    int getMajorityElement(vector<int> nums, int threshold){
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            auto it = map.find(nums[i]);
            if(it == map.end())
                map[nums[i]] = 1;
            else
                map[nums[i]]++;
            
            if(map[nums[i]] > threshold)
                return nums[i];
        }
        return -1;
    }
    
    int majorityElement(vector<int>& nums) {
        int threshold = nums.size() / 2;
        return getMajorityElement(nums, threshold);
    }
};


// Other Approaches(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];     
    }
};


// Other Approaches(2)
class Solution {
public:
    int getCount(vector<int> nums, int element, int beg, int end){
        int count = 0;
        for(int i = beg; i <= end; i++){
            if(nums[i] == element)
                ++count;
        }
        return count;
    }
    
    int getMajorityElement(vector<int> nums, int beg, int end){
        if(beg == end)
            return nums[beg];
        
        int mid = (end - beg) / 2 + beg;
        int left = getMajorityElement(nums, beg, mid);
        int right = getMajorityElement(nums, mid+1, end);
        
        if(left == right)
            return left;
        else{
            int leftCount = getCount(nums, left, beg, end);
            int rightCount = getCount(nums, right, beg, end);
            return leftCount > rightCount ? left : right;
        }
    }
    
    int majorityElement(vector<int>& nums) {
        return getMajorityElement(nums, 0, nums.size() - 1);
    }
};


// Other Approaches(3)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int suffix = nums[0], count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(!count){
                suffix = nums[i];
                count = 1;
            }
            else{
                if(nums[i] == suffix)
                    ++count;
                else
                    --count;
            }
        }
        return suffix;
    }
};