/*
Problem statement:

Gas Station
There are a total of n gas stations along a clockwise, circular route, and for the ith gas station (starting from 0), there are gas[i] litre of gas stored.

The distance between the ith gas station and the i + 1th gas station is dist[i].

You have a car, and you would like to travel clockwise starting from any gas station and return to the same gas station. The car has a sufficiently large gas tank, and for each unit of gas, your car can travel a unit distance. Initially, the fuel tank of your car is empty, but you can add fuel from any fuel station for as long as that fuel station has fuel left.

You wonder whether you can successfully travel this way. If so, output the index representing the starting gas station. Otherwise, output -1. The solution is guaranteed to be unique, if one exists.

Input
gas: a list of integers representing the gas available for each gas station.
dist: a list of integers representing the distance between each two adjacent gas stations.
Output
The unique starting gas station to be able to travel once, or -1 if no such station exists.

Examples
Example 1:
Input:

gas = [1, 2, 3, 4, 5]
dist = [3, 4, 5, 1, 2]
Output: 3

Explanation:

Starting from station 3, the car has 4 gas. It travels to the next station spending 1 gas, leaving 3 gas. Pick up 5 gas, travel to the next station, and leaving 6 gas. For the next three station, there is enough fuel to travel to each one and return to the starting point.

Constraints
1 <= len(gas) == len(dist) <= 10^4
1 <= gas[i], dist[i] <= 10^4
*/

/*
-------------------------    My Approaches:
1. two looped solution [not coded]

    we can use a two looped solution as shown in my approaches. We know for sure about one thing, there is no point starting from a station which has a gas_to_dist of negative.
    that is because, if it were negative, you would not be able to make it to the ext station with the amount of fuel you have and the distance requrired to go to the next station.
    As a result, you skip those gas stations. potential soltuions are those which hasve a positive gas_to_dist ratio. when we find one of them, we basically run throug another for loop which sees 
    whether we can end up at the same index after going in a cycle. if we can, then we hav efound our solution, othweise we cant. we do that for each of the indexes that have a positive
    gas_to_dist index.

    one last thing. if you take the gas_to_dist which is ibtained by deucteing the distance to next station from the gas available at the station and take the whole sum of that list,
    if it doesnt exceed or equal to 0, then a solution cannot be arrived at. this is because whatever you do, whereever you start from (even from aa the max sum position), by the time you 
    try to get back to the starting station, you no longer have the gas needed to make it back at some point or the other.

    Time complexity: O(n^2)
    Space complexity: O(1)

2. improved looped solution [not coded]

    so, the improved solutio comes from the obnservation that our best chance to go through a cycle and get back to a station starts from a station that had the maximum continguius 
    array starting at that location. what i mean by that is we identify the maximum subarray sum that we emcounter from gas_to_distance, either through brute force (through double looped approach O(n^2))
    or through kadane's algorithm (more fficient O(n) algorithm), in a cyclic array. our best chance starts from this subarray starting point because we know that this subrrray will
    provide us witht he contiguous max subarray sum (which will be greater than 0). and that having that maximum sum allows you to maximize your chance of getting back to the station
    from where you started (which si the starting location of the max subarray sum) as tehere will be periods of negative gas_to_dist. if you cant make it from this location, then
    you cant make it from any other location since this area provides you with the best chance of getting back to the starting station 

    the only reason i didnt code it is because i dont remember the kadanes algorithm approach. it has been a while since i used it


    Time complexity: O(n)
    Space complexity: O(1)
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



//  Other Approaches(1)
