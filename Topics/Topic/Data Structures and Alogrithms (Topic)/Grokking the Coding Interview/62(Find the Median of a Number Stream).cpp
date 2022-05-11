/*
Problem statement:

Design a class to calculate the median of a number stream. The class should have the following two methods:

insertNum(int num): stores the number in the class
findMedian(): returns the median of all numbers inserted in the class
If the count of numbers inserted in the class is even, the median will be the average of the middle two numbers.
*/

/*
-------------------------    My Approaches:
1. 

    Came up with two approaches but neither approach the pattern we are trying to implement.

    Approach 1:
        store numbers in vector: time compleixty of insertnum = O(1)
        whenever, we are asked to find median, we sort the vector, and get the median.
        time complexity for findMedian: O(nlogn)
    
    Approach 2:
        store numbers in a heap: time complexity for insertNum = O(log n)
        when asked to find median, we pop elements from heap into a stack till we hit
        the elements we are looking for . we can then get the avg.
        Time comepxlty for findmoedian: O(nlogn)

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O(logn) for insertion and O(1) for findMedian
    Space complexity: O(n)
*/


/*
-------------------------    Notes
median is the middle value in an ordered integer list. a brute foce solution could be to maintain
a sorted list of all numbers inserted in the class so that we can efficinetly return the
median whenever required. inserting a number in a sorted list wll take O(n) time if there are
'N' numbers in the list. this insertion will be similar to insertion sort.

can we utilize thef act that we dont need the fully sorted list. we are only itnerested in 
finding the middle element? 
assume 'x' is the median of a list. this means that half o the numbers in th e list will be
smaller than or equal to to x and the other half will be gereater than or equal to x. this
leads us to an approach where we can divide the list into two halves: one half to store all
the smaller numbers (smallnumList) and one half to sotre the alrger numbers (lets call it largenumList).
the mediann of all numbers will either be the larger nuumber in the smallNumList or the 
smallest number in the largeNumList. if the toal no of elements is even, the median
will be the average of these two numbers

best data strcture to find the smallest or largest among a list of numbers is a heap.
allgorithm:
    1. we can store the first half of numbers(i.e smallNumList) in a amax heap. we should use a 
    max heap as we are interested in knowning the largest number in the first half.
    2. we can store the second half of numbers (i.e largeNumList) in min heap as we are interested
    in knowning the smallest number in the second half.
    3. inserting a number will take o(loign) in a heap which is ebtter than the brute force
    approach
    4. at tany tuime, the median fo the current list opf numbers can calcualted from the 
    top element of the two heaps.

We want to balance both the ehaps as we are inserting because this allows the list
to be divided into two eaual halves at all times. and since we have the bigrest eleemtn
from the small:List and the smallest element from the bigList always at the top, it
becomes easy to take those elements as since our heaps are balanced and with the nature of
the max and min heaps, we always have the median at the top.
if we dont balance, then we would need to take extra effort during findMedian to balance out
the two halves which would a waste of time.
*/



//  My approaches(1)



//  Other Approaches(1)
using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class MedianOfAStream {
 public:
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;

  virtual void insertNum(int num) {
    // TODO: Write your code here
    if(maxHeap.empty() || num < maxHeap.top()){
      cout<<"pushing "<<num<<" into max"<<endl;
      maxHeap.push(num);
    }
    else{
      cout<<"pushing "<<num<<" into min"<<endl;
      minHeap.push(num);
    }

    cout<<"max heap size: "<<maxHeap.size()<<endl;
    cout<<"min heap size: "<<minHeap.size()<<endl;
    // balance the two heaps
    if(maxHeap.size() > 1+ minHeap.size()){
      cout<<"pushing "<<maxHeap.top()<<" into min heap"<<endl;
      minHeap.push(maxHeap.top());
      maxHeap.pop();
    }
    
    else if(minHeap.size() > maxHeap.size()){
      cout<<"pushing "<<minHeap.top()<<" into max heap"<<endl;
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }
  }

  virtual double findMedian() {
    // TODO: Write your code here
    if((maxHeap.size() + minHeap.size()) % 2)
      return maxHeap.top();
    else
      return ((double)(maxHeap.top() + minHeap.top()))/ 2;
  }
};

int main(int argc, char *argv[]) {
  MedianOfAStream medianOfAStream;
  medianOfAStream.insertNum(3);
  medianOfAStream.insertNum(1);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
  medianOfAStream.insertNum(5);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
  medianOfAStream.insertNum(4);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
}


//Other Approaches(2)

