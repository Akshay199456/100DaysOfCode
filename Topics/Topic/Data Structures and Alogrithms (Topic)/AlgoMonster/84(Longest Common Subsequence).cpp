/*
Problem statement:

Given two strings word1 and word2, return the length of their longest common subsequence. This is often called Two Sequence Alignment Problem.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

If there is no common subsequence, return 0.

Example 1:
Input:
word1 = "abcde"
word2 = "ace"
Output: 3
Explanation:
The longest common subsequence is ace and its length is 3.

Example 2:
Input:
word1 = "almost"
word2 = "algomonster"
Output: 6
Explanation:
The longest common subsequence is almost and its length is 6.

Example 3:
Input:
word1 = "abc"
word2 = "def"
Output: 0
Explanation:
There is no such common subsequence, so the result is 0.
*/

/*
-------------------------    My Approaches:
1. Brute force

    While we didnt code the brute force approach, we did theorize the brute force approach correctly. you basically generate all combinations of 
    subsequences from one string and compare it against the next and do the vice versa and keep the max length that
    you have encoutnered when they match.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Other Approaches 
1. Brute force

    the brute force approach is to generate every possible subsequence, which is essentially generating subsets of the string.
    in O(2^n) time, where n is the length of the string, using a combinatorial search. once we have every subsequence of both strings of length m and n, we compare every pair of subsequences in O(n*m) time keeping
    track of which matching pair has the longest length. the final time complexit would be O(2^n + 2^m + n*m) which simplifies to
    O(2^n + 2^m)

    Time complexity: O(2^n + 2^m)
    Space complexity: O()


2. Brute force v2

    the next brute force solution will be slightly lower but will lead us to the dynamic progreamming solutions smoother.
    the idea is to consider both strings at the 'same time' remember that the overall problem is: what is the length of the lcs between strings
    word1 and word2.
    recall: a prefix of a string is a substring that starts at the first character.
    let lcs(i,j) represent the length of the lcs between a prefix of word1 of length i and a prefix of word2 of length j.

    the most obvious solution we have is that if i=0 or j=0, then lcs(i,j) = 0 since there cannot be an lcs if one of the strings is 
    empty.
    next, lets try solving lcs(i,j) if i!=0 and j!=0. we can try splitting the problem into two cases:
        1. word1[i] == word2[j]
        2. word1[i] != word2[j]
    
    in case(1), since the letters match, we try keeping these letters as a part of our LCS and then find the LCS of the rest of the 
    letters. so, lcs(i,j) = lcs(i-1,j-1)+1, where lcs(i-1,j-1) is the lcs of the rest of the letters and the 
    +1 since the letters match

    in case (2), since the letters dont match, we cannot keep these pair of letters and have to find the length of the longest lcs witht he rest of the letters
    possible including letters i or j. so lcs(i,j) = max{
        lcs(i-1,j),
        lcs(i,j-1),
        lcs(i-1,j-1)
    }
    where lcs(i-1,j) means kepping the jth letter but skipping the ith letter, lcs(i,j-1) means keeping the ith letter but skipping
    the jth letter, and lcs(i-1,j-1) means skipping both letters

    we can actually omit lcs(i-1,j-1) from case (2) since both lcs(i-1,j) and lcs(i,j-1) already depend on it. so, if
    lcs(i-1,j-1) is already optimal, its answer will be in either of the first two solutions

    the reason this is slower than our first brute force solutions is because thsi one runs in O(2^(n+m)) time since we are recursing through both strings at the same time 
    instead of separately.

    Additional notes:

    Looking back at this approach and solving it on a paper now makes a lot of sense. we were able to generate the tree structure
    which is the first step to a dp problem. and the way we did that was to break down the problem into
    smaller and smaller sub-problems from the top. we are trying to find the lcs for the whole of the two strings so we start from there.
    now, if the characters match on the indexes, then its great, we know we have a solution that works since the characters
    at i,j works. so we add 1 to our solution and try to get he lcs from the remaining indexes which in this case would be
    i-1,j-1 since characters at i,j match.

    the second case is when the characters at i,j dont match. if that is the case, then we know  characters at i,j dont match. so we have to find the next
    best solution potentials. so we try to find the max of the results that we can get from either i,j-1 or i-1,j
    since characters at i,j dont match and i,j can be made up from i-1,j or i,j-1. so that is where we start looking for solution.
    we continuie this till we get to our most basic unit which is whehn either i or j is 0 which means the result is 0, since
    the longest subsequence when either one of the strings in empty is 0 length.


3. DFS + Memoization

    for case (2) , lcs(i-1, j-1) is a subproblm of both lcs(i-1, j) and lcs(i,j-1). so instead of computing it twice,
    we can simply store its result and reuse it when needed using a 2d table.
    the runtime for this problem is (n*m) since there are O(n*m) states and each state takes O(1) to compute. Similarly
    the space complexity is O(n*m) due to use of the memo array.


4. Bottom-up

    finally we can solve the problem iteratively. the transition will reamin the same but we wil build our solution from the 
    samllest cases up to the largest. the order is essential since we are building upon previous results. we start from the top-left corner of our
    2d array and move row by row until we hit the bottom-right corner. this ensures that by the time we are calculating 
    dp[i][j], we have already computed dp[i-1][j], dp[i][j-1] and dp[i-1][j-1] which are the values we need
    to determine dp[i][j]

    runtime is still O(n*m) since there are O(n*m) states and each state takes O(1) to compute. similarly, the space
    complexity is O(n*m) with the ise of the dp array.
*/


/*
-------------------------    Notes


    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)



//  Other Approaches(1)
void generate_subsequences(string s, int n, string ans, vector<string> &subsequences) {
    // Base case: if the length is zero, add the current string to the subsequences list
    if (n == 0) {
        subsequences.emplace_back(ans);
        return;
    }
    // Include the current character and move to the next one
    generate_subsequences(s, n - 1, s[n - 1] + ans, subsequences);
    // Exclude the current character and move to the next one
    generate_subsequences(s, n - 1, ans, subsequences);
}
int longest_common_subsequence(string word1, string word2) {
    vector<string> word1_subsequences, word2_subsequences;
    // Generate all subsequences for word1
    generate_subsequences(word1, (int)word1.size(), "", word1_subsequences);
    // Generate all subsequences for word2
    generate_subsequences(word2, (int)word2.size(), "", word2_subsequences);
    int longest_match_length = 0;

    // Iterate through all subsequences of word1
    for (auto &subsequence1 : word1_subsequences) {
        // Compare with all subsequences of word2
        for (auto &subsequence2 : word2_subsequences) {
            // If a matching subsequence is found, update the longest_match_length
            if (subsequence1 == subsequence2) {
                int length = (int)subsequence1.size();
                longest_match_length = max(longest_match_length, length);
            }
        }
    }
    return longest_match_length;
}


// Other Approaches(2)
int lcs(int i, int j, string &word1, string &word2) {
  if (i == 0 || j == 0) {
    return 0;
  }
  if (word1[i - 1] == word2[j - 1]) {
    return lcs(i - 1, j - 1, word1, word2) + 1;
  }
  return max(lcs(i - 1, j, word1, word2), lcs(i, j - 1, word1, word2));
}

int longest_common_subsequence(string word1, string word2) {
  int n = word1.length();
  int m = word2.length();
  return lcs(n, m, word1, word2);
}


// Other Approaches(3)
int lcs(int i, int j, string &word1, string &word2, vector<vector<int>> &memo) {
  if (i == 0 || j == 0) {
    return 0;
  }
  if (memo[i][j] != -1) {
    return memo[i][j];
  }
  if (word1[i - 1] == word2[j - 1]) {
    return memo[i][j] = lcs(i - 1, j - 1, word1, word2) + 1;
  }
  return memo[i][j] = max(lcs(i - 1, j, word1, word2), lcs(i, j - 1, word1, word2));
}
int longest_common_subsequence(string word1, string word2) {
  int n = word1.length();
  int m = word2.length();
  vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
  return lcs(n, m, word1, word2, memo);
}


// Other approaches(4)
int longest_common_subsequence(string word1, string word2) {
    // Dimensions of the DP table
    int n = word1.length();
    int m = word2.length();

    // DP table initialized to zeros
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            // Base case: prefixes of zero length have LCS of length 0
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } // When current characters match, add 1 to the LCS length of the previous prefixes
            else if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } // Otherwise, exclude the current character of word1 or word2 and pick better option
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}