console.log('Connected!');

/*
	5.4 Arrays
*/

let list = [1,2,3,4,5,6,];
console.log('List display: ', list);

// for..in loop - not recommended

for (key in list){
	console.log(`Key: ${key}, Value: ${list[key]}`)
}

// delete list[0]
console.log('List: ', list)


/*
	5.5 Array Methods	

	Different methods:
		1. Add/ Remove elements:

		pop, push, unshift, shift, splice

		2. Copy array:
		slice, concat 

		3. Iterables: 
		forEach, for, for...of

		4. Searching array:
		indexOf, lastIndexOf, includes, find, findIndex, filter

		5. Transform and Reorder array
		map, sort, reverse, split, join, reduce, reduceRight

*/


// Translate border-left-width to borderLeftWidth

function camelize(str){
	// Function should take a dash-separated-string to camelCase instead

	console.log('Initial string: ', str);
	let stringTokens = str.split('-');
	console.log('String tokens: ', stringTokens);
	for(let i=1; i< stringTokens.length; i++){
		stringTokens[i] = stringTokens[i].charAt(0).toUpperCase() + stringTokens[i].slice(1);
	}

	console.log('Checking array after modification: ', stringTokens);

	const result = stringTokens.join('');
	console.log('Result: ', result);
}

camelize('-webkit-transition');



// Filter range and in place
function filterRange(arr, a, b){
	// Takes an arr array, looks for elements between a and b in it and returns an array of them

	console.log('Initial array: ', arr);
	arr = arr.filter(item => item >= a && item<=b);
	console.log('Results: ', arr);
	return arr;
}

let arr = [5,3,8,1];
filterRange(arr, 1, 4);


