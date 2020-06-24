input_string = "This is a test. That is not a test. Test"
# input_string = ("From the moment the first immigrants arrived on these shores, generations of parents have worked hard " + 
# "and sacrificed whatever is necessary so that their children could have the same chances they had; or " +
# "the chances they never had. Because while we could never ensure that our children would be rich or " +
# "successful; while we could never be positive that they would do better than their parents, America is " +
# "about making it possible to give them the chance. To give every child the opportunity to try. Education " +
# "is still the foundation of this opportunity. And the most basic building block that holds that " +
# "foundation together is still reading. At the dawn of the 21st century, in a world where knowledge truly " +
# "is power and literacy is the skill that unlocks the gates of opportunity and success, we all have a " +
# "responsibility as parents and librarians, educators and citizens, to instill in our children a love of " +
# "reading so that we can give them the chance to fulfill their dreams.")

element_dict = dict()
max_count = 0 # stores the maximum occurrence count from all words in the string
for word in input_string.split(' '): # get tokens split by space(' ')
    if not word.isalnum(): # if the word is not completely alnum, we need to convert to alnum form by stripping symbols
        temp = ""
        for letter in word:
            if letter.isalnum():
                temp += letter
        word = temp    
    element_dict[word.lower()] = element_dict.get(word.lower(), 0) + 1 # stores the key as a lowercase string in the map and counts and updates its occurrence for every word observed in the string
    if max_count < element_dict[word.lower()]: # update the max count so that it holds the frequency count of the element which occurs the most in the string.
        max_count = element_dict[word.lower()]

sorted_result = [[] for _ in range(max_count + 1)] # first index always empty. creating a list of list of strings to store the words that occurs in the order of the number of times they appear
for key,value in element_dict.items():
    sorted_result[value].append(key) # inserts it into the position in the array depending on the number of occurrences

for index in reversed(range(max_count+1)): # the last index in the list of list of strings will always be the element with the largest number of occurrences
    if(len(sorted_result[index]) > 0): # as long as there are elements in the list, we display it
        sorted_result[index].sort() # sort the list to display results per index alphabetically
        for word in sorted_result[index]:
            print(word, index)