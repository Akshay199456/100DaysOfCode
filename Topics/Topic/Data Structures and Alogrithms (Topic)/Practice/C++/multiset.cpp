/*
    Multisets and multimaps allow multiple keys with same value
    and elements of the data structure are sorted
    
    UnorderedMultiset and unorderedmultiset allow multiple keys of the same values
    but the keys are not sorted
    
    Methods for all the 4 of them are almost the same

    Other additional methods:
        1. empty() -> tests whether the container is empty
        2. size() -> returns the number of elements in the container
        3. clear() -> clears the container  
*/
#include<unordered_set> // or #include<multimap

void displaySet(unordered_multiset<int> set){
    cout<<"\n Displaying elements of the set:";
    for(auto it = set.begin(); it != set.end(); it++)
        cout<<" "<<*it;
    cout<<"\n";
}

void insertElement(unordered_multiset<int> & set, int element){
    cout<<"\n Appending element "<< element<< " to the set \n";
    set.insert(element);
}

auto findElement(unordered_multiset<int> & set, int element){
    cout<<"\n Checking if element "<<element<<" exists in the set \n";
    return set.find(element);
}

void removeElement(unordered_multiset<int> & set, int element){
    auto iterator = findElement(set, element);
    if(iterator != set.end()){
        // Only removes the first occurrence of the element
        cout<<"\n Element "<<element<<" was found and has been removed\n";
        set.erase(iterator);
    }
    else
        cout<<"\n Couldn't find the element "<<element<<" in the set\n";
}

void countElement(unordered_multiset<int> set, int element){
    cout<<"\n Number of instances of "<<element<<" : "<<set.count(element);
}



int main(){
    unordered_multiset<int> set = {1,2,3,34,5,23,5,6,6};
    displaySet(set);
    insertElement(set, 39);
    displaySet(set);
    removeElement(set, 6);
    displaySet(set);
    countElement(set, 233);
    return 0;
}