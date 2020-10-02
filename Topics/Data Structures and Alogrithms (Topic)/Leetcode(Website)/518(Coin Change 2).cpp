/*
-------------------------Question:

You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

 

Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10] 
Output: 1
 

Note:

You can assume that

0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer
*/

/*
-------------------------My Approaches:

*/

/*
-------------------------Other approaches

1. DP Approach - Bottom up

This problem can be solved using DP approach as it has a recusrive substructure and we can extend the solution from each
sub problem to the next sub problem to give us the whole solution. This problem is a classic knapsack problem where you
have a given amount to achieve and a list of options and we have to find the no of ways. Given that we have unlimited choices
for each coin.

To understand how to construct thee table/list, let us think about the basic base case. How can we construct each of the
amounts from 0 - n given an empty coin collection. Well, there is onlyt 1 way to cinstruct 0 given no coins and 0 ways
to construct the rest of the elements. The next immediate negihboring case would be to build these elements from a coin of
1. When building from every other case, we can either choose to use the new coin that we have to buil;d the current amount
or choose not to use it. If we choose, not to use it, then the no of ways would be equal to the no of wasy to genereate
the same amount without using this new coin which would be dpTable[i-1][j].

If we choose to use the new coin, then the no of ways would depend on the no of ways it takes to build the 
dpTable[i][j - coins[i-1]] as using the new coin would leave us with j - coins[i-1] amount to be constructed with the 
same set of coins. During this step, if our amount is less than the coin value, then there is no way to build this amount
with the new coin so we would return the no of ways as 0.

This gives us the recursive formula:

dpTable[i][j] = dpTable[i-1][j] + dpTable[i][j-coins[i-1]]

Time complexity: O(n*k)
Space complexity: O(n*k)

where n-> total amunt given to us and k-> no of coins



2. Improvement of bottom up approach

If we notice in the Other Approaches(1), we can see theat there exists a bottle neck. We only use at most the previous row
or the same row itslef. This means that we are not using any of the other rows given to us. As a result, we don't need to
keep track of the values using a matrix and can use a list instead to keep track of the entries. For the previous row,
our list will already be holding its value from it when we move to the next row. For the same row, we will just be
accessing a value earlier in the list. That's where the improvment comes in for this approach.

We just use a single list to hold the values as we are going along.

Time complexity: O(n*k)
Space complexity: O(n)
*/

// Other Approaches(1)
class Solution {
public:
    vector<vector<int>> dpTable;
    
    int change(int amount, vector<int>& coins) {
        int nRows = coins.size() + 1, nCols = amount + 1;
        for(int i = 0; i < nRows; i++){
            vector<int> list;
            for(int j = 0; j < nCols; j++){
                if(i == 0){
                    if(j == 0)
                        list.push_back(1);
                    else
                        list.push_back(0);
                }
                
                else{
                    // we can choose to use the new coin or choose not to
                    int temp = 0;
                    if(coins[i-1] <= j)
                        temp = list[j - coins[i-1]];
                    list.push_back(dpTable[i-1][j] + temp);
                }
                
            }
            dpTable.push_back(list);
        }
        return dpTable[nRows-1][nCols-1];
    }
};


// Other Approaches(2)
class Solution {
public:
    vector<int> dpList;
    
    int change(int amount, vector<int>& coins) {
        int nRows = coins.size() + 1, nCols = amount + 1;
        
        for(int i = 0; i < nRows; i++){
            for(int j = 0; j < nCols; j++){
                if(i == 0){
                    if(j == 0)
                        dpList.push_back(1);
                    else
                        dpList.push_back(0);
                }
                
                else{
                    // we can choose to use the new coin or choose not to
                    int temp = 0;
                    if(coins[i-1] <= j)
                        temp = dpList[j - coins[i-1]];
                    dpList[j] += temp;
                }
            }
        }
        return dpList[nCols-1];
    }
};