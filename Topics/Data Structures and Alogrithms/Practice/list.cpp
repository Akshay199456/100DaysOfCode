// List - Doubly-linked list
/*
Other methods:
    1. pop_front() - Removes the front element; doesn't return anything
    2. pop_back() - Removes the end element; doesn't return anything
    3. insert() - Inserts new element before element at specified position given position of the element
    4. erase() - Removes element from specified position given the position of the element
*/

#include<list>
#include<utility>

using namespace std;

// Inserts elements into the list at the front or the back
void insertElement(list<pair<string,int>> & elements, string stringElement, int intElement, string position){
    cout<<"\n Inserting elements into the list: \n";
    pair<string, int> newPair = make_pair(stringElement, intElement);
    if(position.compare("front") == 0)
        elements.push_front(newPair);
    else if(position.compare("end") == 0)
        elements.push_back(newPair);
}

// Dispalys elements of the list
void displayList(list<pair<string,int>> elements){
    cout<<"\n Displaying elements of the list: \n";
    for(auto iterator = elements.begin(); iterator!=elements.end(); iterator++){
        cout<<iterator->first<<" "<<iterator->second<<"\n";
    }
}

// Return size of the list
void displaySize(list<pair<string,int>> elements){
    cout<<"\n Is elements list empty: "<< elements.empty();
    cout<<"\n Elements list is of length: "<< elements.size();
}

// Removes element with given value
void removeElement(list<pair<string,int>> & elements, pair<string,int> element_pair){
    cout<<"\n Removing pair: \n";
    elements.remove(element_pair);
}

int main(){
    list<pair<string, int>> elements;
    insertElement(elements, "Hello", 2, "front");
    insertElement(elements, "World", 2, "end");
    displayList(elements);
    displaySize(elements);
    // pair<string, int> newPairFront = elements.front();
    pair<string, int> newPairFront = make_pair("Why", 3);
    cout<<"\n Element at front: "<<newPairFront.first<<" & "<<newPairFront.second;
    removeElement(elements, newPairFront);
    displayList(elements);
    // cout<<elements.pop_front().first;
    return 0;
}