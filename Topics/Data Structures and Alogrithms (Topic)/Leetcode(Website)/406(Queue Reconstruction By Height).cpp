/*
-------------------------Question:

You are given an array of people, people, which are the attributes of some people in a queue (not necessarily in order). Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki other people in front who have a height greater than or equal to hi.

Reconstruct and return the queue that is represented by the input array people. The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).

 

Example 1:

Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
Explanation:
Person 0 has height 5 with no other people taller or the same height in front.
Person 1 has height 7 with no other people taller or the same height in front.
Person 2 has height 5 with two persons taller or the same height in front, which is person 0 and 1.
Person 3 has height 6 with one person taller or the same height in front, which is person 1.
Person 4 has height 4 with four people taller or the same height in front, which are people 0, 1, 2, and 3.
Person 5 has height 7 with one person taller or the same height in front, which is person 1.
Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed queue.
Example 2:

Input: people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
Output: [[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]
 

Constraints:

1 <= people.length <= 2000
0 <= hi <= 106
0 <= ki < people.length
It is guaranteed that the queue can be reconstructed.
*/

/*
-------------------------    My Approaches:
1. Sorting by nof of people ahead in quwue and then putting element in place

If we sort the the people by their order in the queue, we have a good starting point. After sorting, this vector now represents how the people would be ordered in the queue depending on the number of people ahead of them. People who have
a 0 will be at the beginning of the queue while those with the max would ideally be at the end of the queue. Once we have this information, we need to insert the elements into place. As a result, for each element we insert into the new
vector, we want to leep track of the index where the elemnt in people would lie depending on how many people are ahead for that particualr person. As a result, this helps us solve the problem

Time complexity: O(n^2)
Space complexity: O(n)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    void insertIntoPlace(vector<vector<int>> & result, vector<vector<int>> people){
        for(int i=0; i<people.size(); i++){
            int count = 0, j=0, lastIndex = -1;
            bool isEnd = false;
            for(; j<result.size() && !isEnd; j++){
                if(people[i][0] <= result[j][0]){
                    ++count;
                    lastIndex = j;
                }
                if(count == people[i][1] + 1)
                    isEnd = true;
            }
            if(isEnd)
                result.insert(result.begin() + lastIndex, people[i]);
            else 
                result.push_back(people[i]);
        }
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> result;
        sort(people.begin(), people.end(), [this] (vector<int> people1, vector<int> people2){
           return people1[1] < people2[1]; 
        });
        insertIntoPlace(result, people);
        return result;
    }
};