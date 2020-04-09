/*
-------------------------Question:

Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
*/

/*
-------------------------Other approaches

1. Brute Force

The brute force approach is to store the original array when the constructor is called. So, when
reset is called, we can simply pass the original vector.

reset():

Space complexity: O(1)
Time complexity: O(1)

constructor():
Space complexity: O(n)
Time complexity: O(n)

For shuffle, we can generate random numbers from a clone of the original array and push those elements
into a randomArray as well removing those elements from the cloneArray. We do this for all the
elements of the cloneArray

Time complexity: O(n^2) since removing an element from an array takes O(n) time for each element
so for n elements, it will take O(n^2) time

Space complexity: O(n)
*/


// Other Approaches(1)
class Solution {
public:
    vector<int> array;
    Solution(vector<int>& nums) {
        this->array = nums;
        srand(time(NULL));
    }
    
    void printVector(vector<int> nums){
        cout<<"----- Printing vectors -----\n";
        for(int i = 0; i < nums.size(); i++)
            cout<<nums[i]<<" ";
        cout<<endl<<"----------";
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return this->array;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> randomArray, cloneArray;
        cloneArray = this->array;
        int length = cloneArray.size();
        for(int i = 0; i < length; i++){
            int index = rand() % cloneArray.size();
            randomArray.push_back(cloneArray[index]);
            cloneArray.erase(cloneArray.begin() + index);
        }
        return randomArray;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

