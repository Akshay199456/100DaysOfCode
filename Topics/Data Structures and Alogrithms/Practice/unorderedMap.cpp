// Map opertions

#include <vector>
#include <unordered_map>
using namespace std; 

// Prints elements of the map given the map structure
void printMap(unordered_map<string,int> map){
    cout<<"\n Printing contents of Map: \n";
    for (auto it = map.begin(); it!=map.end(); it++) 
        cout << "\n Element: "<< it->first<< " Value: "<< it->second << "\n";
}

/*
chooseOperation has three particular actions it does:
    find - finds whether or not element exists
    delete - deletes element from the map if it exists
    add - adds element to map if it doesn't exis else modifies the value already present
*/
void chooseOperation(unordered_map<string,int> & map, string element, string operation, int position){
    auto iterator = map.find(element);
    if(operation.compare("find") == 0){
        if(iterator == map.end())
            cout<<"\n "<<element<<" element not found in map \n";
        else
            cout<<"\n "<<element<<" element found\n";
    }
    
    else if(operation.compare("delete") == 0){
        if(iterator == map.end())
            cout<<"\n "<<element<<" element doesn't exist in map \n";
        else{
            map.erase(element);
            cout<<"\n "<<element<<" element has been deleted \n";
        }
    }
    
    else if(operation.compare("add") == 0){
        map[element] = position;
    }
}

// Deletes the map itself
void deleteMap(unordered_map<string, int> & map){
    map.clear();
    cout<<"\n Map has been deleted \n";
}

int main() 
{ 
    unordered_map<string, int> map = {{"Hello", 0}, {"World",1}};
    printMap(map);
    chooseOperation(map, "HelloQueen", "find", NULL);
    chooseOperation(map, "HelloWorld", "delete", NULL);
    chooseOperation(map, "Pikachu", "add", 2);
    printMap(map);
    deleteMap(map);
    printMap(map);
    
    
    return 0; 
}