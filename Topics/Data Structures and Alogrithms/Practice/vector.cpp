#include<vector>
#include<algorithm>
/*
    Other methods:
        1. front() -> returns element at the front of the vector
        2. size() -> returns the size of the vector
        3. erase() -> removes element from the vector based on iterator
*/

using namespace std;

void insertElement(vector<int> & list, int element){
    /* Inserts element into the list at the end of the list*/
    cout<<"\n Element "<<element<<" has been added to the end of the list \n";
    list.push_back(element);
}

void displayVector(vector<int> list){
    cout<<"\n Displaying all the elements of the vector \n";
    // for(int element: list)
    //     cout<<element<<" ";
    for(auto it = list.begin(); it!=list.end(); it++)
        cout<<*it<<" ";
    cout<<"\n";
}

auto findPositionOfElement(vector<int> & list, int element){
    for(int i = 0; i < list.size() ; i++){
        if(list[i] == element){
            auto position = list.begin() + i;
            cout<<"\n Element "<<*position<<" found at position: "<< i<<"\n";
            return position; 
        }
    }
    return list.end();
}

void removeElement(vector<int> & list, string position, int element){
    /* Removes element from the end of the list */
    if(position.compare("back")==0){
        cout<<"\n Element at the back is: "<<list.back();
        list.pop_back(); 
        cout<<". It has been removed\n";
    }
    
    else if(position.compare("anywhere")==0){
        auto iterator = findPositionOfElement(list, element);
        if(iterator == list.end())
            cout<<"\n Couldn't find element "<< element<< " in list \n";
        else{
            cout<<"\n Element "<< *iterator <<" has been deleted \n";
            list.erase(iterator);
        }
    }
}

int main(){
    vector<int> list;
    insertElement(list, 2);
    insertElement(list, 3);
    insertElement(list, 4);
    insertElement(list, 5);
    insertElement(list, 6);
    insertElement(list, 7);
    displayVector(list);
    removeElement(list, "anywhere", 7);
    removeElement(list, "back", 0);
    displayVector(list);
    
    return 0;
}