from name_function import get_formatted_name

def check_exit_condition(parameter, exit):
	""" Returns True only if the user doesn't enter 'q' """
	if(parameter != exit):
		return True


print("Enter 'q' to quit at any point")
valid = True
exit = 'q'

while valid:
	first = input('Enter first name: \t')
	valid = check_exit_condition(first, exit)
	if(valid):
		last = input('Enter last name: \t')	
		valid = check_exit_condition(last, exit)
		if(not valid):
			print('User quit on last name')
		else:
			formatted_name = get_formatted_name(first, last)
			print("Welcome " + formatted_name)
	else:
		print('\n User quit for first name \n')


