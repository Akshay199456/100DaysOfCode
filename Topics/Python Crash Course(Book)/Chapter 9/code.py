# Classes

class Restaurant():
	''' Creates a Restaurant class '''
	def __init__(self, restaurant_name, cuisine_type):
		''' Constructor '''
		self.restaurant_name = restaurant_name
		self.cuisine_type = cuisine_type

	def describe_restaurant(self):
		''' Prints the attributes of the class '''
		print('Restaurant: ', self.restaurant_name)
		print('Cuisine: ', self.cuisine_type)

	def open_restaurant(self):
		''' Prints that the restaurant is open '''
		print('The restaurant is now open!')





#  Creating an instance of the class
asian = Restaurant('Bombay to Beijing', 'Asian')
print(asian.restaurant_name)
print(asian.cuisine_type)
asian.describe_restaurant()
asian.open_restaurant()