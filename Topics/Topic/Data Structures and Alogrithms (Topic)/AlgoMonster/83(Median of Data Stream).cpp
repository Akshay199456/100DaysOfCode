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
    heaps either at 1 or 0, with the max heap having the addtional element. in thios state, getting the median is a O(1) operation. and the way we balance the trees
    is a pretty decent operation. if the size of the max heap exceeds that of the min heap, thjen we pop it off from the max heap and insert it intot th e
    min heap. we do the vice versa if the mmin heap exceeds that of the max heap.

    we use the a max heap for the first half so that the for the first half of the elemtns that are less than the median,
    we can easily get he max of that list. and we use a min heap for the second half so that for th second half of the elements that
    are more than the median, we get the min of those elements. these two elements will then serve as the median
    of the lsit.

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
intuition

    brute foce way is to sort the entire list every time we get a new number. this would be Onlogn) for each add_number
    operation.
    one step up is to notice that the list is sorted before we add any new number to it. so every time we add a new number to the exisitng list we just have to find the spot to add it.
    we cam find the insert position using binary search in O(logn). however, since insertinng into a position also means shifting after the insert postiion by 1,
    the overall run time is O(n)
    upon re-examining the conditions and unknowns of the problem, we noticed we only need to find the median and dont the rest of the lsit to be 
    sorted. but how are we goonna find the median ithout having a sorted list?

    it's iseful to use the first principle and go back to the definition of median:

    half the numbers are smaller than the median and the other half are larger than the median.

    Let's assume the total no of elements is even and we can divide the numbers into two piles of equal size based on their values, a smaller half small_pile
    and the bigger half big_pile. the median of both piles is the average of the largest number in the small_pile and the smallest number of the big_pile.
    when we add a new number, two things could happen.

        1. the new number is smaller than the largest of the small_pile, and the size of the small_pile is now 1 greater than big_pile. the median of both piles is the 
        largest number of the small_pile.
        2. the new number is bigger than the largest of the small_pile. in this case, the number belongs to the big pile. and the median of 
        both piles is the smallest number of the big_pile.
    
    now the problem boils down to keep a sm,all+pile where we can find max value easily and a big_pile where we can find min_valu easily.
    and min heap and max heap fits those requirements perfectly.

    time complexity: O(qlogq)
        here we let q denote the no of queries so worst case its log)q) for insertion of a given number
    space complexity: O(n)


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
#include <iomanip> // setprecision
#include <iostream> // cin, cout
#include <queue> // priority_queue
#include <sstream> // istringstream
#include <string> // string

class MedianOfStream {
    private:
        std::priority_queue<float, std::vector<float>, std::greater<float>> minheap;
        std::priority_queue<float> maxheap;

        void _balance() {
            if (maxheap.size() < minheap.size()) {
                maxheap.push(minheap.top());
                minheap.pop();
            }
            if (maxheap.size() > minheap.size() + 1) {
                minheap.push(maxheap.top());
                maxheap.pop();
            }
        }

    public:
        void add_number(float num) {
            if (minheap.size() == 0 || num < minheap.top()) {
                maxheap.push(num);
            } else {
                minheap.push(num);
            }
            _balance();
        }

        float get_median() {
            if (maxheap.size() == minheap.size()) {
                return (maxheap.top() + minheap.top()) / 2;
            } else {
                return maxheap.top();
            }
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