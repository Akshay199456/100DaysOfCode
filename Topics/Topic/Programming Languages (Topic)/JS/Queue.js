function Queue() { 
	this.dataStore = []; 
	this.enqueue = enqueue; 
	this.dequeue = dequeue; 
	this.front = front; 
	this.back = back; 
	this.toString = toString; 
	this.empty = empty;
}

function enqueue(element){
	this.dataStore.push(element);
}

function dequeue(){
	return this.dataStore.shift();
}

function front(){
	if(this.dataStore.length>0)
		return this.dataStore[0];
	else 
		return undefined;
}

function back(){
	if(this.dataStore.length>0)
		return this.dataStore[this.dataStore.length-1];
	else
		return undefined;
}

function toString(){
	return this.dataStore.join(" ");
}

function empty(){
	if(this.dataStore.length===0)
		return true;
	else 
		return false;
}

// Execution of program starts here
var q = new Queue(); 
q.enqueue("Meredith"); 
q.enqueue("Cynthia"); 
q.enqueue("Jennifer");
console.log(q.toString());
q.dequeue();
console.log(q.toString());
console.log("Front of queue: " + q.front());
console.log("Back of queue: " + q.back());
