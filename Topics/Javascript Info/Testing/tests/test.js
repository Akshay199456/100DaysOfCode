describe("pow", function() {

function makeTest(i){
	let expectedResult = i*i*i;
	it(`${i} expected result for 3-rd power is ${expectedResult}`, function(){
		assert.equal(pow(i,3), expectedResult);
	});
}


//  Automating tests

for(let i=0 ; i < 10; i++)
	makeTest(i);

});