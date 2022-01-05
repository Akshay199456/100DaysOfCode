// Class definition for Node
function Node(element, left, right){
	this.data = element;
	this.left = left;
	this.right = right;
	this.show = show;
}

// Member function of Node
function show(){
	return this.data;
}

// class definition for BST
function BST(){
	this.root = null;
	this.insert = insert;
	this.inOrder = inOrder;
}

function insert(element){
	let temp = this.root;
	const newNode = new Node(element, null, null);
	if(temp === null)
		this.root = newNode;
	else{
		let parent = null;
		while(temp!=null){
			parent = temp;
			if(newNode.data < temp.data)
				temp = temp.left;
			else
				temp = temp.right;
			}

		if(newNode.data > parent.data)
			parent.right = newNode;
		else
			parent.left = newNode;
	}
}

function inOrder(nodeElement){
	if(nodeElement!=null){
		inOrder(nodeElement.left);
		console.log(nodeElement.show());
		inOrder(nodeElement.right);
	}
}

function preOrder(nodeElement){
	if(nodeElement!=null){
		console.log(nodeElement.show());
		preOrder(nodeElement.left);
		preOrder(nodeElement.right);
	}	
}

function postOrder(nodeElement){
	if(nodeElement!=null){
		postOrder(nodeElement.left);
		postOrder(nodeElement.right);
		console.log(nodeElement.show());
	}	
}

// Program execution begins here
var nums = new BST(); 
nums.insert(23); 
nums.insert(45); 
nums.insert(16); 
nums.insert(37); 
nums.insert(3); 
nums.insert(99); 
nums.insert(22);
console.log("In order traversal");
inOrder(nums.root);
console.log("Pre order traversal");
preOrder(nums.root);
console.log("Post order traversal");
postOrder(nums.root);