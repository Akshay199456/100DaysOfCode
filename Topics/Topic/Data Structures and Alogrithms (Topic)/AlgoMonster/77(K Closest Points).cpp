/*
Problem statement:

Given a list of points on a 2D plane. Find k closest points to origin (0, 0).

Input: [(1, 1), (2, 2), (3, 3)], 1

Output: [(1, 1)]


*/

/*
-------------------------    My Approaches:
1. Using max heap

    we can use heaps in order to solve this problem. we can use a max heap in order to reduce the amount of space we use.
    as long as the heap size is less than k, we can keep isnerting the point into the heap. once the heap reaches the size k,
    then in order to insert a new point, we will need to check if the distanceSquared fot he new point is less than the top of the heap. since it is a max heap, the point at the top of the heap
    has the largest distanceSquared that we have seen till now. as a result, if the distanceSquared of the new point is less than the 
    top of the heap, then we ahve a point that is closer tot he origin than the top of thhe heap. As a ressu,t, we pop 
    off the top of the heap and insert this new point insdide the heap. 

    at the end of goign through allk the points, we now have the heap of size k. since we have continously removed points that are greater than the current points,
    what we have remainging at the end of the loop is the k points that are the closes tot hte oriign with the one farthest of those at the top.

    Additional notes:
        btw, good ise of the comparator throught eh struct. remember for the max heap, priority of the current element is less than its parent key.
        for a min heap, its priroity is greater than its parebt,. since we had a max heap, we use th eless than sign.


    Time complexity: O(nlogk)
    Space complexity: O(k)
*/


/*
-------------------------    Other Approaches 
1. min heap

distance between two points (x1, y1) and (x2,y2) is sqrt((x1-x2)^2 + (y1-y2)^2). for distance to orinign (x2,y2) is (0,0).

our first reaction when we see 'closest k' is to use a heap. the key for node comparison is a node's distance to origin. we then pop
the top 3 smallest off. 

    Time complexity: O(nlogn)
        we add every element into the heap. heap insertion is O(logn) which we do n times.
    Space complexity: O(n)

2. max heap

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes

*/



//  My approaches(1)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <queue>

struct Comparator
{
    int distanceSquared;
    int xCoord;
    int yCoord;
    
    Comparator(int d, int x, int y) : distanceSquared(d), xCoord(x), yCoord(y){
    }
    
    bool operator < (const struct Comparator& other) const{
        return distanceSquared < other.distanceSquared;
    }
};


void fillResult(std::vector<std::vector<int>> & result, std::priority_queue<Comparator> & pq){
    // popping heap
    while(!pq.empty()){
        Comparator curr = pq.top();
        pq.pop();
        std::vector<int> list = {curr.xCoord, curr.yCoord};
        result.push_back(list);
    }
    
    
    // reversing list
    for(int i=0; i<result.size()/2; i++){
        std::vector<int> temp = result[i];
        result[i] = result[result.size()-1-i];
        result[result.size()-1-i] = temp;
    }  
}


std::vector<std::vector<int>> k_closest_points(std::vector<std::vector<int>> points, int k) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::priority_queue<Comparator> pq;
    std::vector<std::vector<int>> result;
    
    if(!k)
        return result;
    
    for(int i=0; i<points.size(); i++){
        std::vector<int> currPoint = points[i];
        int distanceSquared = currPoint[0] * currPoint[0] + currPoint[1] * currPoint[1]; 
        if(pq.size() >= k){
            Comparator top = pq.top();
            if(top.distanceSquared > distanceSquared){
                pq.pop();
                pq.push(Comparator(distanceSquared, currPoint[0], currPoint[1]));
            }
        }
        else
            pq.push(Comparator(distanceSquared, currPoint[0], currPoint[1]));
    } 
    
    
    fillResult(result, pq);
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

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    int points_length;
    std::cin >> points_length;
    ignore_line();
    std::vector<std::vector<int>> points;
    for (int i = 0; i < points_length; i++) {
        points.emplace_back(get_words<int>());
    }
    int k;
    std::cin >> k;
    ignore_line();
    std::vector<std::vector<int>> res = k_closest_points(points, k);
    for (const std::vector<int>& row : res) {
        put_words(row);
    }
}



//  Other Approaches(1)
#include <algorithm> // copy
#include <cmath> // pow, sqrt
#include <iostream> // boolalpha, cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <limits> // numeric_limits
#include <queue> // priority_queue
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

std::vector<std::vector<int>> k_closest_points(std::vector<std::vector<int>> points, int k) {
    auto compare_distance = [](std::vector<int> p1, std::vector<int> p2) {
        auto distance_to_origin = [](std::vector<int> p) {
            return std::pow(p[0], 2) + std::pow(p[1], 2);
        };
        // use > for min heap
        return distance_to_origin(p1) > distance_to_origin(p2); 
    };
    // initialize min heap with the vector points
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(compare_distance)> heap(points.begin(), points.end(), compare_distance);
    std::vector<std::vector<int>> res;
    for (int i = 0 ; i < k; i++) {
        res.emplace_back(heap.top());
        heap.pop();
    }
    return res;
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

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    int points_length;
    std::cin >> points_length;
    ignore_line();
    std::vector<std::vector<int>> points;
    for (int i = 0; i < points_length; i++) {
        points.emplace_back(get_words<int>());
    }
    int k;
    std::cin >> k;
    ignore_line();
    std::vector<std::vector<int>> res = k_closest_points(points, k);
    for (const std::vector<int>& row : res) {
        put_words(row);
    }
}