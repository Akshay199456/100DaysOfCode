/*

/*
-------------------------    My Approaches:

1. using two pointer technique

This approach uses the two pointer technique to solve the problem. we put one ppointer on the array and th eother on the sequence.
we only move the pointer on the sequence move forward if there is a match with the eleement on the array.
if no match, we move the pointer on the array forward. we continue this process ill either the pointer on the
array or sequence has reached at the end. we then check if the pointer for the sequence has reached the end.
if it has, we know that we saw all the element sin the sequence in the array in the intended order whcich
validates it asa a sequence.

Time complexity: O(n)
Space compleixty: O(1)
*/

/*
-------------------------    Other Approaches 
1.

/*
-------------------------    Video Explanation 

*/


// My approaches(1)

using namespace std;

bool checkSubsequence(vector<int> & array, vector<int> & sequence){
	int arrayPtr = 0, sequencePtr = 0;
	while(arrayPtr < array.size() && sequencePtr < sequence.size()){
		if(array[arrayPtr] == sequence[sequencePtr])
			sequencePtr++;
		arrayPtr++;
	}
	
	if(sequencePtr == sequence.size())
		return true;
	return false;
}

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  // Write your code here.
	return checkSubsequence(array, sequence);
}


// Other Approaches(1)