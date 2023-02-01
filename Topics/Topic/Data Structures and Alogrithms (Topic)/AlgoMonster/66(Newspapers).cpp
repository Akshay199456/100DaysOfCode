/*
Problem statement:

ou've begun your new job to organize newspapers. Each morning, you are to separate the newspapers into smaller piles and assign each pile to a co-worker. This way, your co-workers can read through the newspapers and examine its contents simultenously.

Each newspaper is marked with a read time to finish all its contents. A worker can read one newspaper at a time, and when they finish a newspaper, they can start reading the next newspaper. Your goal is to minimize the amount of time needed for your co-workers to finish all newspapers. Additionally, the newspapers came in a particular order, and you must not disarrange the original ordering when distributing the newspapers. In other words, you cannot pick and choose newspapers randomly from the whole pile to assign to a co-worker, but rather you must take a subsection of consecutive newspapers from the whole pile.

What is the minimum amount of time it would take to have your coworkers go through all the newspapers? That is, if you optimize the distribution of newspapers, what is the longest read time among all piles?

Constraints
1 <= newspapers_read_times.length <= 10^5

1 <= newspapers_read_times[i] <= 10^5

1 <= num_coworkers <= 10^5

Examples
Example 1:
Input: newspapers_read_times = [7,2,5,10,8], num_coworkers = 2
Output: 18
Explanation:
Assign first 3 newspapers to one coworker then assign the rest to another. The time it takes for the first 3 newspapers is 7 + 2 + 5 = 14 and for the last 2 is 10 + 8 = 18.

Example 2:
Input: newspapers_read_times = [2,3,5,7], num_coworkers = 3
Output: 7
Explanation:
Assign [2, 3], [5], and [7] separately to workers. The minimum time is 7.
*/

/*
-------------------------    My Approaches:
1. Brute foce [not coded]

The summary of this approach is provided in images for My Approaches(1)-1. the gist is that for every worker that is available,
you want to minimze the max time that is taken as a whole so you split your array such that the max
time that is taken by any one worker is minmized. if you then have an additional worker, you then take the subarray with the max
time and split that in the same masnner as well since by reducing the max time allows us to minimze the total amount of time
as that is the bottleneck.

    Time complexity: O()
    Space complexity: O()
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
