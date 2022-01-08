/*

/*
-------------------------    My Approaches:

1. Two pointer approach

use the two pointer approach here in order to solve the problem. since we know that that integers cna be either
positive or negative and we also lknow that the elements that wll contribute to the largest element will always be from the 
ends of the array since the array will be in sorted order. so if the arrya has negative elements in the beginning
and poisitive ekements int hee end, the competition between the two will decide whose square will be
larger sinbce square of botha anegative and positive number are positive.

Using think knowledge , we then fill an additional raays of the same size from the back of the array
and keep filling it with larger of the two pointers. if the element with the left pointer has greater square,
we push th left pointer forward else we push the right ptr backward. we contineue to do this till all the elements
have been covered and the left pointer is ahead of the right pointer

Time complexity: O(n)
Space complexity: O(n)
*/

/*
-------------------------    Other Approaches 
1.

/*
-------------------------    Video Explanation 
whenever a problem is given like this and it is specified that is sorted or ina  aparticular order, that is a pretty good indication that you should be able 
to solve in in a complexity better than the bruite force solutions, possibly even linear time.

*/


// My approaches(1)
#include <vector>
using namespace std;

vector<int> getResult(vector<int> & array){
	vector<int> sortedArray(array.size());
	int left = 0, right = array.size()-1, sortedPtr = array.size() - 1;
	while(left <= right){
		int leftValue = array[left] * array[left];
		int rightValue = array[right] * array[right];
		
		if(leftValue > rightValue){
			sortedArray[sortedPtr--] = leftValue;
			left++;
		}
		else{
			sortedArray[sortedPtr--] = rightValue;
			right--;
		}
	}
	return sortedArray;
}

vector<int> sortedSquaredArray(vector<int> array) {
  // Write your code here.
  return getResult(array);
}


// Other Approaches(1)