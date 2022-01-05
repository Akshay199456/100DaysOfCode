function Node(element){
	this.element = element;
	this.next = null;
}

function LinkedList(){
	this.head = new Node("head");
	// this.find = find;
	this.insert = insert;
	this.remove = remove;
	this.display = display;
}

function insert(element){
	let currentNode = this.head;
	while(currentNode.next!=null){
		currentNode = currentNode.next;
	}

	let newElement = new Node(element);
	currentNode.next = newElement;
	// this.display();
}

function display(){
	let currentNode = this.head;
	let output = "";
	while(currentNode!=null){
		output+="->"+currentNode.element;
		currentNode = currentNode.next;
	}
	console.log("Displaying linked list elements: ");
	console.log(output);
}

function remove(element){
	let currentNode = this.head;
	let nextNode = currentNode.next;
	if(nextNode === null)
		return false;
	else{
		while(nextNode!=null && nextNode.element != element){
			currentNode = nextNode;
			nextNode = nextNode.next;
		}

		if(nextNode===null)
			return false;
		else{
			currentNode.next = nextNode.next;
			nextNode.next = null;
			delete nextNode;
			return true;
		}
	}
}


// Program execution begins here

var cities = new LinkedList(); 
cities.insert("Conway"); 
cities.insert("Russellville");
cities.insert("Carlisle"); 
cities.insert("Alma"); 
cities.display();
let status = cities.remove("Almanter");
console.log("After removal. Status:  " + status);
cities.display();


