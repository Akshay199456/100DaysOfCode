/*

-------------------------Question:

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

/*
-------------------------    My Approaches:

1. 

    This seems to be the best approach to the problem. It uses greedy algorithms to find the local maximum and
    adds those results. It continues this till the end of the array in the hope that adding the local
    maximum gives the global maximum.

    Space complexity: O(1)
    Time complexity: O(n)
*/

/*
-------------------------    Brute force approach: 

1. (Worse)

    Find all posibble solutions and calculate the max profit from them
    Time complexity: O(n^n)
    Space complexity: O(n) for recursion calls
*/

/*
-------------------------    Other approaches:

1. (Same)

    There is another approach that is based on the approach that I used. Instead of adding the total
    at each index when start > curr or start <= curr <= end, we can just keep adding whenever we discover
    a peak-valley pair(nums[i] > nums[i-1]). This approach still adds the results like the previous
    one but does so in fewer steps

    Approach 3: Simple One Pass
    
    Algorithm

    This solution follows the logic used in Approach 2 itself, but with only a slight variation. In this case, instead of looking for every peak following a valley, we can simply go on crawling over the slope and keep on adding the profit obtained from every consecutive transaction. In the end,we will be using the peaks and valleys effectively, but we need not track the costs corresponding to the peaks and valleys along with the maximum profit, but we can directly keep on adding the difference between the consecutive numbers of the array if the second number is larger than the first one, and at the total sum we obtain will be the maximum profit. This approach will simplify the solution. This can be made clearer by taking this example:

    [1, 7, 2, 3, 6, 7, 6, 7]

    The graph corresponding to this array is:

    Profit Graph

    From the above graph, we can observe that the sum A+B+CA+B+C is equal to the difference DD corresponding to the difference between the heights of the consecutive peak and valley.

    Time complexity: O(n)
    Space complexity: O(1)
*/

// My Approach(1)
class Solution {
public:
    void setParameters(int & start, int &end, int &current , int &total){
        total += end - start;
        start = current;
        end = current;
    }
    
    int maxProfit(vector<int>& prices) {
        if((prices.size() == 0) || (prices.size() == 1))
            return 0;
        else{
            int start = prices[0], current = 0, end = prices[0], total = 0;
            for(int i = 1; i<prices.size(); i++){
                current = prices[i];
                if(start > current){
                    setParameters(start, end, current, total);
                }
                else if(end < current)
                    end = current;
                else if((start <= current) && (current <= end)){
                    setParameters(start, end, current, total);          
                }
            }
            total += end - start;
            return total;
        }
    }
};



// Other Approaches(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1])
                maxprofit += prices[i] - prices[i - 1];
        }
        return maxprofit;
    }
};