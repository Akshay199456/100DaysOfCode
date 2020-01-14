# Getting input from user
# print("Hello World!")
"""
name = input("What's your name: \t")
print(name)
"""





# Testing set, dict, list properties
"""
obj = set({'name': 'Akshay', 'age' : 25, 'gender': 'male'});
print("Checking value in set: ", 'Akshay' in obj)
"""





# Polling set
"""
polling_data = {}
#print(len(polling_data))

choice = ''


while choice != 'no':
	name = input('Enter your name: ')
	response = input("What's your favorite hobby: ")

	if name in polling_data:
		print('Name already been taken. Enter a unique name: ')
	else:
		polling_data[name] = response

	choice = input("\n Do you want to continue entering more people (yes/no): ").lower()
	print("Choice in lower form: ", choice)	



# Prints dictionary
def printDictionary(polling_data):
	print("************************")
	print("Printing Dictionary")
	print("************************")

	for key, value in polling_data.items():
		print("Name: " + key + " Value: " + value)


printDictionary(polling_data)
"""


# No Pastrami
sandwich_order = ['chicken', 'pastrami', 'beef', 'onions', 'pastrami', 'capsicum', 'pastrami']
finished_sandwiches = []

hashset = set()
# print(sandwich_order)

print("Sorry! The deli has run out of pastrami!")

for type in sandwich_order:
	if type != 'pastrami':
		hashset.add(type)

for type in hashset:
	finished_sandwiches.append(type)

print("Finished sandwiches: ", finished_sandwiches)


