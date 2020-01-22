from restaurant import IceCreamStand

flavors = ['Chocolate', 'Vanilla', 'Strawberry']
iceboy = IceCreamStand("Berry's Ice Cream", 'Ice Cream Shop', flavors)

iceboy.display_intro()
print("The flavors we have are: ")
iceboy.display_flavors()




#  Creating an instance of the class
# asian = Restaurant('Bombay to Beijing', 'Asian')
# print(asian.restaurant_name)
# print(asian.cuisine_type)
# asian.describe_restaurant()
# asian.open_restaurant()