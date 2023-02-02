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
at minimum, the amount of time required to go through all the newspapers has be >= max(newspapers_read_times) to be able to finish reading the longest newspaper.
At maximum, if the amoiunt of time taken to go through all the newspapers is sum(newspapers_read_times), then it would reeequire only 1 coworker to finish the work. since we want to split thhe work of going 
through all the newspapers amoung num_coworkers workers, the minimum amount of time require to finish reading all the newspapers is somewhere is ebtween max(newspapers_read_times) and 
sum(newspapers_read_times). now, we simply need to perform binary search on the possible time values, checking if each time limit is enough to finish the work.

we check if a particular time works by trying to split the work among the coworkers and see if the total time taken 
exceeds the given time limit. we do so by moving from left to right in the newspapers array while keeping tack of the time that the 
current coworker spent. when the time that the current coworker spent exceeds the given time limit, we reset the current time tracker and add 1 to our coworker
count. when we finish checking the newspapers array, we check if the required coworker count exceeds the one we are given. if it does, then we know that the 
given time limit doesnt work and we must try a higher value. otherwise, we want to try a lower value to look for the minimum time limit that works.

Setting the inital low and high values takes O(n) to find out the maximum value and the sum of newspapers_read_times.
then performing binary search takes O(logn) and the helper function feasible() that is called inside the binary search loop is O(n). Overall the binary
search takes O(nlogn) which is more significant than O(n) so the time complexity of our solution is O(nlogn)

    Time complexity: O(n logn)
    Space complexity: O()
*/



//  My approaches(1)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

void getMinMax(std::vector<int> newspapers_read_times, int & maxTime, int & minTime){
    for(int i=0; i<newspapers_read_times.size(); i++){
        maxTime += newspapers_read_times[i];
        minTime = std::max(minTime, newspapers_read_times[i]);
    }
}

bool feasible(std::vector<int> newspapers_read_times, int num_coworkers, int mid){
    int n_workers = 0, time = 0;
    for(int i=0; i<newspapers_read_times.size(); i++){
        if(time + newspapers_read_times[i] > mid){
            time = 0;
            n_workers +=1;
        }
        time += newspapers_read_times[i];
    }
    
    if(time)
        n_workers +=1;
    return n_workers <= num_coworkers;
}


int newspapers_split(std::vector<int> newspapers_read_times, int num_coworkers) {
    // WRITE YOUR BRILLIANT CODE HERE
    int maxTime = 0, minTime = std::numeric_limits<int>::min();
    int result = -1;
    getMinMax(newspapers_read_times, maxTime, minTime);
    
    while(minTime <= maxTime){
        int mid = minTime + (maxTime-minTime)/2;
        if(feasible(newspapers_read_times, num_coworkers, mid)){
            result = mid;
            maxTime = mid-1;
        }
        else
            minTime = mid+1;
    }
    
    return result;
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    ss >> std::boolalpha;
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<int> newspapers_read_times = get_words<int>();
    int num_coworkers;
    std::cin >> num_coworkers;
    ignore_line();
    int res = newspapers_split(newspapers_read_times, num_coworkers);
    std::cout << res << '\n';
}



//  Other Approaches(1)
#include <algorithm> // copy, max_element
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <numeric> // accumulate
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

bool feasible(std::vector<int> newspapers_read_times, int num_coworkers, int limit) {
    // time to keep track of the current worker's time spent, num_workers to keep track of the number of coworkers used
    int time = 0, num_workers = 0;
    for (int read_time : newspapers_read_times) {
        // check if current time exceeds the given time limit
        if (time + read_time > limit) {
            time = 0;
            num_workers++;
        }
        time += read_time;
    }
    // edge case to check if we needed an extra worker at the end
    if (time != 0) {
        num_workers++;
    }
    // check if the number of workers we need is more than what we have
    return num_workers <= num_coworkers;
}

int newspapers_split(std::vector<int> newspapers_read_times, int num_coworkers) {
    int low = *std::max_element(newspapers_read_times.begin(), newspapers_read_times.end());
    int high = std::accumulate(newspapers_read_times.begin(), newspapers_read_times.end(), 0);
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (feasible(newspapers_read_times, num_coworkers, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    ss >> std::boolalpha;
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<int> newspapers_read_times = get_words<int>();
    int num_coworkers;
    std::cin >> num_coworkers;
    ignore_line();
    int res = newspapers_split(newspapers_read_times, num_coworkers);
    std::cout << res << '\n';
}