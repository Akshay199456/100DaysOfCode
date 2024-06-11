/*
Problem statement:

You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a double booking.

A double booking happens when two events have some non-empty intersection (i.e., some moment is common to both events.).

The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.

Implement the MyCalendar class:

MyCalendar() Initializes the calendar object.
boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.
 

Example 1:

Input
["MyCalendar", "book", "book", "book"]
[[], [10, 20], [15, 25], [20, 30]]
Output
[null, true, false, true]

Explanation
MyCalendar myCalendar = new MyCalendar();
myCalendar.book(10, 20); // return True
myCalendar.book(15, 25); // return False, It can not be booked because time 15 is already booked by another event.
myCalendar.book(20, 30); // return True, The event can be booked, as the first event takes every time less than 20, but not including 20.
 

Constraints:

0 <= start < end <= 109
At most 1000 calls will be made to book.
*/

/*
-------------------------    My Approaches:
1. Merge intervals [not coded]

    this problem can easily be solved with the inert/merge interval approach we had learnt earlier. as long as the intervals are sorted, checking if an interval casues a double booking is easy
    as we just need to check if it coincides iwth another interval

    Time complexity: O(nlogn)
    Space complexity: O(1)

2. Line-sweep apprach [time limit exceeded]

    we can also solve this rpoblem with the line-sweep appraoch. using the lessons we learnt from trhe problem "Max population", we can use a similar approach to apply the same technique here.
    for any start time, we add a +1, while for any end time we add a -1. we then sort our this list which includes the new itnerval and go through it to see if we ever have more than
    one event running at a time. if we do, then we know a double booking has occured and as a result, we return false. otherwise, the new interval fits perfect and we return true

    Time complexity: O(nklogn) where n is the no of entries in the list and k is the no of times we repeat the booking.
    Space complexity: O(n)
*/


/*
-------------------------    Other Approaches 
1. optimized line-sweep approach

    this approach builds upon the line-sweep approach we discuseed in my approaches(2). the drawback of that approach is we had to continously sort every time we made a booking by inserting the new
    intrevals so that we would be able to decide the ordere of events. that is taken cae of in this optimized approach where we sue n ordered map that is ordered 
    by the start/end time. we still add +1, -1 to start/end time but we change the value to 0 for a time interval that is not valid. 

    Time complexity: 2O(logn) + O(n) = O(n) for every booking
    Space complexity: O(n)
*/


/*
-------------------------    Notes


    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(2)
class MyCalendar {
    std::vector<std::vector<int>> intervals;
public:
    MyCalendar() {
    }
    
    void printList(std::vector<std::vector<int>> & list){
        for(int i=0; i<list.size(); i++){
            std::cout<<list[i][0]<<" "<<list[i][1]<<std::endl;
        }
    }
    
    bool book(int start, int end) {
        // create a vector for the new events
        std::vector<int> begInterval {start, 1};
        std::vector<int> endInterval {end, -1};
        // store previous state
        std::vector<std::vector<int>> tempIntervals = intervals;
        int nBookings = 0;

        // insert it into the list
        intervals.push_back(begInterval);
        intervals.push_back(endInterval);

        if(intervals.size() > 2){
            // sort the events in ascending order with end intervals coming before beg intervals in terms of same value 
            std::sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
                if(a[0] == b[0])
                    return a[1] > b[1];
                return a[0] < b[0];
            });

            
            // if no merge issues return true, else revert state and return false
            for(int i=0; i<intervals.size(); i++){
                int prevBooking = nBookings;
                nBookings += intervals[i][1];
                if(nBookings > 1){
                    intervals = tempIntervals;
                    return false;
                }
            }
            return true;
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */



//  Other Approaches(1)
class MyCalendar {
public:
    std::map<int,int> intervals;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        int nBookings = 0;
        // insert new interval with +1 for begin and -1 for end
        intervals[start] += 1;
        intervals[end] += -1;

        // std::cout<<"for booking"<<std::endl;
        // run through map to identify double booking
        for(auto it = intervals.begin(); it!= intervals.end(); it++){
            // std::cout<<it->first<<":"<<it->second<<std::endl;
            nBookings += it->second;
            if(nBookings > 1){
                intervals[start] -= 1;
                intervals[end] += 1;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */