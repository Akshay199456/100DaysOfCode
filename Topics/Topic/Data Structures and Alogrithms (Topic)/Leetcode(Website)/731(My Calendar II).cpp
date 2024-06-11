/*
Problem statement:

You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a triple booking.

A triple booking happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).

The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.

Implement the MyCalendarTwo class:

MyCalendarTwo() Initializes the calendar object.
boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar.
 

Example 1:

Input
["MyCalendarTwo", "book", "book", "book", "book", "book", "book"]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
Output
[null, true, true, true, false, true, true]

Explanation
MyCalendarTwo myCalendarTwo = new MyCalendarTwo();
myCalendarTwo.book(10, 20); // return True, The event can be booked. 
myCalendarTwo.book(50, 60); // return True, The event can be booked. 
myCalendarTwo.book(10, 40); // return True, The event can be double booked. 
myCalendarTwo.book(5, 15);  // return False, The event cannot be booked, because it would result in a triple booking.
myCalendarTwo.book(5, 10); // return True, The event can be booked, as it does not use time 10 which is already double booked.
myCalendarTwo.book(25, 55); // return True, The event can be booked, as the time in [25, 40) will be double booked with the third event, the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.
 

Constraints:

0 <= start < end <= 109
At most 1000 calls will be made to book.
*/

/*
-------------------------    My Approaches:
1. optimized line-sweep approach

    this approach builds upon the line-sweep approach we discuseed in my approaches(2). the drawback of that approach is we had to continously sort every time we made a booking by inserting the new
    intrevals so that we would be able to decide the ordere of events. that is taken cae of in this optimized approach where we sue n ordered map that is ordered 
    by the start/end time. we still add +1, -1 to start/end time but we change the value to 0 for a time interval that is not valid. 

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
class MyCalendarTwo {
public:
    std::map<int,int> intervalMap;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        int nBookings = 0;
        // create intervals from the start and end
        intervalMap[start] += 1;
        intervalMap[end] -= 1;

        //determine if a triple bookign is occuring
        for(auto it = intervalMap.begin(); it!= intervalMap.end(); it++){
            nBookings += it->second;
            if(nBookings > 2){
                intervalMap[start] -= 1;
                intervalMap[end] += 1;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */


//  Other Approaches(1)
