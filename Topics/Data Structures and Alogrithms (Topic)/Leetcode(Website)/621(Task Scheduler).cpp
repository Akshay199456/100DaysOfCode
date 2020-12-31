/*
-------------------------Question:

Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: 
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.
Example 2:

Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.
Example 3:

Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation: 
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
 

Constraints:

1 <= task.length <= 104
tasks[i] is upper-case English letter.
The integer n is in the range [0, 100].
*/

/*
-------------------------    My Approaches:

*/

/*
-------------------------    Other approaches:
1. Greedy approach

One of the ways we can solve this problem is by using the greedy approach. If we analyze the problem, we can see that the total number of CPU intervals depends on 2 factors: 
(1) The no of busy intervals
(2) the no of idle intervals

The sum of these two gives the toal no of intervals required by the CPU. (1) is easy to find as it is the total no of intervals taken by the tasks. 
To find (2), we need to obtain the no of idle intervals remaining at the end of all the tasks. We can get a starting point by analyzing the highest frequency task. This will dictate the initial no of idle intervals as it is given by
(fMax -1)*n. 

We continue to do this with the other tasks as well in the order in which their frequency occurs with the highest frequency being first. As a result, this is a greedy approach as we are choosing the best approach for each task which
gives the optimum solution to the problem. For every other task other than the max task, we keep deducting from the idelCount and set it accordingly as min(fMax-1, taskCount[i]). This min comparison is importnat as if we have two tasks
that the same highest frequency, then one of the task point will end up after the current max point. As a result, only fMax-1 idle time slots are used up and thus these are to be duducted form the idleCount. 

At the end, we return the max of (0 and idelCount) as this represnents the idleCount remaining afdter all tasks have been filled im and add this to the no of busy intervals.
*/

// Other Approaches(1)
class Solution {
public:
    int getTotalIntervals(vector<char> tasks, int n){
        int maxTasks = 26;
        
        vector<int> taskCount(maxTasks,0);
        for(int i=0; i<tasks.size(); i++)
            taskCount[tasks[i]-'A']++;
        
        sort(taskCount.begin(), taskCount.end());
        
        int fMax = taskCount[maxTasks-1];
        int idleCount = (fMax-1) * n;
        
        for(int i=maxTasks-2; i>=0 && idleCount>0; i--)
            idleCount -= min(fMax-1, taskCount[i]);
        
        return max(0, idleCount) + tasks.size();
    }
    
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0)
            return tasks.size();
        return getTotalIntervals(tasks, n);
    }
};