// ===================================================
//  Automating test function with a single describe

/*
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

*/
// ===================================================
// Nesting describes


function itStatement(expectedResult, nValue, i){
    it(`${i} expected result for ${nValue} power is ${expectedResult}`, function(){
            assert.equal(pow(i,nValue), expectedResult);
    });
}

describe("pow", function(){
    describe("to the power of 3", function(){
        function makeTestWithThirdPower(i){
            let expectedResult = i*i*i;
            itStatement(expectedResult, 3, i);
		}

		for(let i=0 ; i < 5; i++){
			makeTestWithThirdPower(i);
			// makeTestWithSixthPower(i);
		}
	});

	describe("to the power of 6", function(){
		function makeTestWithSixthPower(i){
			let expectedResult = i*i*i*i*i*i;
			itStatement(expectedResult, 6, i);
		}

		for(let i=0 ; i < 5; i++){
			// makeTestWithThirdPower(i);
			makeTestWithSixthPower(i);
		}
	});

	// Extending spec
    it("for negative values return NaN", function () {
        assert.isNaN(pow(2, -1));
    });

    it("for invalid inputs return NaN", function () {
        assert.isNaN(pow(2, 1.5));
    });
});




// ===================================================
// Using before/after and beforeEach/ afterEach
/*
describe("test", function () {
  before(() => alert("Testing started – before all tests"));
  after(() => alert("Testing finished – after all tests"));

  beforeEach(() => alert("Before a test – enter a test"));
  afterEach(() => alert("After a test – exit a test"));

  it('test 1', () => alert(1));
  it('test 2', () => alert(2));
});
*/