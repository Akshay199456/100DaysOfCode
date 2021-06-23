/*
-------------------------Question:

ou are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
Example 4:

Input: coins = [1], amount = 1
Output: 1
Example 5:

Input: coins = [1], amount = 2
Output: 2
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/

/*
-------------------------    My Approaches:
1. Using DP just like Coin Change 2 but here each cell stores the least number of coins to make that amount

We can apply the same techniues we laernt in Coing Change 2. But, here, we use the fewest number of coins that can be made for a certain amount and certain amount of coins into each cell. That eventually builds up to the final
answer.

Time complexity: O(kn) where k is the amount and n is the no of coins available
Space complexity: O(kn)

2. Improvemnt on My Approaches(1)

If we observe My Approaches(1), we only use the last row at max, so we don't need to store a table. We can just store the prevRow into a list and record its value at the end of a particular value of i.

Time complexity: O(kn)
Space complexity: O(k)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    void createTable(vector<vector<int>> & dpTable, vector<int> & coins, int amount){
        for(int i=0; i<= coins.size(); i++){
            vector<int> list;
            for(int j=0; j<=amount; j++){
                if(j == 0)
                    list.push_back(0);
                else if(i==0)
                    list.push_back(INT_MAX);
                else{
                    int temp = dpTable[i-1][j];
                    if(j < coins[i-1]){
                        if(temp == INT_MAX)
                            list.push_back(INT_MAX);
                        else
                            list.push_back(temp);
                    }
                    else{
                        if(list[j-coins[i-1]] == INT_MAX)
                            list.push_back(temp);
                        else
                            list.push_back(min(1+ list[j - coins[i-1]], temp));
                    }
                }
            }
            dpTable.push_back(list);
        }
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dpTable;
        createTable(dpTable, coins, amount);
        if(dpTable[coins.size()][amount] == INT_MAX)
            return -1;
        return dpTable[coins.size()][amount];
    }
};

// My Approaches(2)
class Solution {
public:
    int getFewestCoins(vector<int> & coins, int amount){
        vector<int> prevRow;
        for(int i=0; i<= coins.size(); i++){
            vector<int> currRow;
            for(int j=0; j<=amount; j++){
                if(j == 0)
                    currRow.push_back(0);
                else if(i==0)
                    currRow.push_back(INT_MAX);
                else{
                    if(j < coins[i-1] || currRow[j-coins[i-1]] == INT_MAX)
                        currRow.push_back(prevRow[j]);
                    else
                        currRow.push_back(min(1+ currRow[j - coins[i-1]], prevRow[j]));
                }
            }
            prevRow = currRow;
        }
        int temp = prevRow[prevRow.size()-1];
        return temp == INT_MAX ? -1 : temp;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        return getFewestCoins(coins, amount);
    }
};