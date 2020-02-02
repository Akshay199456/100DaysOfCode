#include<vector>

const int VERTICES = 5;

class Graph{
    private:
        vector<int> graph[5];
        vector<bool> visited;
        queue<int> elements;
        void bfsImplement(queue<int> &, vector<bool> &);
    public:
        Graph();
        void createGraph(vector<vector<int>>);
        void displayGraph();
        void bfs();      
};

Graph::Graph(){
    for(int i=0; i<VERTICES; i++){
        visited.push_back(false);
    }
}

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
        cout<<" Element "<<i<<"->";
        for(int j=0; j<graph[i].size(); j++)
            cout<<" "<<graph[i][j];
        cout<<"\n";
    }
}

void Graph::bfsImplement(queue<int> & elements, vector<bool> & visited){
    cout<<"\n BFS being implemented \n";
    if(!elements.empty()){
        int currentIndex = elements.front();
        elements.pop();
        if(!visited[currentIndex]){
            visited[currentIndex] = true;
            cout<<"\n Element visited: "<<currentIndex<<endl;
            for(int j=0; j<graph[currentIndex].size(); j++){
                if(!visited[graph[currentIndex][j]])
                    elements.push(graph[currentIndex][j]);
            }
        }
        bfsImplement(elements, visited);
    }
}

void Graph::bfs(){
//     starting index to implement dfs from
    elements.push(0);
    cout<<"--------------------------\n";
    cout<<"\n Implementing BFS \n";
    cout<<"--------------------------\n";
    bfsImplement(elements, visited);    
}

int main(){
    vector<vector<int>> list = {{0,1}, {0,4}, {1,4}, {1,3}, {1,2}, {2,3}, {3,4}};
    // displayList(list);
    Graph object = Graph();
    object.createGraph(list);
    object.displayGraph();
    object.bfs();
    return 0;
}