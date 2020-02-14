function Stack() 
{ 
	this.dataStore = []; 
	this.top = -1; 
	this.push = push; 
	this.pop = pop; 
	this.peek = peek;
	this.length = length;
	this.clear = clear;
}

function push(element){
	this.dataStore[++this.top] = element;
}

function pop(){
	let removedValue = this.dataStore[this.top--];
	return removedValue;
}

function peek(){
	if(this.top>=0)
		return this.dataStore[this.top];
	else 
		return undefined;
}

function length(){
	return this.top+1;
}

function clear(){
	delete this.dataStore;
	this.dataStore = [];
	this.top = -1;
}



// Program execution starts here

var s = new Stack(); 
s.push("David"); 
s.push("Raymond"); 
s.push("Bryan"); 
console.log("length: " + s.length()); 
console.log(s.peek());
var popped = s.pop();
console.log("The popped element is: " + popped); 
console.log(s.peek());
s.push("Cynthia");
console.log(s.peek());
s.clear();
console.log("length: " + s.length()); 
console.log(s.peek());
s.push("Clayton");
console.log(s.peek());