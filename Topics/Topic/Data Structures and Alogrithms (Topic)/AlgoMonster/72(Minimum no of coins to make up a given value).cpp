/*
Problem statement:

You are given coins of different denominations and an amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
Input: coins = [1, 2, 5], amount = 11

Output: 3

Explanation:
11 = 5 + 5 + 1, 3 total coins

Example 2:
Input: coins = [3], amount = 1

Output: -1
*/

/*
-------------------------    My Approaches:
1. DFS approach[Not coded]

    The first approach is the normal DFS approach where we generate the state-space tree. at each step to make up the amount,
    we have the chocies to choose any of the coins. if the total sum crosses over the target amount, then that amount cant be made and we stop the recursion thre.
    if the sum we made form the coins is equal to the target amount, then we return the total no of coins it took to make the amount.

    Time complexity: O()
    Space complexity: O()


2. BFS approach [Not coded]
    another way we can solve this problem is using BFS. we know at each step, the choices we ahve depends on the coins we have. as a result, if we use DFs,
    we will apporach the solution the quickest if it exists. if it deos not, then we return -1



3. Memoization approach [not coded]
    From Ny Approaches(1), we can obverve that the same amount comes up many times in different subtrees. as a result, we can store the min no of coins we have seen till then when we reach an amount. 
    This way we prevent duplicate calculations from taking place
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes


    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)



//  Other Approaches(1)
