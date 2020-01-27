# importing necessary modules
from array import array
from sys import getsizeof


# Testing slicing properties
print('\n Before modification: \n')
temp = ['List', 'of', 'strings']
print('Original list: ', temp)
copy = temp[:2]
print('Copy: ', copy)

print('\n\n After modification: \n')
copy[0] = 'i'
print('Original list: ', temp)
print('Copy: ', copy)


# Array module
prime_list = [2,3,5,7,11,13]
primes = array('i', prime_list)
print('Primes array: ', primes)
print('Type of primes array: ', type(primes))
print('Size of primes array: ', getsizeof(primes))
print('Size of primes list: ', getsizeof(prime_list))


# Short-syntax for lists and matrices creation using default values
c_list = [5] * 10
print('C_List: ', c_list)
matrix = [[5] * 10 for j in range(3)]
print('Matrix: ', matrix) 

# Using string formatting

test_string = '{} and {}'. format('Romeo', 'Juliet')
print('Test string: ', test_string)