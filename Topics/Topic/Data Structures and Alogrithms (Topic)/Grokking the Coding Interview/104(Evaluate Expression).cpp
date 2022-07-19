/*
Problem statement:

Given an expression containing digits and operations (+, -, *), find all possible ways in which the expression can be evaluated by grouping the numbers and operators using parentheses.

Example 1:

Input: "1+2*3"
Output: 7, 9
Explanation: 1+(2*3) => 7 and (1+2)*3 => 9
Example 2:

Input: "2*3-4-5"
Output: 8, -12, 7, -7, -3 
Explanation: 2*(3-(4-5)) => 8, 2*(3-4-5) => -12, 2*3-(4-5) => 7, 2*(3-4)-5 => -7, (2*3)-4-5 => -3
*/

/*
-------------------------    My Approaches:
1. Breaking down the problem into compoenents (Not coded)

    we can solve this problem by breaking into components. there are two components to this problem. 
        1. getting the combination fo expressino
        2. evaluating expression
    
    now, to evaluate the expression is easy. as long as we have a postfix expression at this tage, we can use a stack to solve the problem.
    the difficulty is in generating the combinations. however, i think i was able to come up with a way to generate teh combinations.
    when we see an operand, its simple, we add it to the result.
    when we see an operator , there are a few options we have to generate combinations. we can add the current operator tto the stack and proceed, or wwe can keep removing one operator fromt he stack till the stackk is empty and at eachs tage push the current operator too the stack and continue to proceed.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Other Approaches 
1.

    Time complexity: O()
    Space complexity: O()
*/


/*
-------------------------    Notes


    Time complexity: O()
    Space complexity: O()
*/



//  My approaches(1)



//  Other Approaches(1)
