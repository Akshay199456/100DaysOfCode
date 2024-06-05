/*
Problem statement:

You are given a 2D integer array logs where each logs[i] = [birthi, deathi] indicates the birth and death years of the ith person.

The population of some year x is the number of people alive during that year. The ith person is counted in year x's population if x is in the inclusive range [birthi, deathi - 1]. Note that the person is not counted in the year that they die.

Return the earliest year with the maximum population.

 

Example 1:

Input: logs = [[1993,1999],[2000,2010]]
Output: 1993
Explanation: The maximum population is 1, and 1993 is the earliest year with this population.
Example 2:

Input: logs = [[1950,1961],[1960,1971],[1970,1981]]
Output: 1960
Explanation: 
The maximum population is 2, and it had happened in years 1960 and 1970.
The earlier year between them is 1960.
 

Constraints:

1 <= logs.length <= 100
1950 <= birthi < deathi <= 2050
*/

/*
-------------------------    My Approaches:
1. Sweeping line approach

    we can use the sweeping line approach in order to solve this problem. the base approach would be to basiclaly be listing out every year and in order to determine the populaion at any year
    we can amrk a one between the log for the year they were alive.

    however, if you have a vey big range of values, this approach becomes bery slow. As a result, the sweeping line approach can be used to solve the problem better. for any year a person
    is born, we indicate it with a 1 since it increases the population. for any death year-1, we decrease the population since it decreases the population by 1.
    we then sort out the birth and death years and go through the list. we keep track of the max population we see at any time and that gives us the ability to store the earliest year with
    the maximum population since our result is sorted and we are storiung the max

    Time complexity: O(nlogn)
    Space complexity: O(n) where n is the no of logs
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
class Solution {
public:
    void printList(std::vector<std::vector<int>> & list){
        for(int i=0; i<list.size(); i++){
            std::cout<<list[i][0]<<" "<<list[i][1]<<std::endl;
        }
    }

    int maximumPopulation(vector<vector<int>>& logs) {
        std::vector<std::vector<int>> events;

        // store each birth and death
        for(int i=0; i< logs.size(); i++){
            events.push_back(std::vector<int> {logs[i][0], 1});
            events.push_back(std::vector<int> {logs[i][1]-1, -1});
        }
        
        // sort the events in proper order
        std::sort(events.begin(), events.end(), [](vector<int> &a, vector<int> &b){
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });

        printList(events);

        // get max population and year
        int curPop = 0, maxPop = INT_MIN, year = -1;
        for(int i=0; i<events.size(); i++){
            std::vector<int> currEvent = events[i];
            if(currEvent[1] == 1)
                curPop += 1;
            else
                curPop -= 1;
            
            if(curPop > maxPop){
                maxPop = curPop;
                year = currEvent[0];
            }
        }

        return year;
    }
};


//  Other Approaches(1)
