function List(){
	this.listSize = 0;
	this.pos = 0;
	this.dataStore = []; // initializes an empty array to store list elements 
	this.toString = toString;
	this.append = append;
	this.remove = remove;
	this.find = find;
	this.length = length;
	this.insert = insert;
	this.clear = clear;
	this.contains = contains;
	this.front = front;
	this.end = end;  
	this.prev = prev;
	this.next = next; 
	this.currPos = currPos; 
	this.moveTo = moveTo; 
	this.getElement = getElement;  
}

function append(element){
	this.dataStore[this.listSize++] = element;
}

function find(element){
	//console.log("In find");
	//console.log(this.dataStore);
	return this.dataStore.indexOf(element);
}

function contains(element){
	let index = this.find(element);
	if(index===-1){
		console.log("Element doesn't exist in list");
		return false;
	}

	else{
		console.log("Element found at index: " + index);
		return true;
	}
}

function remove(element){
	let index = this.find(element);
	if(index==-1){
		console.log("Element not found!");
		return false;
	}

	else{
		this.dataStore.splice(index,1);
		this.listSize--;
		console.log("Element has been removed");
		return true;
	}
}

function length(){
	return this.listSize;
}

function toString(){
	console.log("Displaying elements");
	return console.log(this.dataStore.join(" "));
}

function insert(element, position){
	if(position>this.dataStore.length)
		console.log("Positon exceeds length of list. Thus, element can't be inserted");
	else{
		this.dataStore.splice(position,0, element);
		++this.listSize;
		return true;
	}
	return false;
}

function clear(){
	delete this.dataStore;
	this.dataStore = [];
	this.listSize = 0;
}

function front(){
	this.pos = 0;
}

function end(){
	this.pos = this.listSize - 1;
}

function prev(){
	if(this.pos>0)
		this.pos--;
}

function next(){
	if(this.pos<this.listSize-1)
		this.pos++;
}

function currPos(){
	return this.pos;
}

function moveTo(position){
	if(position>=0 && position<=this.listSize-1)
		this.pos = position;
}

function getElement(){
	return this.dataStore[this.pos];
}


// Execution of code begins here
let names = new List();
names.append("Clayton"); 
names.append("Raymond"); 
names.append("Cynthia"); 
names.append("Jennifer"); 
names.append("Bryan"); 
names.append("Danny");


names.toString();
names.front();
console.log(names.getElement());
names.next();
console.log(names.getElement());
names.next();
names.next();
names.prev();
console.log(names.getElement());
