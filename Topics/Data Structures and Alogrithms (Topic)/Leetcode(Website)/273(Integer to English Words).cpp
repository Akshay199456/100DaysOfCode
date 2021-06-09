/*
-------------------------Question:
Convert a non-negative integer num to its English words representation.

 

Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"
Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Example 4:

Input: num = 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
 

Constraints:

0 <= num <= 231 - 1
*/

/*
-------------------------    My Approaches:
1. Setting conditions and using them as prefixes, suffixes and elsewhise

The problem has certiain patterns that wc can use to solve. It has prefixes, suffixes and terms depending on the value of the 3 membered value

Time complexity: O(n)
Space omplexity: O(n)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    vector<string> belowTen = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> belowTwenty = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> restPrefixes = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> suffixes = {"Billion", "Million", "Thousand", "Hundred"};
    
    vector<int> obtainTokens(int num){
        vector<int> tokens;
        int total = 0, count  = 0;
        while(num != 0){
            int rem = num % 10;
            total += (int) pow(10, count) * rem;
            ++count;
            num = num / 10;
            
            if(count == 3){
                tokens.push_back(total);
                count = 0;
                total = 0;
            }
        }
        
        if(count != 3){
            tokens.push_back(total);
            count = 0;
            total = 0;
        }
        return tokens;
    }
    
    
    void reverseTokens(vector<int> & numTokens){
        for(int i=0; i<numTokens.size()/2 ; i++){
            int temp = numTokens[i];
            numTokens[i] = numTokens[numTokens.size()-i-1];
            numTokens[numTokens.size()-i-1] = temp;
        }
    }
    
    void printTokens(vector<int> & numTokens){
        for(int i=0; i<numTokens.size(); i++)
            cout<<numTokens[i]<<" ";
        cout<<endl;
    }
    
    string getString(int num, int index){
        string result = "";
        int numCopy = num;
        
        // string for hundred's place
        if(num >= 100){
            result += belowTen[num/100] + " Hundred ";
            num = num % 100;
        }  
        
        // string for ten's and one's place
        if(num >= 20){
            result += restPrefixes[num/10] + " ";
            if(num % 10 != 0)
                result += belowTen[num % 10] + " ";
        }
        else if(num >= 10)
            result += belowTwenty[num % 10] + " ";
        else if(num >= 1)
            result += belowTen[num%10] + " ";
        
        // string for suffix
        if(index != 3 && numCopy > 0)
            result += suffixes[index] + " ";
        
        return result;
    }
    
    int trimLeading(string & result, unordered_set<int> & spaceIndexes){
        int i;
        for(i=result.size()-1; i>=0 && result[i] == ' '; i--)
            spaceIndexes.emplace(i);
        return i;
    }
    
    int trimTrailing(string & result, unordered_set<int> & spaceIndexes){
        int i;
        for(i=0 ; i < result.size() && result[i] == ' '; i++)
            spaceIndexes.emplace(i);
        return i;
    }
    
    void trimBetween(string & result, unordered_set<int> & spaceIndexes, int begIndex, int endIndex){
        for(int i=begIndex+1; i <= endIndex; i++){
            if(result[i] == ' ' && result[i] == result[i-1])
                spaceIndexes.emplace(i);
        }
    }
    
    
    void filterSpaces(string & result, unordered_set<int> & spaceIndexes){
        int correctedIndex = 0;
        for(int i=0; i<result.size(); i++){
            if(spaceIndexes.find(i) == spaceIndexes.end())
                result[correctedIndex++] = result[i];
        }
        
        while(result.size() > correctedIndex)
            result.pop_back();
    }
    
    void fixSpace(string & result){
        unordered_set<int> spaceIndexes;
        int endIndex = trimLeading(result, spaceIndexes);
        int begIndex = trimTrailing(result, spaceIndexes);
        trimBetween(result, spaceIndexes, begIndex, endIndex);
        filterSpaces(result, spaceIndexes);
    }
    
    string convertToEnglish(int num){
        string result = "";
        vector<int> numTokens = obtainTokens(num);
        while(numTokens.size() < 4)
            numTokens.push_back(0);
        reverseTokens(numTokens);
        
        for(int i=0; i< numTokens.size(); i++){
            string stringValue = getString(numTokens[i], i);
            result += stringValue + " ";
        }
        
        fixSpace(result);
        return result; 
    }
    
    string numberToWords(int num) {
        if(!num)
            return belowTen[num];
        return convertToEnglish(num);
    }
};