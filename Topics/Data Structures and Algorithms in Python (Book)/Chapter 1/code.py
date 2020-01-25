''' Testing aliases and concatenation '''

alpha = [1,2,3,4,5]
print('Initial value of alpha: ', alpha)
beta = alpha
print('Initial valud of beta: ', beta)

# Modifies both the alias and the original list
beta += [6,7]
print('Second value of alpha: ', alpha)
print('Second value of beta: ', beta)

# Only modifies the alia but doesn't change the original list
beta = beta + [8,9]
print('Third value of alpha: ', alpha)
print('Third value of beta: ', beta)



''' Testing function return values '''

def hello_world():
	# returns None since no return statement added
	print("Hello World!")

return_value = hello_world()
print('Return value: ', return_value)


''' Defining and testing a generator '''
def factors(n):
	for index in range(1, n+1):
		if (n % index == 0):
			yield index

print('Testing the factors generator:')
for value in factors(100):
	print('Factor value: ', value)


''' List comprehension '''
n = 100
factor_list = [value for value in range(1, n) if n % value == 0]
print('Factor List: ', factor_list)
