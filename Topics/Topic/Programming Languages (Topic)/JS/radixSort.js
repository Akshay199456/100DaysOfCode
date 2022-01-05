// This program only works for up to 2 digit numbers at max

function Queue(){ 
	this.dataStore = []; 
	this.enqueue = enqueue; 
	this.dequeue = dequeue; 
	this.front = front; 
	this.back = back; 
	this.toString = toString; 
	this.empty = empty;
}

function enqueue(element) { 
	this.dataStore.push(element);
}

function dequeue() {
	return this.dataStore.shift();
}

function front() {
	return this.dataStore[0];
}

function back() {
	return this.dataStore[this.dataStore.length-1];
}

function toString() {
	var retStr = "";
	for (var i = 0; i < this.dataStore.length; ++i) {
		retStr += this.dataStore[i] + "\n"; }
		return retStr; 
}

function empty() {
	if (this.dataStore.length == 0) {
	return true; 
	}
	else{
		return false;
	} 
}


function distribute(nums, queues, n, digit){
	// This function should distribute the numbers by the place 1's or 0's.
	for(let i=0; i<n; i++){
		if(digit === 1)
			queues[nums[i]%10].enqueue(nums[i]);
		else
			queues[Math.floor(nums[i]/10)].enqueue(nums[i]);
	}
}

function collect(queues, nums){
	let count = 0;
	// This function should collect the numbers from the queue
	for(let i=0; i<10; i++){
		while(!queues[i].empty()){
			nums[count++] = queues[i].dequeue();
		}
	}
}

function dispArray(array){
	return console.log(array.join(" "));
}

// Execution of program starts here
let queues = []; 

for(let i=0;i<10;++i){
	queues[i] = new Queue(); 
}

let nums = []; 
for(let i=0;i<10;++i){
   nums[i] = Math.floor(Math.floor(Math.random() * 100));
}

console.log("Before radix sort: ");
console.log("Nums: ");
dispArray(nums);
distribute(nums, queues, 10, 1);
console.log("Queues: ")
console.log(queues);
collect(queues, nums);
dispArray(nums);
distribute(nums, queues, 10, 10);
console.log(queues);
collect(queues, nums);
console.log("\n\nAfter radix sort: ");
dispArray(nums);