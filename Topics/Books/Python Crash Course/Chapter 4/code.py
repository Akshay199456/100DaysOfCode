"""
	In order to run the code on Sublime Text itself, either go to Tools -> Build
	 -> Python or Ctrl + b shortcut.
"""


# List Comprehension - Combines for loop and the creation of new elements into 
# one line and automatically append each element


original_list =  [value for value in range(5)];
squares = [value ** 2 for value in range(5)];
print("This is the original list: ", original_list);
print("This is squares list: ", squares);



# Cubes using list comprehension

cubes_list = [value**3 for value in range(1,11)];
print("Cubes list: ", cubes_list);


# Tuples - immutable list that doesn't allow to change elements within the tuple
# Use can change what the tuple points to but not the contents of the tuple

animal_tuples = ('cat', 'dog', 'rabbit', 'elephant');
print("Tuples: ", animal_tuples);

"""
del animal_tuples;
print("Tuples check: ", animal_tuples);
"""

