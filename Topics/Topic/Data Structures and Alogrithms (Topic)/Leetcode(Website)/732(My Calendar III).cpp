/*
Problem statement:

A k-booking happens when k events have some non-empty intersection (i.e., there is some time that is common to all k events.)

You are given some events [startTime, endTime), after each given event, return an integer k representing the maximum k-booking between all the previous events.

Implement the MyCalendarThree class:

MyCalendarThree() Initializes the object.
int book(int startTime, int endTime) Returns an integer k representing the largest integer such that there exists a k-booking in the calendar.
 

Example 1:

Input
["MyCalendarThree", "book", "book", "book", "book", "book", "book"]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
Output
[null, 1, 1, 2, 3, 3, 3]

Explanation
MyCalendarThree myCalendarThree = new MyCalendarThree();
myCalendarThree.book(10, 20); // return 1
myCalendarThree.book(50, 60); // return 1
myCalendarThree.book(10, 40); // return 2
myCalendarThree.book(5, 15); // return 3
myCalendarThree.book(5, 10); // return 3
myCalendarThree.book(25, 55); // return 3

 

Constraints:

0 <= startTime < endTime <= 109
At most 400 calls will be made to book.
*/

/*
-------------------------    My Approaches:
1. optimized line-sweep approach

    this approach builds upon the line-sweep approach we discuseed in my approaches(2). the drawback of that approach is we had to continously sort every time we made a booking by inserting the new
    intrevals so that we would be able to decide the ordere of events. that is taken cae of in this optimized approach where we sue n ordered map that is ordered 
    by the start/end time. we still add +1, -1 to start/end time but we change the value to 0 for a time interval that is not valid. 

    th eonly change in thsi rpoblem compared to rpeivous problems is that instead of checking for whether you can add an interval, here youi add an interval and fix the max k-booking
    that we encounter after adding the new interval. everything else is the same

    Time complexity: 2O(logn) + O(n) = O(n) for every booking
    Space complexity: O(n)
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
class MyCalendarThree {
public:
    std::map<int,int> intervalMap;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        int nBookings = 0, maxBooking = 0;
        // insert new interval
        intervalMap[startTime] += 1;
        intervalMap[endTime] -= 1;

        //find max k-booking
        for(auto it = intervalMap.begin(); it!= intervalMap.end(); it++){
            nBookings += it->second;
            if(nBookings > maxBooking)
                maxBooking = nBookings;
        }
        return maxBooking;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */


//  Other Approaches(1)
