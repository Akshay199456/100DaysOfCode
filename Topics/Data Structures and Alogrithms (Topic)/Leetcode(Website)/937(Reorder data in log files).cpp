/*
-------------------------Question:
You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.

There are two types of logs:

Letter-logs: All words (except the identifier) consist of lowercase English letters.
Digit-logs: All words (except the identifier) consist of digits.
Reorder these logs so that:

The letter-logs come before all digit-logs.
The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
The digit-logs maintain their relative ordering.
Return the final order of the logs.

 

Example 1:

Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
Explanation:
The letter-log contents are all different, so their ordering is "art can", "art zero", "own kit dig".
The digit-logs have a relative order of "dig1 8 1 5 1", "dig2 3 6".
Example 2:

Input: logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
 

Constraints:

1 <= logs.length <= 100
3 <= logs[i].length <= 100
All the tokens of logs[i] are separated by a single space.
logs[i] is guaranteed to have an identifier and at least one word after the identifier.
*/

/*
]-------------------------    My Approaches:
1. Sorting using comparator

For the logs that are given to us, we can contine to store the digit logs into an array preseriving their relative ordering. However, for the letter logs, we will need to sort the entries using a custom comparator in order to ensure
proper ordering.

Time complexity: O(mnlogn) where m is length of each string, n is totall number of strings
Space complexity: O(mlog n)
*/

/*
-------------------------    Other approaches:

*/

// My Approaches(1)
class Solution {
public:
    string skipFirstToken(string & log, int & index){
        string identifier = "";
        int i;
        for(i=0; log[i] != ' '; i++)
            identifier += log[i];
        
        index = i+1;
        return identifier;
    }
     
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> results, digitLogs;
        vector<pair<string, string>> letterLogs;
        
        // collect all logs types
        for(int i=0; i<logs.size(); i++){
            int index = 0;
            string identifier = skipFirstToken(logs[i], index);
            if(isdigit(logs[i][index]))
                digitLogs.push_back(logs[i]);
            else{
                string identifier = logs[i].substr(0, index-1), content = logs[i].substr(index, logs[i].size() - index);
                letterLogs.push_back(make_pair(content, identifier));
            }
        }
        
        // sort letter logs based on condition
        sort(letterLogs.begin(), letterLogs.end(), []( const pair<string, string> & i1, const pair<string, string> &i2){
            if(i1.first.compare(i2.first) == 0)
                return i1.second.compare(i2.second) < 0;
            return i1.first.compare(i2.first) < 0;
        });
        
        // push letter logs into results
        for(int i=0; i<letterLogs.size(); i++)
            results.push_back(letterLogs[i].second + " " + letterLogs[i].first);
        
        // push digit logs into results
        for(int i=0; i<digitLogs.size(); i++)
            results.push_back(digitLogs[i]);
        
        return results;
    }
};