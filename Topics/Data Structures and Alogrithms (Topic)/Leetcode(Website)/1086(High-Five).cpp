/*
-------------------------Question:

Given a list of the scores of different students, items, where items[i] = [IDi, scorei] represents one score from a student with IDi, calculate each student's top five average.

Return the answer as an array of pairs result, where result[j] = [IDj, topFiveAveragej] represents the student with IDj and their top five average. Sort result by IDj in increasing order.

A student's top five average is calculated by taking the sum of their top five scores and dividing it by 5 using integer division.

 

Example 1:

Input: items = [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
Output: [[1,87],[2,88]]
Explanation: 
The student with ID = 1 got scores 91, 92, 60, 65, 87, and 100. Their top five average is (100 + 92 + 91 + 87 + 65) / 5 = 87.
The student with ID = 2 got scores 93, 97, 77, 100, and 76. Their top five average is (100 + 97 + 93 + 77 + 76) / 5 = 88.6, but with integer division their average converts to 88.
Example 2:

Input: items = [[1,100],[7,100],[1,100],[7,100],[1,100],[7,100],[1,100],[7,100],[1,100],[7,100]]
Output: [[1,100],[7,100]]
 

Constraints:

1 <= items.length <= 1000
items[i].length == 2
1 <= IDi <= 1000
0 <= scorei <= 100
For each IDi, there will be at least five scores.
*/

/*
-------------------------    My Approaches:
1. Using a custom sort comparator

We can nuse a custome sort comparator in order to sort the array and then select the top 5 scores we are interested in.

Time complexity: O(nlogn)
Space complexity: O(1)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> result;
        
        // sort based on comparator
        sort(items.begin(), items.end(), [] (const auto & lhs, const auto & rhs){
            if(lhs[0] == rhs[0])
                return lhs[1] > rhs[1];
            return lhs[0] < rhs[0];
        });
        
        int lastStudent = items[0][0], count = 1, total = items[0][1];
        
        
        // calculate avg for top 5 scores
        for(int i=1; i<items.size(); i++){
            // if the current student is same as last student seen
            if(items[i][0] == lastStudent){
                // if 5 test scores have still not been seen
                if(count < 5){
                    // cout<<"Adding "<<items[i][1]<<" to total for student "<<items[i][0]<<endl;
                    total += items[i][1];
                    ++count;
                }
            }
            
            else{
                // push the lastStudents avg into the result
                vector<int> list{lastStudent, total / 5};
                result.push_back(list);
                
                // update values to new student
                count = 1, lastStudent = items[i][0], total = items[i][1];
            }
        }
        
        vector<int> list{lastStudent, total / 5};
        result.push_back(list);
        
        return result;
    }
};