function Dictionary(){
	this.dataStore = [];
	this.length = 0;
	this.add = add;
	this.find = find;
	this.remove = remove;
	this.showAll = showAll;
	this.count = count;
	this.clear = clear;
	this.showAllSorted = showAllSorted;
}

function add(key, value){
	this.dataStore[key] = value;
	this.length++;
}

function find(key){
	return this.dataStore[key];
}

function remove(key){
	delete this.dataStore[key];
	this.length--;
}

function showAll(){
	for(const key of Object.keys(this.dataStore)){
		// console.log(key);
		console.log(key + " -> "+ this.dataStore[key]);
	}
}


function count(){
	let countKeys = 0;
	for(const key of Object.keys(this.dataStore)){
		countKeys++;
	}

	return countKeys;
}

function clear(){
	for(const key of Object.keys(this.dataStore)){
		delete this.dataStore[key];
	}

	this.length = 0;
}

function showAllSorted(){
	let sortedKeys = Object.keys(this.dataStore).sort();
	// console.log(sortedKeys);
	for(const key of sortedKeys){
		console.log(key+" -> "+ this.dataStore[key]);
	}
}

// Program execution begins here

var pbook = new Dictionary(); 
pbook.add("Raymond","123"); 
pbook.add("David", "345"); 
pbook.add("Cynthia", "456"); 
pbook.add("Mike", "723"); 
pbook.add("Jennifer", "987"); 
pbook.add("Danny", "012"); 
pbook.add("Jonathan", "666"); 
pbook.showAllSorted();
