#include<unordered_set>

/*
    Adiditonal methods:
        1. empty() -> tests whether unordered_set is empty
        2. size() -> returns number of elements in set
        3. find() -> returns iterator to element if it finds it else return unordered_set.end()
        4. count() -> returns count of element with specific key.
        5. clear() -> removes all elements from the set
        
*/

void insertElements(unordered_set<int> & element_set, vector<int> list){
    cout<<"\n Inserting elements into the set \n";
    for( int i=0; i<list.size(); i++)
        element_set.insert(list[i]);
}

void displayElements(unordered_set<int> element_set){
    cout<<"\n Displaying all elements of the set: ";
    for(auto it = element_set.begin(); it!=element_set.end(); it++)
        cout<<*it<<" ";
    cout<<"\n";       
}

void removeElement(unordered_set<int> & element_set, int element){
    if(element_set.find(element) != element_set.end())
        element_set.erase(element);
    else
        cout<<"\n Element was not found in set \n";
}

int main(){
    vector<int> list = {1,22,435,655,11,45,22,11};
    unordered_set<int> element_set;
    insertElements(element_set, list);
    displayElements(element_set);
    removeElement(element_set, 436);
    displayElements(element_set);
    return 0;
}