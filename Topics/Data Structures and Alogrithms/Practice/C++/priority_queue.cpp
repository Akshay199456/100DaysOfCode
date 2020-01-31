/*
    Prioirty queue can be used to implement both a max heap and min heap
    Syntax for max heap: priortity_queue<int> pq;
    Syntax for min heap: priority_queue<int, vector<int>, greater<int>> pq;
*/
    
#include <queue>

void create_priority_queue(vector<int> list, auto & pq, string operation){
    cout<<"\n Creating priority queue: (type) ";
    for(int i=0; i<list.size(); i++){
        pq.push(list[i]);
    }
    cout<<operation<<"\n";
}

void display_priority_queue(auto pq, string operation){
    cout<<"\n Displaying priority queue: (type) "<<operation<<"\n";
    while(!pq.empty()){
        cout<<" "<<pq.top();
        pq.pop();
    }
    cout<<"\n";
}

void display_size(auto pq){
    cout<<"\n Size of priority queue: "<<pq.size()<<"\n";
}


int main(){
    vector<int> list = {33, 56, 22, 11, 1, 24};
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    
    // Creating max heap     
    create_priority_queue(list, max_pq, "max");
    display_priority_queue(max_pq, "max");
    display_size(max_pq);
    
    // Creating min heap
    create_priority_queue(list, min_pq, "min");
    display_priority_queue(min_pq, "min");
    display_size(min_pq);
    return 0;
}