/*
-------------------------Question:

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/

/*
-------------------------My Approaches:

*/

/*
-------------------------Other approaches

This problem is a very good problem to understnad how to solve a DS problem with the right steps. This is very much in
accordance with the Cracking the Code Interview steps (pg 62). Each approach in this problem was based on the previous
approach. The brute force approach helped us understand how to solve the problem however inefficeint it was. The optimization
over it using DP targeted the bottleneck in the first appraoch by claculating th emax before hand. The optimization in the
final approach built upon the DP approach by fixing its bottleneck to solve the problem without using the arrays and 
understading how the result's value was being decided. 

1. Brute Force

All the otehr approaches can be used to imporve upon this current approach once you understand how the solve the problem
in brute force. The ley to understand here is that, to know what's the max value that can  be stored in a particular
index, we need to know the max that is available on the left and the max on the right. These maxes on the elft and right
decide the amount of water the current index can hold. The amount of water the current index can hold can be understood
by min(leftMax, rightMax) - height[currentIndex]. In the brute force, we use two loops to get that info.

Time complexity: O(n^2)
Space complexity: O(1)


2. Dynamic Programming

If we obnserse the proveious approach, we see that we are caculating the left max and the right max for each index that
we have in the array. If we take two arrays for leftMax and rightMax, we can do precalculations to store that information
before hand itself. In the main loop, we will thenn only to calcualte the difference between the min of two and the height
of the current index.

Time complexity: O(n)
Space complexity: O(n)


3. Two pointer approach

We can also use two poitner appraoch to solve this problem. IF we observe the max from the arrays from the previous 
approach, we notice that before the global max, the min is decided by the leftMax while after the global max in the array,
the min is determined by the rightMax since in the former,we will only have the globalMax after the index where the global
max is and in the latter,t he globalMax will be the one filled intot he array till the index of the global index is hit.
We can therefore, use this knowledge to adjust our poitners accordingly and calcualte the result.

Time complexity: O(n)
Space complexity: O(1)
*/


// Othe Approaches(1)
class Solution {
public:
    int getTrap(vector<int> height){
        int result = 0;
        for(int i = 0; i < height.size(); i++){
            int leftMax = -1, rightMax = -1;
            // getting max value on the left
            for(int j = 0; j <=i; j++)
                leftMax = max(leftMax, height[j]);
            
            // getting max value on the right
            for(int j = i; j < height.size(); j++)
                rightMax = max(rightMax, height[j]);
            
            result += min(leftMax, rightMax) - height[i];
        }
        return result;
    }
    
    int trap(vector<int>& height) {
        if(height.size() == 0 || height.size() == 1)
            return 0;
        else
            return getTrap(height);
    }
};


// Other Approaches(2)
class Solution {
public:
    int getTrap(vector<int> height){
        vector<int> leftMax(height.size(), -1);
        vector<int> rightMax(height.size(), -1);
        leftMax[0] = height[0];
        rightMax[height.size() -1] = height[height.size() - 1];
        int result = 0;
            
        // build leftMax
        for(int i = 1; i < height.size(); i++)
            leftMax[i] = max(height[i], leftMax[i-1]);
        
        // build RightMax
        for(int i = height.size() - 2; i >= 0; i--)
            rightMax[i] = max(height[i], rightMax[i+1]);
        
        // get result
        for(int i = 0; i < height.size(); i++)
            result += min(leftMax[i], rightMax[i]) - height[i];
        
        return result;
    }
    
    int trap(vector<int>& height) {
        if(height.size() == 0 || height.size() == 1)
            return 0;
        else
            return getTrap(height);
    }
};



// Other Approaches(3)
class Solution {
public:
    void getMaxAndIndex(vector<int> height, int & max, int & maxIndex){
        for(int i = 1 ; i < height.size(); i++){
            if(height[i] > max){
                max = height[i];
                maxIndex = i;
            }
        }
    }
    
    int getTrap(vector<int> height){
        int max = height[0], maxIndex = 0, result = 0;
        int leftMax = height[0], rightMax = height[height.size() - 1];
        int left = 0, right = height.size() - 1;
        getMaxAndIndex(height, max, maxIndex);
        
        while(left < right){
            // if the current index is less than max index, result decided from left
            if(left < maxIndex){
                if(height[left] > leftMax)
                    leftMax = height[left];
                result += leftMax - height[left];
                left++;
            }
            
            else{
                if(height[right] > rightMax)
                    rightMax = height[right];
                result += rightMax - height[right];
                right--;
            }
        }
        return result;
    }
    
    int trap(vector<int>& height) {
        if(height.size() == 0 || height.size() == 1)
            return 0;
        else
            return getTrap(height);
    }
};