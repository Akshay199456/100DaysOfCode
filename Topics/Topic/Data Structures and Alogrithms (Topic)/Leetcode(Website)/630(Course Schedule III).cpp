/*
-------------------------Question:

There are n different online courses numbered from 1 to n. Each course has some duration(course length) t and closed on dth day. A course should be taken continuously for t days and must be finished before or on the dth day. You will start at the 1st day.

Given n online courses represented by pairs (t,d), your task is to find the maximal number of courses that can be taken.

Example:

Input: [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
Output: 3
Explanation: 
There're totally 4 courses, but you can take 3 courses at most:
First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day.
Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day. 
Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day. 
The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.
 

Note:

The integer 1 <= d, t, n <= 10,000.
You can't take two courses simultaneously.
*/

/*
-------------------------    My Approaches:

*/

/*
-------------------------    Other approaches:

1. Greedy Approach

Just a sidenote here before we begin. I had initially figured out that we had to sort by the end day as well as come up with a test case that violated our theory till then. I should have pushed just a little bit forward and if so, I
would have figured out the solution to the problem on my own. I am continusoly observing that I am on the right path for most of the solutions when I do give up and if I just analyze the test cases or add more test cases, I can hit a home run here.
Anyways, back to the problem:

We can apply a greedy approach here in order to solve the problem. Once we sort the courses by the end date, it provides us with a good ability to select the courses. We want to sort by the end date as that alolows to maximize our
intake of courses by the final end date. In addition, for a new course that we are trying to add, we want to make one of 2 checks. If we can add the new course automatically with the new end date, then we go ahead and add it.
However, if we are unable to add it due to the presence of other courses, in that case, we want to replace our most time consuming course with the current course. This is because, by adding the new course we have two advantages.
We know that the new course will have a greater or equal to end date than the one it is replacing. In addition, because we are replacing the most time consuming course that tis greater than the current course, we can add more courses
going into the future since we will have more leeway to add moe courses. This is the principle of greedy approach in this problem.

Time complexity: O(n^2)
Space complexity: O(1)


2. Using prioirty_queue to optimize

The bottleneck in the previous approach was that if the current course could not be added, we would check the current course with all the prvious courses which were considered leading to O(n^2) time complexity. We can get rid of that by instead
using a max heap to keep hold of the max and evaluate it against that. This is practically what wehat we were interested in the previous approach.

Time complexity: O(nlogn)
Space complexity: O(1)
*/

// Other Approaches(1)
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int currentTime = 0, nCourses = 0;
        
        // sort courses by end day
        sort(courses.begin(), courses.end(), [this](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        
        for(int i=0; i<courses.size(); i++){
            // if a course can be added within the duration
            if(currentTime + courses[i][0] <= courses[i][1]){
                currentTime += courses[i][0];
                nCourses++;
            }  
            //else if it can't, we want to compare to a differnt cours which has already been selected that has a duration greater than the duration of the current course
            else{
                int position = i;
                for(int j=0; j<i; j++){
                    if(courses[j][0] != -1 && courses[j][0] >= courses[position][0])
                        position = j;
                }
                
                if(position != i)
                    currentTime -= (courses[position][0]-courses[i][0]);
                courses[position][0] = -1;
            }
        }
        return nCourses;
    }
};



// Other Approaches(2)
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int currentTime = 0, nCourses = 0;
        priority_queue<pair<int,int>> elements;
        
        // sort courses by end day
        sort(courses.begin(), courses.end(), [this](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        
        for(int i=0; i< courses.size(); i++){
            if(currentTime + courses[i][0] <= courses[i][1]){
                currentTime += courses[i][0];
                nCourses++;
                elements.push(make_pair(courses[i][0], courses[i][1]));
            }
            else{
                if(!elements.empty() && elements.top().first >= courses[i][0]){
                    currentTime -= (elements.top().first - courses[i][0]);
                    elements.pop();
                    elements.push(make_pair(courses[i][0], courses[i][1]));
                }
            }
        }
        return nCourses;
    }
};