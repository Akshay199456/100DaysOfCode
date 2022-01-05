def printList(lists, message):
	print(message);
	for i in range(len(lists)):
		print(lists[i], end = ' ');
	print("\n");



lists = ["bye","asta","lavista","hello"];

# Appends element to end of list
lists.append('world');
printList(lists, "\nUsing append: ");


# Used to insert elements
lists.insert(1, "bye");
printList(lists, "\nUsing insert: ");


# Used to delete elements
del lists[0];
printList(lists, "\nUsing delete: ");


# Used to remove element from end of list or from any other position
lists.pop();
printList(lists, "\nUsing pop: ");


# Used to remove an element from the list based on the value;
lists.remove("asta");
printList(lists, "\nUsing remove: ");

"""
# Used to sort elements in ascending order. Can't sort element of different data types.
lists.sort();
printList(lists, "\nAfter assceding sort: ");
# For descending order
lists.sort(reverse=True);
printList(lists, "\nAfter descending sort: ");
"""

# To maintain original order of the list
sortedList = sorted(lists);
printList(sortedList, "\nUsing sorted() function; new list: ");
printList(lists, "\nOriginal list:  ");

