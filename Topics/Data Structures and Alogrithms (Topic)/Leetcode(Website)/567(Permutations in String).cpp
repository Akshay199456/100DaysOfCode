/*
-------------------------Question:

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Constraints:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/

/*
-------------------------My Approaches:

*/

/*
-------------------------Other approaches
1. Brute force approach

The first approach that we can use to solve this problem is the brute force approach. As the question suggests, we can
generate all permutations of s1 and then check if it is contianed withing s2. If it is, then return true; else return
false;

To generate permutations, check out the 'Helping Images' folder for more steps. The crux of the approach is that we swap
the current index with the left index till we reach the end where we insert it into the result.

Time complexity: O(s2* s1!)
Space complexity: O(s1!)


2. Sorting and comparing strings.

If we look at the bottleneck in the pervious approach, we see that it takes a lot of time to generate the permutations.
We can improve upon this by instead generating the different substrings of length s1 as generating a  substring is a 
quadratic itime operation at worst. As a result, once we generate the substrings of length s1, we want to compare the sorted
versions of both s1 and s2. This is because, if the permutation exiosts, then the frequqncy of the characters and the 
sorted order will be the same. In other words, sorted(x) = sorted(y). Hence, we can test this to test whether it exists or
not

Time complexity: O(s1log(s1) + (s2-s1)(s1 + s1logs1))
Space complexity: O(s1)


3. Using maps/arrays to get frequency count of characters and comparing

We can continue of the previous approach and iomprove it. If we notice in the previous approach, we were sorting the 
s1 and substring of s2 of length s1 to check if they were eqal. At the end of the day, what we were doing was checking
if the count and frequency of characters were the same. Hence, this is where we can optimize the previous approach. By using
maps/arrays we can get frequency count of characters and use that information

Time complexity: O(s1 + 26*s1*(s2-s1))
Space complexity: O(1)
*/

// Other Approaches(1)
class Solution {
public:
    void generatePermutations(vector<string> & allPermutations, string s1, int left, int right){
        if(left == right)
            allPermutations.push_back(s1);
        else{
            for(int i = left; i <= right; i++){
                swap(s1[left], s1[i]);
                generatePermutations(allPermutations, s1, left+1, right);
                swap(s1[left], s1[i]);
            }
        }
    }
    
    bool checkPermutationExists(vector<string> allPermutations, string s2){
        for(int i = 0; i < allPermutations.size(); i++){
            if(s2.find(allPermutations[i]) != string::npos)
                return true;
        }
        return false;
    }
    
    bool findInclusion(string s1, string s2){
        vector<string> allPermutations;
        generatePermutations(allPermutations, s1, 0, s1.size() - 1);
        return checkPermutationExists(allPermutations, s2);
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size())
            return false;
        return findInclusion(s1, s2);
    }
};

// Other Approaches(2)
class Solution {
public:
    bool findInclusion(string s1, string s2){
        sort(s1.begin(), s1.end());
        for(int i = 0; i<= s2.size() - s1.size(); i++){
            string element = s2.substr(i, s1.size());
            sort(element.begin(), element.end());
            if(s1.compare(element) == 0)
                return true;
        }
        return false;
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size())
            return false;
        return findInclusion(s1, s2);
    }
};


// Other Appraoches(3)
class Solution {
public:
    void generateMap(string s, unordered_map<char, int> & map){
        for(int i = 0; i < s.size(); i++){
            if(map.find(s[i]) == map.end())
                map[s[i]] = 1;
            else
                map[s[i]]++;
        }
    }
    
    bool compareMaps(unordered_map<char, int> s1Map, unordered_map<char,int> s2Map){
        if(s1Map.size() != s2Map.size())
            return false;
        for(auto it1 = s1Map.begin(); it1!= s1Map.end(); it1++){
            if(s2Map.find(it1->first) == s2Map.end())
                return false;
            else if(it1->second != s2Map[it1->first])
                return false;
        }
        return true;
    }
    
    bool findInclusion(string s1, string s2){
        unordered_map<char, int> s1Map;
        generateMap(s1, s1Map);
        
        for(int i = 0; i <= s2.size() - s1.size(); i++){
            string element = s2.substr(i, s1.size());
            unordered_map<char, int> s2Map;
            generateMap(element, s2Map);
            if(compareMaps(s1Map, s2Map))
                return true;
        }
        return false;
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size())
            return false;
        return findInclusion(s1, s2);
    }
};