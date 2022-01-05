/*
-------------------------Question:

Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
*/

/*
-------------------------My Approaches:

1. There are several approaches to this problem depending on the constraints we are limited by. I
used variables to hold the values that we are testing for and use if statements for comparison.

This approach is good if we are trying to optimize the performance of the machine instead of fully
automating the procedure.

Time complexity: O(n)
Space complexity: O(1)


The key to this problem is to understand what constraint we are limited by and then implenting
a solution which satisifies that constraint.
*/

/*
-------------------------Other approaches

1. Using hashmap to store mappings

This approach is good if we want to automate the procedure as much as possible. In this case, we
just need to add mappings into the hashmap and the rest is taken care of. We have to use a map(
ordered) since we want the hashmap to store the mappings in a particular order.

Time complexity: O(m * n)
Space complexity: O(m) for hashmap
*/


// My aproaches(1)
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> resultVector;
        int multiple1 = 3, multiple2 = 5;
        for(int i = 1; i <= n; i++){
            string result = "";
            if( i % multiple1 == 0)
                result += "Fizz";
            if( i % multiple2 == 0)
                result += "Buzz";
            if(result.empty())
                result += to_string(i);
            
            resultVector.push_back(result);
        }
        return resultVector;
    }
};



// Other approaches(1)
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> resultVector;
        map<int, string> mappings;
        mappings[3] = "Fizz";
        mappings[5] = "Buzz";
        
        for(int i = 1; i <= n; i++){
            string result = "";
            for(auto it = mappings.begin(); it != mappings.end(); it++){
                if(i % it->first == 0)
                    result += it->second;
            }
            
            if(result.empty())
                result += to_string(i);
            resultVector.push_back(result);
        }
        return resultVector;
    }
};
