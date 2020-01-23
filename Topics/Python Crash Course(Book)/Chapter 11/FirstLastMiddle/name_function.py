# Chapter 11: Testing your code

def get_formatted_name(first, last, middle = ''):
	""" Generate a nearly formatted full name """
	if not middle:
		full_name = first + ' ' + last
	else:		
		full_name = first + ' ' + middle + ' ' + last
	return full_name.title()