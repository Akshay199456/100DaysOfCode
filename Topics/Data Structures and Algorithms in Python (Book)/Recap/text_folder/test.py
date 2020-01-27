# Reading string from relative file ordering where file is in parent folder
with open('../code.txt') as file_object:
	count = 0
	for line in file_object:
		count += 1
		print("Line ", count, " : ", line)
	# content = file_object.readline()

# print('Contents: \n\n', content.strip())