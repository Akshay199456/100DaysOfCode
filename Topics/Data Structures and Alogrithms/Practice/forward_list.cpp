#include<forward_list>

/*
	Forward lists - Singly linked lists
    Additional methods:
        1. front() -> returns reference to the first element
        2. empty() - > returns a bool value indicating whether forward_list container is empty or not
        3. size() -> returns size of list
        4. insert_after() -> inserts after a particular element given the reference to the element
        5. erase_after() -> removes after a particular element given the reference to that element
        6. clear() -> removes all elements from the list
        7. sort() -> sorts the elements of the linked list
        8. reverse() -> reverses the elements of the linked list.
        
*/

void displayList(forward_list<int> list){
    cout<<"\n Displaying the elements of the list \n";
    for(auto it = list.begin(); it!=list.end(); it++){
        cout<<"Element: "<<*it<<"\n";
    }
}

void insertElement(forward_list<int> & list, int element, string operation){
    cout<<"Element "<< element<<" has been inserted\n";
    if (operation.compare("front") == 0)
        list.push_front(element);
}

bool checkElementExists(forward_list<int> list, int element){
    for(auto it = list.begin(); it!=list.end(); it++){
        if(*it == element)
            return true;
    }
    return false;
}

void removeElement(forward_list<int> & list, string operation, int element){
    if(operation.compare("front") == 0){
        list.pop_front();
        cout<<"\n Element "<<element<<" has been deleted\n";
    }
    else if(operation.compare("value") == 0){
        if(checkElementExists(list, element))
            list.remove(element); // remove() removes all instances of the value in the forward_list
        else
            cout<<"\n Element "<< element<<" was not found in the list: \n";
    }
}

int main(){
    forward_list<int> list = {1,23,45,10,11,23};
    displayList(list);
    insertElement(list, 36, "front");
    displayList(list);
    removeElement(list, "front", -1);
    removeElement(list, "value", 23);
    displayList(list);
    return 0;
}