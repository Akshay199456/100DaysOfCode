/*
-------------------------Question:

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

/*
-------------------------My Approaches:

1. Double for loop to find the max for each index of the array

This approach uses a double for loop to fond the max for each index of the array spanning the 
whole array from that index. If that exceeds the max_total, the difference between the value at
current index and the value at the index of the element is the new max.

Time complexity: O(n^2)
Space complexity: O(1)
*/

/*
-------------------------Other approaches

1. One pass through the array[Best]

In order to get the result in a single pass, we want to make sure that maximize the value of
prices[j] - prices[i] in a single pass. In addition, the price at which we sell the stock must
be greater than the price at which we buy the stick which means that the min profit must always be
0. 

If you plot the points on a graph, you want to find the greatest diff between a valley and a peak
starting from the valley to maximize the profit. If you encounter the next valley, you repeat the 
same till you get the global max profit.

Time complexity: O(n)
Space complexity: O(1)


2. Adopting Kadane's algorthm [Same as above]


We can perform an adoptation of kadane's algorithm to get the answer to this problem so let's step
through the logic.

If our array is [a0,a1,a2,a3,a4] and if the max exists b/w a4 and a1, our solution is given by
a4 - a1

If we have an array b = [b0,b1,b2,b3,b4] where b[i] = 0 if i = 0 and b[i] = a[i] - a[i-1], we are
looking for the sum b2+b3+b4. This is because:

b2 = a2 - a1;
b3 = a3 - a2;
b4 = a4 - a3;

b2 + b3 + b4 = (a2-a1) + (a3-a2) + (a4-a3) = a4 - a1 which is the solution we are looking for.
Thus, we are looking for the max continuous subarray to get the max profit which is nothing but 
Kadane's algorithm.

Time complexity: O(n)
Space complexity: O(1)
*/



// My Approaches(1)
class Solution {
public:
    int getMaxProfit(vector<int> prices){
        int max_total = 0;
        for(int i = 0; i < prices.size(); i++){
            for(int j = i+1; j < prices.size(); j++)
                if(prices[j] - prices[i] > max_total)
                    max_total = prices[j] - prices[i];
        } 
        return max_total;
    }
    
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        else
            return getMaxProfit(prices);
        
    }
};


// Other Approaches(1)
class Solution {
public:
    int getMaxProfit(vector<int> prices){
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < minPrice)
                minPrice = prices[i];
            else if(prices[i] - minPrice > maxProfit)
                maxProfit = prices[i] - minPrice;
        }
        return maxProfit;
    }
    
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        else
            return getMaxProfit(prices);
    }
};



// Other Approaches(2)
class Solution {
public:
    int getMaxProfit(vector<int> prices){
        int maxCurrent = 0, maxGlobal = 0;
        for(int i  = 1; i < prices.size(); i++){
            maxCurrent = max(0, maxCurrent += prices[i] - prices[i-1]);
            maxGlobal = max(maxCurrent, maxGlobal);
        }
        return maxGlobal;
    }
    
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        else
            return getMaxProfit(prices);
    }
};