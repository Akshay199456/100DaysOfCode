/*
  Returns x raised to n-th power
  @param {Number} x Number to raise
  @param {Number} n Power to be raised by; must be natural number
  @return {Number} result x raised to n-th power  
*/

function pow(x, n) {
  /* function code is to be written, empty now */
  if(Math.floor(n)!==n || n<0)
    return NaN;
      
  let result = 1;
  for(let i = 0 ; i < n ; i++){
    result *= x;
  }

  return result;
}