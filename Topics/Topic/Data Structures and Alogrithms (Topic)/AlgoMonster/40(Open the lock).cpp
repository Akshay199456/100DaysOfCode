/*
Problem statement:

You commissioned a locksmith to craft a special combination lock for you, because you are a lich and you want to hide your phylactery in somewhere secure. It looks like a regular 4-digit combination lock, with each digit can be one of the digits from 0~9. Each digit can be turned forwards by 1 and backwards by 1, and the first and the last digit is connected (9 goes to 0 when moving forward, and 0 goes to 9 when moving backward). The lock starts at 0000.

However, because you don't want people to find your phylactery, you have trapped certain combinations of this combination lock. If someone were to set the combination to a trapped combination, bad things happen to them, which this question would not elaborate upon.

You know the combination, and you know the trapped combinations. You wonder if the lock can be opened without triggering the traps, and if so, how many digit changes must be made to the lock to unlock it.

Input
target_combo: a string representing the four digit combination to open the lock.
trapped_combos: a list of strings representing the trapped combinations.
Output
An integer representing the number of steps it takes to open the lock, or -1 if you can't open it without triggering the trap.

Examples
Example 1:
Input:

target_combo = "0202"
trapped_combos = ["0201","0101","0102","1212","2002"]
Output: 6

Explanation:

0000 -> 1000 -> 1100 -> 1200 -> 1201 -> 1202 -> 0202, a total of 6 steps.

Constraints
The starting combination (0000) and the final combination is not trapped because that defeats the purpose of the lock.
*/

/*
-------------------------    My Approaches:
1. 

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
question is a standard bfs problem, except we consider two combinations who has one one digit differ by one 'adjacent'. the implementation comes easily after we feifined what 'adjacent' means for this question


    Time complexity: O(n)
    Space complexity: O()

where n is the number of possible combination (which is 10$ = 10000 in this case)


Additional notes:

there didnt seem to be anything complicated about this problem. it was a basic application of BFS to keep gettin adjacent neigbors and following that path, we should have got to th enaswer.
we keep track ofhte numbers we have run into to avoid cycles and duplicate work.. you just needed to know what adjacent and neighbors meant for that problem and since you know you were
using BFS, once you got ot know what hte neighbors and adjacent was, everything else fell ointo place


Additional notes:

two combinations are adjacent if they differ by one digit, and the difference is either 1 or 9. for example,
0000 annd 0001 are adjacent, but 0000 and 0002 are not. this naturally models the lock as a graph. where each node
is a combination , and edge being the difference of one digit. the no of steps to open lock is the 
shortest path from 0000 to the target combination.

the time complexity is O(n) where n is the number of possible combinations (which is 10^4 == 10000 in this case)

the space complexity is also O(n) as we store the steps to reach each combination which each takes O(1)
*/



//  My approaches(1)



//  Other Approaches(1)
#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <queue> // queue
#include <sstream> // istringstream
#include <string> // getline, string
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <vector> // vector

int num_steps(std::string target_combo, std::vector<std::string> trapped_combos) {
    if (target_combo == "0000") return 0;

    std::unordered_map<char, char> next_digit = {
        {'0', '1'},
        {'1', '2'},
        {'2', '3'},
        {'3', '4'},
        {'4', '5'},
        {'5', '6'},
        {'6', '7'},
        {'7', '8'},
        {'8', '9'},
        {'9', '0'},
    };
    std::unordered_map<char, char> prev_digit;
    for (std::pair<char, char> entry : next_digit) {
        prev_digit[entry.second] = entry.first;
    }

    std::unordered_set<std::string> trapped_combo_set(trapped_combos.begin(), trapped_combos.end());
    std::unordered_map<std::string, int> steps;
    steps["0000"] = 0;
    std::queue<std::string> bfs_queue;
    bfs_queue.push("0000");
    while (bfs_queue.size() > 0) {
        std::string top = bfs_queue.front();
        for (int i = 0; i < 4; i++) {
            std::string new_combo = top.substr(0, i) + next_digit[top[i]] + top.substr(i + 1);
            if (!trapped_combo_set.count(new_combo) && !steps.count(new_combo)) {
                bfs_queue.push(new_combo);
                steps[new_combo] = steps[top] + 1;
                if (new_combo == target_combo) return steps[new_combo];
            }
            new_combo = top.substr(0, i) + prev_digit[top[i]] + top.substr(i + 1);
            if (!trapped_combo_set.count(new_combo) && !steps.count(new_combo)) {
                bfs_queue.push(new_combo);
                steps[new_combo] = steps[top] + 1;
                if (new_combo == target_combo) return steps[new_combo];
            }
        }
        bfs_queue.pop();
    }
    return -1;
}

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

int main() {
    std::string target_combo;
    std::getline(std::cin, target_combo);
    std::vector<std::string> trapped_combos = get_words<std::string>();
    int res = num_steps(target_combo, trapped_combos);
    std::cout << res << '\n';
}
