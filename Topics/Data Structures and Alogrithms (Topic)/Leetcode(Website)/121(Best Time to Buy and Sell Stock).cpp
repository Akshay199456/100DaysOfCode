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


// Other Approaches(1)[Doesn't work]
class Solution {
public:
    int getMaxProfit(vector<int> prices){
        int best_buy, best_sell, max_profit = 0;
        best_buy = best_sell = prices[0];
        for(int i= 1; i < prices.size(); i++){
            if(prices[i] - best_buy > max_profit)
                best_sell = prices[i];
            else if(prices[i] < best_buy && max_profit == 0)
                best_buy = best_sell = prices[i];
            
            max_profit = best_sell - best_buy;
        }
        return max_profit;
    }
    
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        else
            return getMaxProfit(prices);
    }
};