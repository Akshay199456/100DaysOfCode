/*

/*
-------------------------    My Approaches:

1. Using hashset to store results 

We can use ahashset instead of a hashmap as it conserves some amount of space compared to our previous solution.

Time complexity: O(n)
Space complexity: O(n)
*/

/*
-------------------------    Other Approaches 
1. Sorting and using two pointer technique

with this appraoch, you can sort ehe original array so that the elements are now in sorted order. once they are in sorted order, you can assign one pointer at the beginning of the array and the other pointer at the end of the array.As long the sum is less than the target, you keep moving th eleft pointer right and if the sum if greater than the target, then you keep moving the right pointer left. We continue this till we hoit our target sum or left crosses over right

Time complexity: O(nlogn)
Space complexity: O(1)
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


