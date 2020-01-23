# Chapter 10: Files and Exceptions

FILENAME = 'file.txt'
"""
with open(FILENAME) as file_object:
	# Stores file as a list of lines
	lines = file_object.readlines()

print("Lines: ", lines)
"""

"""
# Exceptions

try:
	print(5/0)

except ZeroDivisionError:
	# Runs if it encounters a ZeroDivisionError exception
	print("You can't divide by zero")
"""

# Addition exception
"""
try:
	num1 = int(input('Enter number 1'))
except ValueError:
	print('Number 1 is not a number')
else:
	try:
		num2 = int(input('Enter number 2'))
	except ValueError:
		print('Number 2 is not a number')
	else:
		sumTotal = num1 + num2
		print("The total sum is: " + str(sumTotal))
"""

# Common Words

word_search = 'the'

try:
	with open(FILENAME) as file_object:
		lines = file_object.readlines()
except FileNotFoundError:
	print("\n*The file was not found in that location*")
else:
	sum_count = 0
	for line in lines:
		# Converts the line to lowercase, removes extra whitespace from both ends
		# and splits it into tokens
		line_list = line.lower().strip().split()
		sum_count += line_list.count(word_search)
	print("The total number of occurrences of 'the' is: ", sum_count)
