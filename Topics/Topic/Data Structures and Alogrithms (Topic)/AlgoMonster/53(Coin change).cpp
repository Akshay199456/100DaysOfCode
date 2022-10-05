/*
Problem statement:

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

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
1. Combinatorics

    we can use combinaotircs in order to solve this problem. at any step, we can use one of all the different types of coins 
    we have. as a result, we use that to generate all possible combinatioons of coins. if our sum exceeds the amopunt or if we have mincoins set and the current coint of coins is more than mincoins, 
    then we step the recusion. else we add the current coin to sum, increase the count and call recursively.

    Time complexity: O()
    Space complexity: O()
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
#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

void getMinCoins(std::vector<int> & coins, int amount, int & minCoins, int sum, int count){
    // if sum > amount, we stop
    if(sum > amount)
        return;
    else if(sum == amount){
        // if sum == amount
        if(count < minCoins)
            minCoins = count;
        return;
    }
    // if minCoins is set and number of coins exceeds it
    else if((minCoins != std::numeric_limits<int>::max()) && (count > minCoins))
        return;
    
    
    for(int i=0; i<coins.size(); i++)
        getMinCoins(coins, amount, minCoins, sum + coins[i], count+1);
}


int coin_change(std::vector<int> coins, int amount) {
    // WRITE YOUR BRILLIANT CODE HERE
    int minCoins = std::numeric_limits<int>::max();
    if(!amount)
        return 0;
    getMinCoins(coins, amount, minCoins,0,0);
    if(minCoins == std::numeric_limits<int>::max())
        return -1;
    return minCoins;
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<int> coins = get_words<int>();
    int amount;
    std::cin >> amount;
    ignore_line();
    int res = coin_change(coins, amount);
    std::cout << res << '\n';
}



//  Other Approaches(1)
