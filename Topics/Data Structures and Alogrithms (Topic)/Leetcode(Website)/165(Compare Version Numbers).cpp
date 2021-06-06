/*
-------------------------Question:

Given two version numbers, version1 and version2, compare them.

Version numbers consist of one or more revisions joined by a dot '.'. Each revision consists of digits and may contain leading zeros. Every revision contains at least one character. Revisions are 0-indexed from left to right, with the leftmost revision being revision 0, the next revision being revision 1, and so on. For example 2.5.33 and 0.1 are valid version numbers.

To compare version numbers, compare their revisions in left-to-right order. Revisions are compared using their integer value ignoring any leading zeros. This means that revisions 1 and 001 are considered equal. If a version number does not specify a revision at an index, then treat the revision as 0. For example, version 1.0 is less than version 1.1 because their revision 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.

Return the following:

If version1 < version2, return -1.
If version1 > version2, return 1.
Otherwise, return 0.
 

Example 1:

Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both "01" and "001" represent the same integer "1".
Example 2:

Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: version1 does not specify revision 2, which means it is treated as "0".
Example 3:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Explanation: version1's revision 0 is "0", while version2's revision 0 is "1". 0 < 1, so version1 < version2.
Example 4:

Input: version1 = "1.0.1", version2 = "1"
Output: 1
Example 5:

Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1
*/

/*
-------------------------    My Approaches:
1. Splitting into tokens and comparing values

We can split the string into tokens hich we can then compare the values associated with them and finally return the values.

Time complexity: O(max(n,m))
Space complexity: O(max(n,m))


2. Two pointer approach

Time complexity: O(max(m,n))
Space complexity: O(1)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    vector<int> getToken(string stringValue){
        string value = "";
        vector<int> intList;
        for(int i=0; i< stringValue.size(); i++){
            if(stringValue[i] == '.'){
                intList.push_back(stoi(value));
                value = "";
            }
            else
                value += stringValue[i];
        }
        
        intList.push_back(stoi(value));
        return intList;
    }
    
    vector<vector<int>> splitValues(vector<string> stringValues){
        vector<vector<int>> result;
        for(int i=0; i< stringValues.size(); i++){
            vector<int> intToken = getToken(stringValues[i]);
            result.push_back(intToken);
        }
        return result;
    }
    
    void appendZeros(vector<int> & intValue, int diff){
        while(diff--)
            intValue.push_back(0);
    }
    
    int compareValues(vector<int> intValue1, vector<int> intValue2){
        for(int i=0; i<intValue1.size(); i++){
            if(intValue1[i] < intValue2[i])
                return -1;
            else if(intValue2[i] < intValue1[i])
                return 1;
        }
        return 0;
    }
    
    int compareSizeAndValues(vector<vector<int>> & intValues){
        if(intValues[0].size() < intValues[1].size())
            appendZeros(intValues[0], intValues[1].size() - intValues[0].size());
        else if(intValues[0].size() > intValues[1].size())
            appendZeros(intValues[1], intValues[0].size() - intValues[1].size());
        
        return compareValues(intValues[0], intValues[1]);
    }
    
    int compareVersion(string version1, string version2) {
        vector<int> value1, value2;
        vector<string> stringValues {version1, version2};
        vector<vector<int>> intValues = splitValues(stringValues);
        return compareSizeAndValues(intValues);
    }
};


// My Approaches(2)
class Solution {
public:
    int getValue(string text, int & ptr){
        string stringValue = "";
        while(text[ptr] != '.' && ptr < text.size()){
            stringValue += text[ptr++];
        }
        ptr++;
        return stoi(stringValue);
    }
    
    int compareStrings(string version1, string version2, int & ptr1, int & ptr2){
        while(ptr1 < version1.size() && ptr2 < version2.size()){
            int value1 = getValue(version1, ptr1);
            int value2 = getValue(version2, ptr2);
            if(value1 < value2)
                return -1;
            else if(value1 > value2)
                return 1;
        }
        
        if(ptr1 == version1.size() + 1 && ptr2 == version2.size() + 1)
            return 0;
        else if(ptr2 < version2.size() + 1){
            while(ptr2 != version2.size()){
                ptr1 = 0;
                return compareStrings("0", version2, ptr1, ptr2);   
            }
        }
        else{
            while(ptr1 != version1.size()){
                ptr2 = 0;
                return compareStrings(version1, "0", ptr1, ptr2);   
            }
        }
        return INT_MAX;
    }
    
    int compareVersion(string version1, string version2) {
        int ptr1 = 0, ptr2 = 0;
        return compareStrings(version1, version2, ptr1, ptr2);
    }
};