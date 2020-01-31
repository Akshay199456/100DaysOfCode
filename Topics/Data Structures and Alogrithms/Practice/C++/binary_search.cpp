#include<algorithm>

void sort_list(vector<int> & list){
    cout<<"\n Sorting contents of the list: \n";
    sort(list.begin(), list.end());
}

void display_list(vector<int> list){
    cout<<"\n Displaying the contents of the list:";
    for(int i=0; i<list.size(); i++){
        cout<<" "<<list[i];
    }
    cout<<"\n";
}

void binary_search_element(vector<int> list, int element){
    auto iterator = lower_bound(list.begin(), list.end(), element);
    if(binary_search(list.begin(), list.end(), element))
        cout<<"\n Position where the element "<< element<<" was found was: "<< iterator - list.begin();
    else
        cout<<"\n The element is not present in the list \n";
}

int main(){
    vector<int> list = {22,45,11,8,134,55,22};
    sort_list(list);
    display_list(list);
    binary_search_element(list, 23);
    return 0;
}