/*
Problem statement:

A bunch of cards is laid out in front of you in a line, where the value of each card ranges from 0 to 10^6. A pair of cards are matching if they have the same number value.

Given a list of integer cards, your goal is to match a pair of cards, but you can only pick up cards in a consecutive manner. What's the minimum number of cards that you need to pick up to make a pair? If there is no matching pairs, return -1.

For example, given cards = [3, 4, 2, 3, 4, 7], then picking up [3, 4, 2, 3] makes a pair of 3s and picking up [4, 2, 3, 4] matches two 4s. We need 4 consecutive cards to match a pair of 3s and 4 consecutive cards to match 4s, so you need to pick up at least 4 cards to make a match.


*/

/*
-------------------------    My Approaches:
1. Sliding window fo varying size

    we can use the sliding window apporach in order to solve this problem. since we just need to match one pari of cards, as we are going through the array
    we can insert each element intot he set as long ass the element in the array is not found in the set. if it is found
    in the set, then we have found a case that satisifes our condition, so we record it and then move the beg pointer forward to find a better solution that the one we had.

    Time complexity: O(n)
    Space complexity: O(n)
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes
1. burte foce

    can use brute force to find the next appearence of a card for every card in cards. the tuntime of this algorithm
    will be O(n^2) as there are n cards and finding its match each takes O(n) time.


2. Sliding Window

    a faster algorithm is to use a sliding window on the cards. essentuakky, this question is asking for the shortest subarray that 
    contains a duplicate. we start frm an emptyu window and continue adding cards to the right until we find a match, then we try to see whether we can discard some cards form the elft.
    wheilt he window is valid, we caompare for the shorter length and find the least number of consecutive cards that contains a match.

    we apply the flexible sliding window template to dinf the shortest subarray. since we are looking to match a pair, the deck is valid
    when the card that was just added intot he winodow matches with a previous card within the window. that is, the number value of
    cards[right[ appeared in our window twice , windowpcardspright]] == 2. then since we are looking for the shortest
    window, we increasmetn the elft pointer until cards[right[ no longer make a match. followig that, we will continue to search for other valued windows towards the right and find the shortest
    length/

    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <limits>
#include <unordered_set>

int least_consecutive_cards_to_match(std::vector<int> cards) {
    // WRITE YOUR BRILLIANT CODE HERE
    std::unordered_set<int> elementSet;
    int beg = 0, end = 0, minLength = std::numeric_limits<int>::max();
    
    
    if(!cards.size())
        return 0;
    
    while(end < cards.size()){
        if(elementSet.find(cards[end]) != elementSet.end()){
            minLength = std::min(minLength, end-beg+1);
            elementSet.erase(cards[beg++]);
        }
        else{
            elementSet.emplace(cards[end++]);
        }
    }
    
    return (minLength == std::numeric_limits<int>::max()) ? -1 : minLength;
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    ss >> std::boolalpha;
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

int main() {
    std::vector<int> cards = get_words<int>();
    int res = least_consecutive_cards_to_match(cards);
    std::cout << res << '\n';
}



//  Other Approaches(1)
#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <map> // map
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int least_consecutive_cards_to_match(std::vector<int>& cards) {
    std::map<int, int> window;
    int left = 0, shortest = cards.size()+1;
    for (int right = 0; right < cards.size(); ++right) {
        window[cards[right]]++;
        while (window[cards[right]] == 2) {
            shortest = std::min(shortest, right-left+1);
            window[cards[left]]--;
            ++left;
        }
    }
    return shortest != cards.size()+1 ? shortest : -1;
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    ss >> std::boolalpha;
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

int main() {
    std::vector<int> cards = get_words<int>();
    int res = least_consecutive_cards_to_match(cards);
    std::cout << res << '\n';
}   