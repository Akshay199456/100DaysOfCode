console.log('Connected!');

/*
	8.1 Prototypal inheritance
*/

let animal = {
	jumps: true,
	walk(){
		console.log("Animal jumps");
	}
};

let rabbit = {
	walks : true,
	__proto__: animal,
	hello(){
		console.log("Hello");
	}
};

rabbit.hello();
rabbit.walk();

/*
	8.2 F.prototype
*/


/*
	8.3 Native Prototypes
*/

