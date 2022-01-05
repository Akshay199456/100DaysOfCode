# Python automatically sorts numbers and strings seperately in different manner.
number_list = [1,2,34,5,4,6,7]
string_list = ['Hello', 'Hi', 'Bye', 'Nigh']
print('Original number list: ', number_list)
print('Original string list: ', string_list)
number_list.sort()
string_list.sort()
print('Number list sorted: ', number_list)
print('String list sorted: ', string_list)


# Testing python functions

def describe_pet(cat, parrot, dog='tommy'):
	print('Cat: ', cat)
	print('Dog: ', dog)
	print('Parrot: ', parrot)
# Doesn't ignore extra arguments like JS does
print('First instance of describe_pet')
describe_pet('Millie', 'johnny', 'Sammy')


# Testing aliases

number_list = [1,2,34,5,4,6,7]
alias_list = number_list
print('Number list before testing: ', number_list)
print('Alias list before testing: ', alias_list)

alias_list[2] = 3
print('Number list after testing: ', number_list)
print('Alias list after testing: ', alias_list)


alias_clone = number_list[:]
print('Number list before clone: ', number_list)
print('Alias list before clone: ', alias_clone)

alias_clone[2] = 56
print('Number list after clone: ', number_list)
print('Alias list after clone: ', alias_clone)


# Testing inheritance
class BaseClass:
	def __init__(self):
		self.__privatemember = 'Hello'

class ChildClass(BaseClass):
	def display_private_member(self):
		print(self._BaseClass__private_member)
'''
	Even though private members are inherited, they can't be directly accessed
	by their name even in th child class. Only way to target them would be 
	through the self._BaseClass__private_member. This is because due to name
	mangling, the private member in the base class is inherited as 
	BaseClass__privatemember and cab only be accessed that way. If we
	had a private member in the child class we could access it using
	ChildClass__privatemember
''' 
objectFile = ChildClass()
print('Private member from outside class: ', objectFile._BaseClass__privatemember)
# object.display_private_member()


# Reading string from relative file ordering where file is within a folder within the current path
with open('text_folder/text_file.txt') as file_object:
	content = file_object.read()

print('Contents: \n\n', content)




# Using .join to append content
string = "Hello World"
string_list = [letter for letter in string]
string_tuple = tuple(string_list)
print('String tuple: ', string_tuple)
print('String list: ', string_list)
new_string = '$'.join(letter for letter in string)
print('Original string: ', string)
print('New string:', new_string)


# Appending elements to set using list
name_list = ['Hello', 'I', 'am', 'Akshay', 'Akshay']
name_set = set()
for name in name_list:
	name_set.add(name)
print('Name set: ', name_set)
print('Class of name set: ', type (name_set))

if 'Akshay' in name_set:
	print('Akshay is in the set')
	name_set.discard('Akshay')
	print('Akshay has been discarded. Current contents of list are: ', name_set)
