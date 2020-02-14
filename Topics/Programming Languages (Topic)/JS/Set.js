function Set(){
	this.dataStore = [];
	this.add = add;
	this.remove = remove;
	this.show = show;
}

function add(element){
	if(this.dataStore.indexOf(element)>0)
		return false;
	else
	{
		this.dataStore.push(element);
		return true;
	}
}

function remove(element){
	let positionIndex = this.dataStore.indexOf(element);
	if(positionIndex>0){
		this.dataStore.splice(positionIndex, 1);
		return true;
	}
	else
		return false;
}

function show(){
	return(this.dataStore);
}


// Program execution begins here
let names = new Set(); 
names.add("David"); 
names.add("Jennifer"); 
names.add("Cynthia"); 
names.add("Mike"); 
names.add("Raymond"); 

if (names.add("Mike")) {
   console.log("Mike added");
}
else {
	console.log("Can't add Mike, must already be in set");
}

console.log(names.show());
let removed = "Mike";

// console.log("We here!");
if (names.remove(removed)) {
   console.log(removed + " removed.");
}
else {
console.log(removed + " not removed.");
}

names.add("Clayton"); 
console.log(names.show()); 
removed = "Alisa";

if (names.remove("Mike")) {
   console.log(removed + " removed.");
}
else {
	console.log(removed + " not removed.");
}
