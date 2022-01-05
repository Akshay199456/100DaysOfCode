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




# Inheritance 

class IceCreamStand(Restaurant):
	def __init__(self, restaurant_name, cuisine_type, flavors):
		super().__init__(restaurant_name, cuisine_type)
		self.flavors = flavors

	def display_intro(self):
		print("Welcome to " + self.restaurant_name + ". We are an " + \
				self.cuisine_type)

	def display_flavors(self):
		for type in self.flavors:
			print(type, end=", ")