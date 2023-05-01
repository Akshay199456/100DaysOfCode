/*
Problem statement:

Given a stream of numbers, find the median number at any given time (accurate to 1 decimal place). Do this in O(1) time complexity.

Example:

add_number(1)
add_number(2)
add_number(3)
get_median() == 2.0
add_number(4)
get_median() == 2.5
*/

/*
-------------------------    My Approaches:
1. using two heaps

    we can use two heaps n order to solve this problem. the main idea here is that if we hav two heaps,
    one a max heap and the other a min heap, we can contninue to have the middle of the data stream at the top of the heaps. so dependiong on whether the no of elements is odd or even,
    we return the top of the max heap or get he avg og the top of both the heaps.

    the way we do this is to balance the heap after insertion of each element. we want the difference in sizes of the 
    heaps either at 1 or 0, witht ehmax heap having the addtional element. in thios state, getting the median is a O(1) operation. and the way we balance the trees
    is a pretty decent operation. if the size of the max heap exceeds that of the min heap, thjen we pop it off from the max heap and insert it intot th e
    min heap. we do the vice versa if the mmin heap exceeds that of the max heap.

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
#include <iomanip> // setprecision
#include <iostream> // cin, cout
#include <sstream> // istringstream
#include <string> // string
#include <queue>
#include <cmath>
#include <vector>

class MedianOfStream {
    private:
        std::priority_queue<int> maxPq;
        std::priority_queue<int, std::vector<int>, std::greater<int>> minPq;
        
        void balanceTrees(std::priority_queue<int> & maxPq, std::priority_queue<int, std::vector<int>, std::greater<int>> & minPq){
            int sizeDiff = maxPq.size() - minPq.size();
            while(sizeDiff > 1 || sizeDiff < 0){
                // fill logic here for this function - @TODO
                if(sizeDiff > 1){
                    minPq.push(maxPq.top());
                    maxPq.pop();
                }
                else{
                    maxPq.push(minPq.top());
                    minPq.pop();
                }
                
                sizeDiff = maxPq.size() - minPq.size();
            }
        }
        
    public:
        void add_number(float num) {
            // Implement function here
            if(!minPq.empty()){
                int minTop = minPq.top();
                if(num > minTop)
                    minPq.push(num);
                else 
                    maxPq.push(num);
            }
            else
                minPq.push(num);
            
            balanceTrees(maxPq, minPq);
        }

        float get_median() {
            // Implement function here
            float result = 0;
            bool isEven = ((maxPq.size() + minPq.size()) % 2 == 0) ? true : false;
            if(isEven)
                result = ((float)maxPq.top() + minPq.top())/2;
            else
                result = maxPq.top();
            return result;
        }
};

int main() {
    MedianOfStream median_of_stream;
    int n;
    std::cin >> n;
    std::string input;
    for (int i = 0; i < n; ++i) {
        std::cin >> input;
        if (input == "get") {
            float median = median_of_stream.get_median();
            std::cout << std::fixed << std::setprecision(1) << median << '\n';
        } else {
            float num;
            std::stringstream ss;
            ss << input;
            ss >> num;
            median_of_stream.add_number(num);
        }
    }
}




//  Other Approaches(1)
