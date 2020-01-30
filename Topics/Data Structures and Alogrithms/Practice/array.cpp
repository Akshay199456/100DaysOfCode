#include<array>

/*
    Other methods:
        1. empty() -> checks if array is empty
        2. begin() -> referene to beginning of array
        3. end() -> reference past last element of array
*/

void display(array<int,7> list, string operation){
    if(operation.compare("front") == 0)
        cout<<"\n Element in front: " << list.front()<<"\n";
    else if(operation.compare("back") == 0)
        cout<<"\n Element at back: "<< list.back()<<"\n";
    else if(operation.compare("whole") == 0){
        cout<<"Elements in list: ";
        for(int i=0 ; i<list.size(); i++)
            cout<<list[i]<<" ";
        cout<<"\n";
    }
}

// can't add or remove elements because they are of fixed size
int main(){
    array<int,7> list = {1,2,3,45,6,77,69};
    display(list, "front");
    display(list, "back");
    display(list, "whole");
    return 0;
}