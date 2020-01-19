console.log('Connected');

/*
	9.1 Class Basic syntax
*/

class User{
	constructor(name){
		this.name = name;
	}

	sayHi(){
		return this.name;
	}
}

let object = new User('Akshay');
console.log(object.sayHi());



/*
	9.4 Private and protected properties and methods
*/
