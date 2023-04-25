/*
Problem statement:

Given a string s, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result. If not possible, return the empty string.

Example 1:
Input:s = "aab"
Output: aba
Example 2:
Input:s = "aaab"
Output: ``
Note:
s will consist of lowercase letters and have length in range [1, 500].
*/

/*
-------------------------    My Approaches:
1. using the other approaches(1) after learning about it

    so, we implemented this approach after learning about Other Approaches(1) and going through it first. tbf before we wnt through other approaches(1)
    we kind of deduced that if any char had count greater than (n+1)/2, it would nnot be psossible since two characters would
    then be adjacent to each other. we had also thopught of using map to store count of each character and then using a heap to store
    the counts in a max heap order. that way we would know the character with the most count. the only part i didnt know was to how we would go about filling he max character from the heap into
    the string. and that's where the other approaches(1) cane in. they thought of the string as a combination of odd and even indices and so
    from the heap, we take the max count character and fill it in the even indices as we go along. we then repeat that with the next
    max count character. if we run out of even indices, we can then use the odd indices instead. this way, we know the same character
    are always going to have at least one character between them and as a result solves the problem for us.

    lets analuze how they used heap as a moving best in order to solve the problem. 
    once they get the count of each character in the map and transfer that information into the heap, what they then do is
    take the max character count at each step and fill that fully into the result before moving on to the next max element 
    and repeating the same process again. this way they are using the best element to fill in the result as you are moving along
    as opposed to the typical top k where you store the top k results and then pop it.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
solution:
    we divide the indices of the string into two: odds and evens. in that case, elements with odd indices can only be adjacent to
    element with even indices and vice-versa. note that because the index starts at zero, there will always be more or equal evens than odds. if there
    are more of one character than the number of evens, it is impossible to rearrange the string so no adjacent characters are the same. otherwise, we can start from the character that
    occurs the most and fill out spots with even indices. once we run out of spots to fill, we fill out the spots with odd indices.
    in this case, the result will guarantee to have no same adjacent characters

    for implementation, we use a heap to guarantee the character that is repeated the most is processed first, and because the character repeated the most changes as we process more characters.


    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)
#include <iostream> // cin
#include <string> // getline, string
#include <unordered_map> // unordered_map
#include <queue>
#include <vector>
#include <utility>

void fillMap(std::unordered_map<char,int> & elementMap, std::string & s){
    for(int i=0; i<s.size(); i++){
        if(elementMap.find(s[i]) == elementMap.end())
            elementMap[s[i]] = 1;
        else
            elementMap[s[i]]++;
    }
}

void fillHeap(std::priority_queue<std::pair<int, char>> & pq, std::unordered_map<char,int> & elementMap){
    for(auto it = elementMap.begin(); it!= elementMap.end(); it++){
        std::pair<int, char> currPair = std::make_pair(it->second, it->first);
        pq.push(currPair);
    }
}

std::string evaluateResult(std::priority_queue<std::pair<int, char>> & pq, int n){
    std::vector<char> result(n,' ');
    int index = 0;
    if(pq.top().first > ((n+1)/2))
        return "";
    
    while(!pq.empty()){
        std::pair<int,char> currPair = pq.top();
        pq.pop();
        
        for(int i=0; i<currPair.first; i++){
            result[index] = currPair.second;
            index+=2;
            if(index >= n)
                index = 1;
        }
    }
    
    std::string temp(result.begin(), result.end());
    return temp;
}

std::string getResult(std::string & s){
    std::priority_queue<std::pair<int, char>> pq;
    std::unordered_map<char,int> elementMap;
    fillMap(elementMap, s);
    fillHeap(pq, elementMap);
    return evaluateResult(pq, s.size());
}

std::string reorganize_string(std::string s) {
    // WRITE YOUR BRILLIANT CODE HERE
    return getResult(s);
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::string res = reorganize_string(s);
    if (res.size() == 0) {
        std::cout << "Impossible" << std::endl;
        return 0;
    }
    std::unordered_map<char, int> s_counter;
    std::unordered_map<char, int> res_counter;
    for (char c : s) {
        if (s_counter.count(c)) {
            s_counter[c] += 1;
        } else {
            s_counter[c] = 1;
        }
    }
    for (char c : res) {
        if (res_counter.count(c)) {
            res_counter[c] += 1;
        } else {
            res_counter[c] = 1;
        }
    }
    if (s_counter != res_counter) {
        std::cout << "Not rearrangement" << std::endl;
        return 0;
    }
    for (int i = 0; i < res.size() - 1; i++) {
        if (res[i] == res[i + 1]) {
            std::cout << "Same character at index " << i << " and " << i + 1 << '\n';
        }
    }
    std::cout << "Valid" << std::endl;
}



//  Other Approaches(1)
#include <iostream> // cin
#include <queue> // priority_queue
#include <string> // getline, string
#include <unordered_map> // unordered_map

std::string reorganize_string(std::string s) {
    int n = s.size();
    std::unordered_map<char, int> char_count;
    for (char c : s) {
        if (char_count.count(c)) {
            char_count[c] += 1;
        } else {
            char_count[c] = 1;
        }
    }
    // Use a max heap to compare the multiplicity of each character
    auto compare = [](std::pair<char, int>& a, std::pair<char, int>& b) {
        // use < for max heap
        return a.second < b.second; 
    };
    std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, decltype(compare)> heap(char_count.begin(), char_count.end(), compare);
    // Return the empty string if there are too many of one character
    if (heap.top().second > (n + 1) / 2) return "";
    // Stores the resulting char array to be converted to string
    std::vector<char> res(n);
    // Pointer to the next item to be inserted
    // Increment by 2 until it reaches the end to fill out even positions,
    // then it is reset to 1 to fill out odd positions
    int ptr = 0;
    // Insert characters into the char array by their multiplicity
    while (heap.size() > 0) {
        std::pair<char, int> pairing = heap.top();
        heap.pop();
        for (int i = 0; i < pairing.second; i++) {
            res[ptr] = pairing.first;
            ptr += 2;
            if (ptr >= n) ptr = 1;
        }
    }
    std::string res_str(res.begin(), res.end());
    return res_str;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::string res = reorganize_string(s);
    if (res.size() == 0) {
        std::cout << "Impossible" << std::endl;
        return 0;
    }
    std::unordered_map<char, int> s_counter;
    std::unordered_map<char, int> res_counter;
    for (char c : s) {
        if (s_counter.count(c)) {
            s_counter[c] += 1;
        } else {
            s_counter[c] = 1;
        }
    }
    for (char c : res) {
        if (res_counter.count(c)) {
            res_counter[c] += 1;
        } else {
            res_counter[c] = 1;
        }
    }
    if (s_counter != res_counter) {
        std::cout << "Not rearrangement" << std::endl;
        return 0;
    }
    for (int i = 0; i < res.size() - 1; i++) {
        if (res[i] == res[i + 1]) {
            std::cout << "Same character at index " << i << " and " << i + 1 << '\n';
        }
    }
    std::cout << "Valid" << std::endl;
}