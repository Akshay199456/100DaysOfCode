function createTwoDArray(rows,columns,initialValue){
	let array = [];
	for(let i=0; i<rows; i++){
		let rowArray = [];
		for(let j=0; j<columns; j++){
			rowArray[j] = initialValue;
		}
		array[i] = rowArray;
		//console.log("Row i is: "+ array[i]);
	}

	return array;
}

function printTwoDArray(array, rows, columns){
	for(let i=0; i<rows; i++){
		let row = [];
		for(let j=0; j<columns; j++){
			row.push(array[i][j]);
		}
		console.log(row.toString());
	}
}

let array = createTwoDArray(5, 5, 3);
printTwoDArray(array,5,5);