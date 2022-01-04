/*

/*
-------------------------    My Approaches:

1. Using hashset to store results 

We can use ahashset instead of a hashmap as it conserves some amount of space compared to our previous solution.

Time complexity: O(n)
Space complexity: O(n)
*/

/*
-------------------------    Brute force approach: 
*/

// My approaches(1)
#include <vector>
using namespace std;

vector<int> getResult(vector<int> & array, int & targetSum){
	vector<int> result;
	unordered_set<int> elementSet;
	
	for(int i=0; i< array.size(); i++){
// 		if element is found in the set
		if(elementSet.find(array[i]) != elementSet.end())
			result.insert(result.end(), {array[i], targetSum - array[i]});
		else
			elementSet.emplace(targetSum - array[i]);
	}
	return result;
}

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	if(array.size() < 2)
		return {};
	return getResult(array, targetSum);
}
