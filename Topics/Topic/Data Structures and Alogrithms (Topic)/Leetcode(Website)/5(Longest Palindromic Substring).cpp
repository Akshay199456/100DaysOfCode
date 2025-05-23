/*
-------------------------Question:

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

/*
-------------------------My Approaches:

1. Brute Force Approach[Worst]

The brute force approch is simple. Generate all the substring combinations of the given string and for each
substring, check if it's a palindrome. If it is and it is of the max length that has been encoutnered, 
store the result. At the end, you want to return the string with the max length;

Time complexity: O(n^3)
Space complexity: O(1)


2. Recursive approach[Not coded]

If we observe this problem, this is a recusive problem. Starting from a length of the string, if the first character is
equal to the end character, then we know that the outside of the string is a palindrome so we need to check the inside
to make sure it is a palindrome as well. If the first character is not equal to the last character, then we know that
we will not be able to generate a substring from the string of this length, so we look for substrings of size -1. There
are two combinataions possible at each step, by either pushing the beginning pointer forward or by pushing the end pointer
backward by 1. We continue this recursively. 

Our base case is when we encounter a substring of either length 1 or 2. If it is of length 1, we know that is is a palindrome.
If it is of length 2, we need to check the first and last character to determine if it is a palindrome 

Time complexity: O(2^n)
Space complexity: O(n)


3. Bottom up DP Approach

If we notice the bottleneck in the previous approach, we notice that, we are performing the same calcualtions time and time
again. So, we can instead cache those results for further use. As a result, we use a dpTable to store the state and set
the dpTable[i][j] = 1 since any substring of length 1 will be a palindrome. We then start from the bottom of the array
and move from left to right to fill in the tnries for the rest of the table depending on the recursive state relationship
we encountered in My Approaches(2)


Time complexity: O(n^2)
Space complexity: O(n^2)
*/

/*
-------------------------Other approaches

1. Using mirroring property of Palindromes(Dynamic Programming)[Better]

If you take a string that's a palindrome, you notice that starting from its center, every character to its
left and right are equal.

eg: aba -> starting from b, every character i-1, i+1 are equal to each other
    abba -> here, we assume the center to be between the two midpoints[b and b]. every character i-1, i+1
            are equal to each other

In addition, if you look at a palindrome like 'aba' and 'abba', each of these palindromes can be broken into
two core conditions. The general condition being 
    P(i,j) = {
                true if Si.....Sj is a palindrome
                false otherwise
              }
    
    and P(i,j) = P(i+1, j-1) && S[i] == S[j]

The two core conditions are:
    P(i,i) = true (Since a string of length 1 is always a palindrome and odd length)
    P(i,i+1) = true if S[i] == S[i+1][ String of length 2 and even length]

Every other string can be broken down into one of these conditions. We will be using these conditions
to test for palindromes as we pass through the stirng element.

Now, we can divide the string into 2n-1 centers => n from the single element and n-1 from the double element.
We test for these conditions at the 2n-1 centers as we progress through the string. The reason we choose the
centers is because the palindromes mirror around the center. Hence, if our centers are equal, we can expand
outwards from there and keep the same check going.

Time complexity: O(n^2) => Going through the string of length n and for each center, worse case is that
we will go throguh the whole string.
Space complexity: O(1)



2. Using a 2d array as reference to store whether a string of a certain length is a palindrome or not

As suggested above, we could use a 2d array as reference. As was shown in the Other Approaches(1), strings
of length 1 and 2 are the base cases from which everything else will be derived. As a result, we use 
a couple of loops to set the elements in the array to 1. For length 1, we set all [i][i] to 1 since any
character is a palindrome to itself. For length 2, we set [i][i+1] to true if element[i]==element[j]. These
base cases will help set up for any length of string > 2.

For any string Si...Sj of length > 2, we are able to deduce if it is a palindrome if Si+1...Sj-1 is also
a palindrome and S[i] == S[j]. In the 2d array, hence we check for array[i+1][j-1] to check if it's a 
palindrome(if it is set to 1) and if S[i] == S[j]. If it is, we know this is also a palindrome so we set
the array[i][j] = 1 to set as a guide for the next level. In addition, if it exceeds the max size, we make
sure to store it as the maxSize. We continue this till we have covered a level whose length is equal to the
length of the stirng element.

Thus, starting from level 1 and 2, we extend what we learn from the previous level about the string and
deduce if the string in the current level is a palindrome.

Check out [https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/] for reference with respect
to this solution

Time complexity: O(n^2)
Space complexity: O(n^2)


3. Same as Other Approaches(2) but more concise

This approach is same as Other Apporoaches(2) but is more concise as compared to it.

Time complexity: O(n^2)
Space complexity: O(n^2)

*/

// My Approaches(1)
class Solution {
public:
    bool checkPalindrome(string element){
        for(int i = 0; i < element.size()/ 2; i++){
            if(element[i] != element[element.size() - i - 1])
                return false;
        }
        return true;
    }
    
    string findLongestPalindrome(string element){
        //printResult(allSubstrings);
        string maxElement = string(1,element[0]);
        int maxSize = 1;
        for(int i = 0; i < element.size(); i++){
            string result = string(1,element[i]);
            for(int j = i+1; j < element.size(); j++){
                result += string(1, element[j]);
                if(checkPalindrome(result) && result.size() > maxSize){
                    maxSize = result.size();
                    maxElement = result;
                }
            }
        }
        return maxElement;
    }
    
    string longestPalindrome(string s) {
        if(s.empty())
            return "";
        else
            return findLongestPalindrome(s);
    }
};

// My Approaches(3)
class Solution {
public:
    vector<vector<bool>> dpTable;
    
    void constructDpTable(int size){
        for(int i = 0; i < size; i++){
            vector<bool> list;
            for(int j = 0; j < size; j++){
                if(i==j)
                    list.push_back(true);
                else
                    list.push_back(false);
            }
            dpTable.push_back(list);
        }
    }
    
    string fillDpTable(string s){
        int startIndex = 0, endIndex = 0;
        for(int i = s.size()-1; i>=0; i--){
            for(int j = i+1; j < s.size(); j++){
                if(s[i] == s[j]){
                    if(j-1 == i)
                        dpTable[i][j] = true;
                    else
                        dpTable[i][j] = dpTable[i+1][j-1];
                }
                else
                    dpTable[i][j] = false;
                
                if(dpTable[i][j] && endIndex - startIndex< j - i){
                    startIndex = i;
                    endIndex = j;
                }
            }
        }
        return s.substr(startIndex, endIndex-startIndex+1);
    }
    
    string longestPalindrome(string s) {
        constructDpTable(s.size());
        return fillDpTable(s);
    }
};



// Other Approaches(1)
class Solution {
public:
    string findLongestPalindrome(string element){
        // will be used to store the beginning and end index of the palindromic substring
        int start = 0, end = 0;
        for(int i = 0; i < element.size(); i++){
            //finding the max length using the single center
            int singleCenterLength = extendPalindromeSubstring(element,i,i);
            //finding the max length using the double center
            int doubleCenterLength = extendPalindromeSubstring(element,i,i+1);
            // only need the largest length from them since that's what we are looking for
            int maxLength = max(singleCenterLength, doubleCenterLength);
            
            // only if the length of the current palindrome is greater than what we had
            if(maxLength > (end - start + 1)){
                start = i - (maxLength - 1) / 2;
                end = i + maxLength / 2;   
            }
        }
        return element.substr(start, end - start + 1);
    }
    
    int extendPalindromeSubstring(string element, int left, int right){
        // as long as we are within the limits of the string, we can keep moving outward both on the left
        // and the right starting from the current center
        while((left >= 0 && right <element.size()) && (element[left] == element[right])){
            left--;
            right++;
        }
        // returning the length of the palindromic substring
        return right - left - 1;
    }
    
    
    string longestPalindrome(string s) {
        if(s.empty())
            return "";
        else
            return findLongestPalindrome(s);
    }
};


// Other Approaches(2)
class Solution {
public:
    string findLongestPalindrome(string element){
        bool palindromeArray[element.size()][element.size()];
        int maxLength = -1, startIndex = -1;
        
        for(int i = 0; i < element.size(); i++)
            for(int j = 0; j < element.size(); j++)
                palindromeArray[i][j] = 0;
        
        // Setting palindromes of length 1 and 2;
        for(int i = 0; i < element.size(); i++){
            maxLength = 1;
            startIndex = i;
            palindromeArray[i][i] = 1;
        }
        
        // Setting palindromes of length 2
        for(int i = 0; i < element.size() - 1; i++){
            if(element[i] == element[i+1]){
                maxLength = 2;
                startIndex = i;
                palindromeArray[i][i+1] = 1;
            }
        }
        
        // Palindromes of length >= 3
        // k is the length of the string we will be covering
        for(int k = 3; k <= element.size(); k++){
            // i is the start index
            for(int i = 0; i < element.size() - k + 1; i++){
                // j is the end index
                int j = k + i - 1;
                if(palindromeArray[i+1][j-1] && (element[i] == element[j])){
                    palindromeArray[i][j] = 1;
                    
                    if(k > maxLength){
                        startIndex = i;
                        maxLength = k;
                    }
                }
            }
        }
        //printMatrix((bool *)palindromeArray, element.size());
        return element.substr(startIndex, maxLength);
    }
    
    void printMatrix(bool * array, int size){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++)
                cout<<*((array + i*size) + j)<<" ";
            cout<<endl;
        }
    }
    
    string longestPalindrome(string s) {
        if(s.empty())
            return "";
        else
            return findLongestPalindrome(s);
    }
};


// Other Approaches(3)
class Solution {
public:
    vector<vector<bool>> dpTable;
    
    void constructDpTable(int length){
        for(int i = 0; i < length; i++){
            vector<bool> list;
            for(int j = 0; j < length; j++)
                list.push_back(false);
            dpTable.push_back(list);
        }
    }
    
    string getLongestPalindrome(string s){
        constructDpTable(s.size());
        int startIndex = INT_MIN, endIndex = INT_MIN;
        
        // entries for i,i will be true since string of length 1 will be a palindrome
        for(int i = 0; i < s.size(); i++)
            dpTable[i][i] = true;
        
        // entries for string lengths greater than 1
        for(int k = 1; k < s.size(); k++){
            for(int i = 0; i < s.size() - k; i++){
                int j = k+i;
                bool stepResult = false;
                if(k == 1)
                    stepResult = (s[i] == s[j]);
                else
                    stepResult = (s[i] == s[j] && dpTable[i+1][j-1]);
                
                if(stepResult){
                    startIndex = i;
                    endIndex = j;
                }
                dpTable[i][j] = stepResult;
            }
        }
        
        if(startIndex == INT_MIN)
            return s.substr(0,1);
        return s.substr(startIndex, endIndex-startIndex+1);
    }
    
    string longestPalindrome(string s) {
        if(s.size() <= 1)
            return s;
        return getLongestPalindrome(s);
        
    }
};