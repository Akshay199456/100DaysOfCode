/*
-------------------------Question:

here are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique

 

Example 1:

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
Example 2:

Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
 

Constraints:

gas.length == n
cost.length == n
1 <= n <= 104
0 <= gas[i], cost[i] <= 104
*/

/*
-------------------------    My Approaches:

*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    void getLocalMinimum(vector<int> gas, vector<int> cost, unordered_set<int> & localMinimumSet){
        vector<int> diff;
        for(int i=0; i<gas.size(); i++){
            if(gas[i]-cost[i] >= 0)
                diff.push_back(gas[i]-cost[i]);
            else
                diff.push_back(INT_MAX);
        }
        
        for(int i=0; i<gas.size(); i++){
            // cout<<"I: "<<i<<" Gas: "<<gas[i]<<" Cost: "<<cost[i]<<endl;
            if(diff[i]!=INT_MAX && diff[i]>=0){
                if(i==0){
                    if(diff[i]<=diff[i+1])
                        localMinimumSet.emplace(i);
                }
                else if(i==gas.size()-1){
                    if(diff[i]<diff[i-1])
                        localMinimumSet.emplace(i);
                }
                else{
                    if(diff[i]<diff[i-1] && diff[i]<=diff[i+1])
                        localMinimumSet.emplace(i);
                }   
            }
        }
    }
    
    int checkRoute(vector<int> gas, vector<int> cost, unordered_set<int> localMinimumSet){
        if(localMinimumSet.size() != 0){
            for(auto it=localMinimumSet.begin(); it!=localMinimumSet.end(); it++){
                int currStart = *it, currTank =0;
                int cycleIndex = currStart;
                // cout<<"CurrStart: "<<currStart<<" cycleIndex: "<<cycleIndex<<" Current tank: "<<currTank<<endl;   
                bool isEnd = false;
                do{ 
                    currTank += gas[cycleIndex];
                    // cout<<"CycleIndex: "<<cycleIndex<<" Gas at cycleIndex: "<<gas[cycleIndex]<<" Tank after adding gas: "<<currTank<<" cost at cycleIndex: "<<cost[cycleIndex]<<endl;
                    if(currTank-cost[cycleIndex]>=0){
                        currTank -= cost[cycleIndex];
                        cycleIndex++;
                        // cout<<"Updated cycleIndex: "<<cycleIndex<<" updated tank: "<<currTank<<endl;
                        
                        if(cycleIndex == gas.size())
                            cycleIndex=0;
                        if(cycleIndex == currStart)
                            return currStart;
                    }
                    else
                        isEnd = true;
                }while(!isEnd);
            }   
        }
        return -1;
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size() == 1){
            if(gas[0]-cost[0] < 0)
                return -1;
            else
                return 0;
        }
        else{
            unordered_set<int> localMinimumSet;
            getLocalMinimum(gas, cost, localMinimumSet);
            return checkRoute(gas, cost, localMinimumSet);
        }
    }
};