/*
-------------------------Question:

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/

/*
-------------------------    My Approaches:

1. 

While I was able to figure out this approach almost immediately, I implemented it poorly. Whatever
be the reason(was probably tired), I didn't take into consideration different edge cases that would
have caused the algorithm to fail. As a result, while implementing this algorithm and running, I ran
into 'wrong answers' 4 times.

The approach used in this algorithm basically uses two pointers to keep track of the needle and
haystack. Obviously, if needle.size() > haystack.size() as well as haystack.size() ==0, we return
-1 as we can't find the needle in it. If instead, the needle.size() == 0, we return 0 as defined
by the problem statement in this case. If they are of the same size, we write a separate algo to
increase the speed taken for that particular case. Else we follow a general algorithm where we 
check if the characters of the haystack and the needle are the same. This has a worst case time
complexity of O(mn).

We can technical combine the case for when the haystack.size() >= needle.size()

m-> size of haystack
n-> size of needle

Time complexity: O(mn)
Space complexity: O(1)
*/

/*
-------------------------    Other approaches:

1. Using KMP which is particularly built for finding substring within a string within linear
time complexity (Images have been attached in respective folder to understand algorithm better):

m-> size of haystack
n-> size of needle

Time complexity: O(m+n)
Space complexity: O(n)

KMP uses a two stepped approach to find the matching substring in O(m+n) time complexity:

	a. Contructing an lps array to know the number of characters to skip by

	This prevents us from allowing to check if each character that occurred before and only
	compare with characters that are the start of a pattern.

	Time complexity: O(n)
	Space complexity: O(n)

	b. Using the lps array to find matching substring

	Whenever there is a match, we progress till we hit the end of the pattern. Else, if there is a
	mismatch, we only compare it with the beginning of the previous pattern and continue to do so
	with mismatches till we hit the beginning of the array.

	Time complexity: O(m)
	Space complexity: O(1)

Total complexity:

Time complexity: O(m+n)
Space complexity: O(n)


Note: The lps array stands for longest proper prefix that is also a suffix. By building it, the advantage is that upon a mismatch, we can obtain the value at the previous index. This value tells us whether there is any match upto the current
value. If it is, we know that this is a suffix that exists in the string. This then means that there must be a prefix that matches this string. As a result, we make our len jump to value. This will be the value from which we can continue
searching for next patterns thereby skipping a few characters.

*/

// My approaches(1)
class Solution {
public:
    int getIndex(string haystack, string needle){
        if(needle.size() == 0)
            return 0;
        else if(haystack.size() == 0 || haystack.size() < needle.size())
            return -1;
        else if(haystack.size() == needle.size()){
            int pointer = 0;
            while(pointer < haystack.size()){
                if(!(haystack[pointer] == needle[pointer]))
                    return -1;
                else
                    pointer++;
            }    
            return 0;
        }
        else{
            int hayptr = 0, needptr = 0, index = 0;
            bool found = false;
            while(hayptr < haystack.size() && needptr < needle.size()){
                if(haystack[hayptr] == needle[needptr]){
                    if(!found){
                        index = hayptr;
                        found = true;
                    }
                    needptr++;
                }
                
                else{
                    if(found)
                        hayptr = index;
                    found = false;
                    needptr = 0;
                }
                hayptr++;
            }
            
            if(needptr == needle.size())
                return index;
            else
                return -1;
        }
    }
    
    int strStr(string haystack, string needle) {
        return getIndex(haystack, needle);
    }
};



// Other approaches(1)[Work in progress]
class Solution {
public:
    void generateLps(string needle, int *lps){
        int len = 0, index = 1;
        lps[len] = 0;
        while(index < needle.size()){
            if(needle[index] == needle[len])
                lps[index++] = ++len;
            else{
                if(len > 0)
                    len = lps[len-1];
                else
                    lps[index++] = 0;
            }
        }
    }
    
    void displayLps(int * lps, int size){
        cout<<"Displaying the array lps: \n";
        for(int i = 0; i < size; i++ )
            cout<<lps[i]<<" ";
        cout<<endl;
    }
    
    int searchAlgorithm(string haystack, string needle, int * ptr){
        int i = 0, j = 0;
        while(i < haystack.size()){
            // cout<<"I: "<< i <<" J: "<<j<<endl;
            if( j == needle.size())
                return i - j; 
            else if(haystack[i] == needle[j]){
                // cout<<"We getting here\n";
                ++i;
                ++j;
            }
            else{
                if(j > 0)
                    j = ptr[j-1];
                else
                    ++i;
            }
        }
        
        if(j == needle.size())
            return i-j;
        else
            return -1;
    }
    
    int firstOccurrence(string haystack, string needle){
        if(needle.size() == 0)
            return 0;
        else if(haystack.size() == 0 || haystack.size() < needle.size())
            return -1;
        else{
            int lps[needle.size()];
            generateLps(needle, lps);
            // displayLps(lps, needle.size());
            return searchAlgorithm(haystack, needle, lps);
        }
    }
    
    int strStr(string haystack, string needle) {
        return firstOccurrence(haystack, needle);
    }
};