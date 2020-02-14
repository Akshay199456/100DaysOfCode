function Vertex(vertex){
	this.vertex = vertex;
}

function Graph(vertexNumber){
	this.vertexNumber = vertexNumber;
	this.edges = 0;
	this.adj = [];
	this.queue = [];
	this.visited = [];
	this.addEdge = addEdge;
	this.toString = toString;
	this.showGraph = showGraph;
	this.dfs = dfs;
	this.bfs = bfs;

	// Initializing adjacency list
	for(let i=0; i<vertexNumber; i++){
		this.adj[i] = [];
	}

	// Initializing visitedVertex array
	for(let i=0; i<vertexNumber; i++){
		this.visited[i] = false;
	}
}


function addEdge(vertex1, vertex2){
	this.adj[vertex1].push(vertex2);
	this.adj[vertex2].push(vertex1);
	this.edges++;
}


function showGraph(){
	let result = "";
	for(let i =0; i<this.adj.length; i++){
		result+="Vertex "+i+"->";
		for(let j=0; j<this.adj[i].length; j++)
			result+=this.adj[i][j]+"->";
		console.log(result);
		result="";
	}
}


function dfs(vertex){
	if(this.visited[vertex]){

	}
	else{
		this.visited[vertex] = true;
		console.log(vertex);
		for(let i=0; i<this.adj[vertex].length; i++){
			this.dfs(this.adj[vertex][i]);
		}
	}
}


function bfs(vertex, initial){
	if(initial){
		this.queue.push(vertex);
		this.bfs(vertex, false);
	}
	
	else if(!initial && this.queue.length == 0)
	{

	}

	else{
		let element= this.queue.shift();
		this.visited[element] = true;
		console.log(element);
		for(let i=0; i<this.adj[element].length; i++){
			if(this.visited[this.adj[element][i]]!= true){
				this.queue.push(this.adj[element][i]);
			}
		}

		this.bfs(element, false);
	}
}


// Program execution begins here
g = new Graph(5); 
g.addEdge(0,1); 
g.addEdge(0,2); 
g.addEdge(1,3); 
g.addEdge(2,4); 
g.showGraph();
// console.log("DFS in progress: ");
// g.dfs(0);
console.log("BFS in progress");
g.bfs(0, true);
