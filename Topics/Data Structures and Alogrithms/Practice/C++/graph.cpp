#include<vector>

const int VERTICES = 5;

class Graph{
    private:
        vector<int> graph[5];
    public:
        void createGraph(vector<vector<int>>);
        void displayGraph();
        
};

void Graph::createGraph(vector<vector<int>> list){
    cout<<"\n Creating the graph \n";
    for(int i=0; i<list.size(); i++){
        graph[list[i][0]].push_back(list[i][1]);
        graph[list[i][1]].push_back(list[i][0]);
    }   
}

void Graph::displayGraph(){
    cout<<"\n Displaying the contents of the graph \n";
    for(int i=0; i<VERTICES; i++){
        cout<<"Element "<<i<<"->";
        for(int j=0; j<graph[i].size(); j++)
            cout<<" "<<graph[i][j];
        cout<<"\n";
    }
}

int main(){
    vector<vector<int>> list = {{0,1}, {0,4}, {1,4}, {1,3}, {1,2}, {2,3}, {3,4}};
    // displayList(list);
    Graph object = Graph();
    object.createGraph(list);
    object.displayGraph();
    return 0;
}