# Counting word frequencies in file
FILE_NAME = 'file.txt'

freq = {}
with open(FILE_NAME) as file_object:	
	# Creates alias for the file object. Generates list of 
	# all tokens by converting them to lowercase and then splitting 
	# based on whitespace
	all_tokens = file_object.read().lower().split()

# print('Line array: ', all_tokens)

for token in all_tokens:
	# new_word is the concatenated token after removing any non-alpha characters
	new_word = ''.join(letter for letter in token if letter.isalpha())
	# print('New word: ', new_word)
	# print('Token: ', token)
	if new_word:
		freq[new_word] = 1 + freq.get(new_word, 0)


for (key , value) in freq.items():
	print('Token: {} , Count: {} '.format(key,value))
