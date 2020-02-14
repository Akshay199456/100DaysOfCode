function Patient(name, code) { 
	this.name = name; 
	this.code = code;
}

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
	if(this.dataStore.length === 1)
		return this.dataStore.shift();
	else{
		let patient = this.dataStore[0];
		let patientPriority = patient.code;
		let index = 0;
		for(let i=1; i<this.dataStore.length; i++){
			if(patientPriority>this.dataStore[i].code){
				patient = this.dataStore[i];
				patientPriority = patient.code;
				index = i;
			}
		}

		return this.dataStore.splice(index,1);
	}
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
	let result = "";
	for(let i=0; i<this.dataStore.length; i++){
		result+="Name: "+this.dataStore[i].name+" Code: "+ this.dataStore[i].code+"\n";
	}
	return result;
}

function empty(){
	if(this.dataStore.length===0)
		return true;
	else 
		return false;
}


// Execution of program begins

var p = new Patient("Smith",5); 
var ed = new Queue(); 
ed.enqueue(p);
p = new Patient("Jones", 4); 
ed.enqueue(p);
p = new Patient("Fehrenbach", 6); 
ed.enqueue(p);
p = new Patient("Brown", 1); 
ed.enqueue(p);
p = new Patient("Ingram", 1);
ed.enqueue(p);
console.log(ed.toString());


var seen = ed.dequeue();
console.log("Patient being treated: " + seen[0].name); 
console.log("Patients waiting to be seen: ");
console.log(ed.toString());


// another round
var seen = ed.dequeue();
console.log("Patient being treated: " + seen[0].name); 
console.log("Patients waiting to be seen: "); 
console.log(ed.toString());

var seen = ed.dequeue();
console.log("Patient being treated: " + seen[0].name);
console.log("Patients waiting to be seen: ");
console.log(ed.toString());




