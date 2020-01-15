test = []
print(1==True)

# Testing for list modification

def modify_list(test_list):
	""" Modifying the contents of the list """
	count = 0
	for name in test_list:
		name += ' The Great'
		test_list[count] = name
		count += 1


test_list = ['Sam', 'Jungle', 'Mowgli']
print('List before modification: ', test_list)
# modify_list(test_list)
# print('List after modification: ', test_list)



# Slicing doesn't modify the list
print("\n\n Slicing the list now \n ")
modify_list(test_list[:])
print('List after modification: ', test_list)