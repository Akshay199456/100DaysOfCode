// Queues

#include<queue>
#include<vector>
using namespace std;

// Displays elements of the list
void displayList(vector<int> list){
    for(int element: list){
        cout<<"Element: "<<element<<"\n"; 
    }
}

// Pushes an element into the Queue from the vector
void pushQueue(vector<int> list, queue<int> & element_queue){
    cout<<"\n Pushing elements into the Queue \n";
    for(int element: list){
        element_queue.push(element);
    }
}

// Displays the Queue
void displayQueue(queue<int> element_queue){
    cout<<"\n Displaying Queue: \n";
    while(!element_queue.empty()){
        cout<<"Element: "<< element_queue.front()<<"\n";
        element_queue.pop();
    }
}

void displaySize(queue<int> element_queue){
    cout<<"\n Displaying size: "<<element_queue.size()<<"\n";
}

int main(){
    vector<int> list {1,2,3,5,6,7};
    queue<int> element_queue;
    displayList(list);
    pushQueue(list, element_queue);
    displayQueue(element_queue);
    displaySize(element_queue);
    cout<<"\n Element back: "<< element_queue.back()<<"\n";
    return 0;
}