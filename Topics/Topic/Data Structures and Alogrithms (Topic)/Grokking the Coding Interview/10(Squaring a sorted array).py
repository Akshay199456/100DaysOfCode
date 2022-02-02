"""
Problem statement:
Given a sorted array, create a new array containing squares of all the numbers of the input array in the sorted order.

Example 1:

Input: [-2, -1, 0, 2, 3]
Output: [0, 1, 4, 4, 9]
Example 2:

Input: [-3, -1, 0, 1, 2]
Output: [0, 1, 1, 4, 9]

"""

"""
-------------------------    My Approaches:
1. two pointer approach
    Start: 8:33 pm
    End: 8:45 pm

    we can use the two pointer approach here to solve the problem. since we have a sorted input and we are triung to find a condition ()find the max element,
    we can use the two pointer approach. since the array is sorted, we know the max will only come fromt ehe ends of the array.
    this means that we can add elements from the end of t original array into the new array depending on the squared value and move the pointers either forward or backward.


    Time complexity: O(n)
    Space complexity: O(n)
*/
"""

"""
-------------------------    Other Approaches 
1.
    Start: 
    End: 

    

    Time complexity: O()
    Space complexity: O()
"""


"""
-------------------------    Notes
only trikck is that we can have negatgive numbers in the input array

an easier approach could be to first find th eindex of first non-negative number in array. after that, can use two-pointer approach
to iteratre the array. one pointer will mvoe forwards to iteratre non-negative numbers and other
will move backward to iterate negative numbers. at any step whichever bigger square will be added to output arrrray

alternate approach to use pointersstarting at both ends fo input array. whichever gives us the 
bigger sqaure, we add it to result array and move to next/previous number according to pointer
"""



#  My approaches(1)
def get_square(index,arr):
  return arr[index] * arr[index]

def fill_squares(arr, squares):
  beg, end = 0, len(arr)-1
  while beg <= end:
    beg_squared, end_squared = get_square(beg,arr), get_square(end, arr)
    if beg_squared > end_squared:
      squares.append(beg_squared)
      beg += 1
    else:
      squares.append(end_squared)
      end -= 1
  squares.reverse()

def make_squares(arr):
  squares = []
  # TODO: Write your code here
  fill_squares(arr, squares)
  return squares



# Other Approaches(1)
def make_squares(arr):
  n = len(arr)
  squares = [0 for x in range(n)]
  highestSquareIdx = n - 1
  left, right = 0, n - 1
  while left <= right:
    leftSquare = arr[left] * arr[left]
    rightSquare = arr[right] * arr[right]
    if leftSquare > rightSquare:
      squares[highestSquareIdx] = leftSquare
      left += 1
    else:
      squares[highestSquareIdx] = rightSquare
      right -= 1
    highestSquareIdx -= 1

  return squares


def main():

  print("Squares: " + str(make_squares([-2, -1, 0, 2, 3])))
  print("Squares: " + str(make_squares([-3, -1, 0, 1, 2])))


main()
