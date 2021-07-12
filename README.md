# #100DaysOfCode

Hello everyone! Welcome to my journey of 100 days of coding. Being an avid Twitter user and following several awesome engineers and developers on the platform, I have been inspired by them to follow my own journey into coding for 100 days and eventually making it a habit where I would love to code/work on projects everyday. For those who don't know me, my background section should give you a quick glimpse into me.

## Background

I have a Bachelors in Computer Engineering from the University of Houston. During my undergrad, I got to work on a whole lot of projects related mostly on hardware but I got to work on a few software projects as well. During this time, I discovered that I was way more passionate about coding related projects that were handed over to me and as a result, as soon as I completed my undergrad, I enrolled in a software engineering bootcamp at General Assembly(GA) in San Francisco.

During my time at GA, I got the opportunity to work with several peers on coding projects with respect to full stack web development using technologies focused on the MERN stack. Check out my GitHub profile if you want to take a look into the projects I built during this time.

I am currently pursuing a Masters in Software Engineering at the University of Houston to integrate my background in software engineering with industry specific knowledge related to the field.

## What This 100DaysOfCode Will Cover

During the 100 days of code, I will aim to cover projects from different fields of software engineering which will include but is not limited to:

- Frontend development using HTML, CSS, Javascript, Python and other frontend development frameworks and libraries.
- Backend development using C++, Java etc.
- Machine Learning.
- Testing Frameworks. 
- Full Stack Applications.
- App development.
- Data Structure and Algorithm Problem Solving.


The goal of this journey for me is to make myslef into a better software engineer by exposing to different technologies/frameworks, building projects and learning the fundamental skills. If you would like to collab with me or provide any feedback on how to make this journey better, please reach out to me at my different profiles:

1. [LinkedIn](https://www.linkedin.com/in/akshaymysore/)
2. [Twitter](https://twitter.com/MysoreAkshay)
3. [Gmail](mailto:akshay.kum94@gmail.com)

------------------------------------------
## Problem Solving Patterns


# Problem Solving:

This category will provide a general guidance to solve a problem given any category of question. This could be general tips as well as specific tips to certain categories. As we get more data, we will find better patterns and will continuosly
update it.


## General problem solving:

1. List out all the important data that is given in the problem in the form of multiline comments. This is helpful as it is reinforces the main concepts of the problem. This even includes the given and todo sections
2. Come up with a bunch of test cases of different varieties. The more the test cases, the better you will be able to understand the problem from different scenarios.
3. Whenever you see a problem that's hard, think how you can do this in th emost naive of ways. Always start with the brute force solution. Stop trying to find an improved/optimized solution from the first go itself. Once you do a brute force solution, you get a better understanding of the problem and find out what the bottlenecks are. Once you are able to find the bottlenecks, you can then apply the optimization techniques that you learnt from CodePath across each of the categories to resolve the bottlnecks. This is a much better and higher probabilty success solution as compared to trying to find an optimized algorithm in the first go.
4. There are several advantages of writing comments for you code as you go along. Writing comments allows you to to see the bigger picture and plan out your apporach before you jump in to code. It also helps you isolate issues
quicke when you try debuggin with print stateements.


### Bit Manipulation

1. Bit Manipulation and using bit vector can be really useful in optimizing problems further on already optimizaed solutions. It will optimize space constraints further while it doesn't add any optimization to time.
2. Difference betwen arithemetic and logical right shift:
    1. Notes:
        - There are two types of right shift operators. The arithmetic right shift essentially divides by two. The logical right shift does what we would visually see as shifting the bits. This is best seen on a negative number
        - In a logical right shift, we shift the bits and put a 0 in the most significant bit. It is indicated with a >>> operator.
        - In an arithmetic right shift, we shift values to the right but fill in the new bits with the value of the sign bit. This has the effect of (roughly) dividing by two. It is indicated by a > > operator.
    2. Logical vs Arithemetic Shift
        1. Logical Shift:
            - A Left Logical Shift of one position moves each bit to the left by one. The vacant least significant bit (LSB) is filled with zero and the most significant bit (MSB) is discarded.
            - A Right Logical Shift of one position moves each bit to the right by one. The least significant bit is discarded and the vacant MSB is filled with zero.
        2. Arithemetic Shift:
            - A Left Arithmetic Shift of one position moves each bit to the left by one. The vacant least significant bit (LSB) is filled with zero and the most significant bit (MSB) is discarded. It is identical to Left Logical Shift
            - A Right Arithmetic Shift of one position moves each bit to the right by one. The least significant bit is discarded and the vacant MSB is filled with the value of the previous (now shifted one position to the right) MSB.
        3. Important links for more info:
            1. CTCI pg 113-114 [http://pdfviewer.softgateon.net/?state=%7B%22ids%22:%5B%221p5Nrl5_Ugu5HOKejMSKq1kgYO9tkvGkz%22%5D,%22action%22:%22open%22,%22userId%22:%22102159110389363585919%22%7D]
            2. Differences [https://open4tech.com/logical-vs-arithmetic-shift/]   
3. Common Bit tasks: Getting and Setting
    1. Get Bit:
        - This method shifts lover by i bits, creating a value that looks like eeElleeee. By performing an AND with num, we clear all bits other than the bit at bit i. Finally, we compare that to e. If that new value is not zero, then bit i  must have a 1. Otherwise, bit i is a O.  
        - boolean getBit(int num, int i) { return «num & (1 « i» != 0); }
    2. Set Bit:
        - SetBi t  shifts lover by i bits, creating a value like eeeleeee. By performing an OR with num, only the value at bit i will change. All other bits of the mask are zero and will not affect num. 
        - int setBit(int num, int i) { return num I (1 « i); }
    3. Clear Bit
        - This method o perates in almostthe reverse of setBi t . First, we create a number like 11101111 by creating the reverse of it (00010000) and negating it. Then, we perform an AND with num. This will clear the ith bit and leave the remainder unchanged. 
            - int clearBit(int num, int i) { int mask = ~(1 « i); return num & mask; } 
        - To clear all bits from the most significant bit through i  (inclusive), we create a mask with a 1 at the ith bit (1 < < i). Then, we subtract 1 from it, giving us a sequence of 0s followed by i 1s. We then AND our number with this mask to leave just the last i  bits. 
            - int clearBitsMSBthroughI(int num, int i) {int mask = (1 « i) -1; return num & mask; } 
        - To clear all bits from i  through 0 (inclusive), we take a sequence of all1s (which is -1) and shift it left by i + 1 bits. This gives us a sequence of 1 s (in the most significant bits) followed by i 0 bits. 
            - int clearBitslthrough0(int num, int i) { int mask = (-1 « (i + 1»; 3 return num & mask;}
    4. Update Bit
        - To set the ith bit to a value v, we first clear the bit at position i  by using a mask that looks like 11101111. Then, we shift the intended value, v, left by i  bits. This will create a number with bit i  equal to v  and all other bits equal to 0. Finally, we OR these two numbers, updating the ith bit if v is 1 and leaving it as 0 otherwise. 
        - int updateBit(int num, int i, boolean bitlsl) { int value = bitlsl ? 1  : 0; int mask = ~(1 « i); return (num & mask) I (value « i);}
    5. Clear single least signal bit
        - n & (n-1)
    6. Swapping numbers:
        - If numbers are x and y
        - x = x^y, y = y^x, x= x^y
        - At the end of the operations, x and y are swapped. The first operation x = x^y generates the difference in bits between the two numbers which is then used to swap the numbers accordingly.   
4. Two's complement and negative numbers:
    - Computers typically store integers in two's complement representation. A positive number is represented as itself while a negative number is represented as the two's complement of its absolute value (with a 1 in its sign bit to indicate that a negative value). The two's complement of an N-bit number (where N is the number of bits used for the number, excluding the sign bit) is the complement of the number with respect to 2N
    - Let's look at the 4-bit integer - 3 as an example. If it's a 4-bit number, we have one bit for the sign and three bits for the value. We want the complement with respect to 23, which is 8. The complement of 3 (the abso-lute value of -3) with respect to 8 is 5. 5 in binary is 1131. Therefore, -3 in binary as a 4-bit number is 1101, with the first bit being the sign bit. 
    - In other words, the binary representation of -K (negative K) as a N-bit number is concat (1 J 2N•1 -K).
    - Another way to look at this is that we invert the bits in the positive representation and then add 1 . 3 is 1311 in binary. Flip the bits to get lee, add 1 to get 1131, then prepend the sign bit (1) to get 11131.


### Sorting

1. If a question asks you something related to sorting (for example, in finding th ekth greaters, kth smallest value); using the sorting techniques can be highly valuable here. The techniques we could use are:
    1. Sorting
    2. Heap


### Binary Search

1. Efficient method for locating element in sorted list efficiently.


### Linked Lists:

1. Tactics to solve these kind of problems occur in 3 ways:
    1. Take multiple passes through Linked List
        - get length
        - save other information about contents
    2. Two pointers (Runner technique)
        - 'race car' strategy with one slow pointer and one fast pointer
    3. Dummy node
        - helpful for preventing errors when returning 'head', 'tail' [mergin lists, deleting from lists]
2. In some problems, we can more efficiently solve the problem by modifying the given linked list in place instead of creatiing a copy of the list and making changes to it.This way we save time in terms of space complexity. Check pb 138 leetcode for more information.


### Strings and Arrays:

1. Tactics to solve these kind of problems include:
    1. Two pointer technique
        - Useful for when you are dealing with sorted arrays and need to find set of elements that fullfill some constraint
        - Different approaches:
            - One pointer at beginning and one pointer at end, either moving towards the middle or starting at middle and moving towards the end
            - Both popinters at beginning
            - Both pointers at end
            - One slow and one fast
    2. Sliding window technique
        - This technqie is very useful to calculate something among all subarrays of given size.
        - Anytime there's substring/subarray involved in a problem, think of sliding window
        - Steps of apporach:
            1. Two pointers starting from the beginning, say leftPtr and rightPtr.
            2. Increment rightPtr until it 'controls' the array (or string) [or condition is satisfied]
            3. Increment leftPtr unti it 'doesn't control' the array (or string) [or condition not satisifed]
            4. Keep track of the 'best' ound result.
        - Two types of sliding window:
            1. Fixed window length k
                - Length of window is fixed and it asks you to find something in the window
            2. Varying window:
                - window size is not fixed
    3. Traversing through the array multiple times to collect information
        1. In this approach, we can move through the array multiple times in order to gather some informationa bout the problem. This can often take the position where you go through the array from one direction to the other to pick up a certain information and store it and then go from the other direction to the one direction and update that information again. Check out pb 238 leetcode for more information on this.
            - In this kind of problem for the brute force appraoch, for each index, we usually do some kind of work on the left and some kjind of work on thr right. By doing that work beforehand, we save time.
2. 5 common types of string questions:
    1. Generate all permutations of given string
    2. Substrings of given string.
    3. Reversing a given string.
    4. Substitution/replacing specific letters
    5. String compression.
3. 2D arrays:
    - Matrix problems are often graph problems in disguise.
    - If problems involve notion of entities and some type of relationship between those entities, consider graph techniques.
    - Two most common and important traversals:
        1. Breadth first traversal (BFS)
            - using queue
            - better in finding shortes path
        2. Depth first traversal (DFS)
            - using stack
            - better in problems that deal with strcture of the problem as opposed to finding shortest path.
    - When dealing with 2D arrays, after solving the problem through brute force, by using an additional matrix, you want to check if you can optimize it by doing the operations in place instead of using additional space for another
    space for another matrix/array. This usually involves modifying the array as you are goin along.
4. Array and string questions tend to be interchangeable. The same strategies you apply to strings can be applied to arrays.
5. A common approach in string manipulation problems is to edit the string starting from the end and working backwards. This is useful because we have an extra buffer at the end, which allows us to change characters without worrying about what we're overwriting.


### Stacks and Queues

1. Summary: 
    1. Stack - Data structure that stores items in LIFO order
    2. Queue - Data structure that stores items in FIFO
2. Common problems for stacks:
    1. Parsing questions
        - Evaluating arithemetic expressions
        - Matching brackets
    2. Implementing recurisve solutions iteratively
3. We use stacks to reverse the order of elements while we use queues to maintain order of elements. Stacks are very useful for its backtracking features while queues are useful when the ordering of the data matters as it rpeserves that ordering.


### Heaps

1. Heaps are special tree based data strctures that satisfy 2 properties:
    1. Nodes ordered in specific way
        - In min heaps, root node contains smallest elements and all the nodes in the heap contain elements that are less than or equal to their child nodes.
        - In max heaps, root node contains largest element and all nodes in heap contain elements that are greater or equal to their child nodes.
    2. It's a complete binary tree. Binary tree's nodes will have at most two children: a left child and a right child. Since it's a complete binary tree, it fills each level entirely except the last level.
2. Can be easily built using an array.
3. Given an array:
    1. Parent: (currrentIndex - 1)/2
    2. LEft child: currentIndex * 2 + 1
    3. Right child: currentIndex * 2 + 2
4. Creating heap directly froma  list is O(n) as opposed to adding each single element to heap which results in total O(nlogn) complexity. As a result, we can potentially optimize a solution by building heap from list instead of running insertion n times to create heap.
5. Situations where heaps are most useful: 
    1. Heaps are expecially useful when getting largest or smallest elements and in situations where you don't care about fast lookup, delete or search
    2. Especially useful for questions that involve getting x-largest or s-mallest elements of some data set.
6. Definition of few terms:
    1. Min heap
        -   Max-heaps are essentially equivalent, but the elements are in descending order rather than ascending order. A min-heap is a complete binary tree (that is, totally filled other than the rightmost elements on the last level) where each node is smaller than its children. The root, therefore, is the minimum element in the tree.


### Trie

1. Based on the prefix of a string. Used in the retrieval of data. It's a special data structure used to store strings that can be visualized like a graph.
2. Tries generally used on a group of strings rather than a single string. When given multiple strings, we can solve a variety of problems abased on them.
3. Why trie:
    1. Can insert and find strings in O(l) time where l represents the length of a single word.
    2. Can easily print all words in alphabetic order
    3. Can efficeintly do prefix search (or auto-complete)
    4. Used for prefix search, alphabetical order printing and nearest neighbor search.
4. Very commonly, a trie is used to store the entire (English) language for quick prefix lookups. While a hash table can quickly look up whether a string is a valid word, it cannot tell us if a string is a prefix of any valid words. A trie can do this very quickly.
5. Many problems involving lists of valid words leverage a trie as an optimization. In situations when we search through the tree on related prefixes repeatedly (e.g., looking up M, then MA, then MAN, then MANY), we might pass around a reference to the current node in the tree. This wi" allow us to just check if Y is a child of MAN, rather than starting from the root each time


### Binary Trees

1. 2 major form of traversals spread across 2 different categories:
    1. Depth first
        - Start at root and explore branch till we hit left node before backtracking and going another branch
        1. Preorder
            - Root > left subtree > right subtree
        2. Postorder   
            - Left subtree > right subtree > root
        3. Inorder
            - Left subtree > root > right subtree
    2. Breadth first (level order)
        - Visit nodes at each depth
        - Once we have visited nodes in one depth level, we move on to next level.
        - Use queue to keep track of children.
2. In different situations, different traversals are helpful
    - If changin a tree, preorder is useful as we must copy root before copying left and right subtrees
    - If deleting a tree, we would use postorder as we would want to delete child nodes first before deleting root.
    - If flattening a tree, inorder is useful to get sorted list representation.
3. Patterns for tree problems:
    1. Traversal tree
    2. Serialize/ deserialize
        - Convert into sorted list.
        - Use sorted list to construct BST
    3. Given any two, obtain the third one:
        - given preorder and postorder, find inorder
        - given preorder and inorder, find postorder
        - given posorder ad inorder, find preorder.
4. Problems can be solved in 1 of 2 ways:
    1. Iterative
        - Usually involves using stack/queue
        - Couple of important steps to convert recursive to iterative approach
            1. Recall recurisve way to solve problem.
            2. Working from recursive soluton, we know what the desired output should be
            3. Using desired output, we then tried to create a new approach that woukd vive us the same outcome.
    2. Recursive
        - uses memory in stack calls
5. Can build trees from the top-down as well as bottom-up.
6. Common techniques to efficiently improve bruteforce noticed in binary tree problems:
    1. Using min and max condition or similar approaches to insert nodes going along. We keep track of something on the left as well as something on the right and make a decision based on it.
    2. Using info from one array of traversal to more acrross another array of traversal
    3. Creating/travering a tree from bottom-up instead of top-down based on a set of condition. Information/state is then sent upwards
        - For top-down, information/state is sent downwards.
7. Trick with most binary search tree problems is that there is a straightforward approach that will get you O(n) running time, but there is almost always an optimization you can make to get O(log n) running time.
8. Few defintions of terms:
    1. Balanced vs unbalanced
        - One way to think about it is that a "balanced" tree really means something more like "not terribly imbal-anced:' It's balanced enough to ensure O( log n) times for insert and find, but it's not necessarily as balanced as it could be.
    2. Complete binary trees
        - A complete binary tree is a binary tree in which every level of the tree is fully filled, except for perhaps the last level. To the extent that the last level is filled, it is filled left to right.
    3. Full binary trees
        - A full binary tree is a binary tree in which every node has either zero or two children. That is, no nodes have only one child. 
    4. Perfect binary trees
        - A full binary tree is a binary tree in which every node has either zero or two children. That is, no nodes have only one child. 
        - Note that perfect trees are rare in interviews and in real life, as a perfect tree must have exactly 2k -1 nodes (where k is the number of levels). In an interview, do not assume a binary tree is perfect.
    5. Height and depth of a tree
        - For each node in a tree, we can define two features: height and depth. A node’s height is the number of edges to its most distant leaf node. On the other hand, a node’s depth is the number of edges back up to the root. So, the root always has a depth of 0 while leaf nodes always have a height of 0.


### Graphs

1. Graphs best utilized for problems in which there are binary relationships between objects. Once problem can be represented as graph, problem can generally be solved based off of one of the key graph algorithms.
2. 3 ways of graph representaitons:
    1. Adjacency lists
        - Each node stores a list of its adjacent vertices
    2. Edge sets/lists
        - Each set represents a graph as a collection of all its edges.
        - Each item in the set represents an edge between two vertices of teh graph.
    3. Adjacency matrix
        - Represents a graph with n nodes as an a n by n boolean matrix in which matrix[u][v] is set to trie if an edge exists from node u to node v.
3. Two graph traversal techniques:
    1. DFS
        - better for analyzing structure of graphs
        - eg: looking for cycle, path exists
    2. BFS
        - better for optimiation
        - eg: shortes path algroithms
4. 3 main categories of problems that can be encountered:
    1. BFS
    2. DFS
    3. Topological sort
        - prodces a linear ordering of nodes in a directed graph such that direction of edges is respected.
        - an ordering of nodes for a directed acyclic graph (DAG) such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering
        - simply a modification of DFS
            - involves DFS on an entrie graph and adding each node to the global ordering of nodes only after all of the node's children's are visited.
            - this ensures that parent nodes will be ordered before theire child nodes honoring the forward direction of edges in the ordering.
5. A graph is simply a collection of nodes with edges between (some of) them:
    - Graphs can be either directed (like the following graph) or undirected. While directed edges are like a one-way street, undirected edges are like a two-way street.
    - The graph might consist of multiple isolated subgraphs.lf there is a path between every pair of vertices, it is called a "connected graph:'
    - The graph can also have cycles (  or not). An "acyclic graph" is one without cycles
6. You don't necessarily need any additional classes to represent a graph. An array (or a hash table) of lists (arrays, arraylists, linked lists, etc.) can store the adjacency list. 
7. In some scenarios, bidirectional search can be useful:
    - Bidirectional search is used to find the shortest path between a source and destination node. It operates by essentially running two simultaneous breadth-first searches, one from each node. When their searches collide, we have found a path.
    - To see why this is faster, consider a graph where every node has at most k adjacent nodes and the shortest path from node 5 to node t has length d. 
        - In traditional breadth-first search, we would search up to k nodes in the first "level" of the search. In the second level, we would search up to k nodes for each of those first k nodes, so k2 nodes total (thus far). We would do this d times, so that's a (kd) nodes. 
        - In bidirectional search, we have two searches that collide after approximately ~ levels (the midpoint of the path). The search from 5 visits approximately kd/2, as does the search from t. That's approximately 2 kd/2, or a (kd12), nodes total. 
    - This might seem like a minor difference, but it's not. It's huge. Recall that (k^(d/2)) * (k^(d/2)) = k^d
    - The bidirec-tional search is actually faster by a factor of kdl2. Put another way: if our system could only support searching "friend of friend" paths in breadth-first search, it could now likely support "friend of friend of friend of friend" paths. We can support paths that are twice as long.


### Dynamic Programming:

1. Problems that seem to deal with maximize/minimize/no of ways are good candidates for DP.
    - Additional condition to be satisifed is that there should be some form of recursive structure to the problem.
    - Goal of DP table/ dp list is to give a recurisve equation that you can use to solve the problem
2. Problems that have repeated work continuosly done leading to repeated recurison are good candidates for dp by using a dp list/matrix.
3. Problems most often takes the form:
    - Given a set of rukesm find the optimal cost of some objective governed by thosew rules.
4. Observations:
    - Call graph is great way to get idea of computational compleixty of recursive algorithm and wasted computations.
    - Once you find a recusive solution to your problem that exhibits the computational explosion because of wasteful repetition, you can improve performance by saving computation and adding storage.
5. Two main patterns to DP design
    1. Top-down or recursion_memoization
    2. bottom-up or DP Table design
        - DAG is useful as it shows you dependency relationship which you can extend to the base case
        - DP Table is really helful as a visualization technique for designing these kind os solutions in a multi-prefex/multi-suffix or subsequence problem
        - When you have factors on which your problem depends, DP table is a good approach to solve the problem.
6. 3 main variants of DP problems:
    1. Single suffix/prefix:
        - where subproblem solves for some position i and then recurses or iterates on the rest defined by either f[:,i-1] or f[i+1,:].
        - Often O(n)
    2. Subsequence:
        - will solve for both ends of an interval in your sequence and be left to solve for f[i,j]
        - Ofen O[n^2]
    3. Double suffix/prefix:
        - more rate, but sometimes you will solve for i and j separately and be left with work in 2 linear sequqnces f[:,i-1] and g[:,j-1]
        - Likely O[n^2]
7. Some common patterns in DP
    1. Fibonacci
    2. Kanpsack
        - Have different types of items. Each one has a weight.
        - Maximize/minimize result
        - Can only take each item once.
    3. Unbounded knapsack
        - Same as above but can take items as many times
    4. Palindromic sequences
    5. Common substrings
8. How to approach these problems:
    1. Recursive solutions, by definition, are built off of solutions to subproblems. Many times, this will mean simply to compute f (n) by adding something, removing something, or otherwise changing the solution for f (n -1). In other cases, you might solve the problem for the first half of the data set, then the second half, and then merge those results. There are many ways you might divide a problem into subproblems. Three of the most common approaches to develop an algorithm are bottom-up, top-down, and half-and-half
    2. Bottom-up approach:
        - The bottom-up approach is often the most intuitive. We start with knowing how to solve the problem for a simple case, like a list with only one element. Then we figure out how to solve the problem for two elements, then for three elements, and so on. The key here is to think about how you can build the solution for one case off of the previous case (or multiple previous cases).
    3. Top down approach:
        - The top-down approach can be more complex since it's less concrete. But sometimes, it's the best way to think about the problem. In these problems, we think about how we can divide the problem for case N into subproblems. Be careful of overlap between the cases.
    4. Half and Half approach:
        - In addition to top-down and bottom-up approaches, it's often effective to divide the data set in half. For example, binary search works with a "half-and-half" approach. When we look for an element in a sorted array, we first figure out which half of the array contains the value. Then we recurse and search for it in that half. Merge sort is also a "half-and-half" approach. We sort each half of the array and then merge together the sorted halves.
9. Tips:
    - Although people make a big deal about how scary dynamic programming problems are, there's really no need to be afraid of them. I n fact, once you get the hang of them, these can actually be very easy problems. Dynamic programming is mostly just a matter of taking a recursive algorithm and finding the overlapping subproblems (that is, the repeated calls). You then cache those results for future recursive calls. Alternatively, you can study the pattern of the recursive calls and implement something iterative. You still "cache" previous work.
    - Remember this for future problems. Drawing the recursive calls as a tree is a great way to figure out the runtime of a recursive algorithm. 
10. Whatever is the goal for the problem is what you should be checking in the per unit/ per cell basis of the dp table/ dp list. Doing that, we then solve that for each of the sub-problems thereby giving us the information to extract the same for the whole of the problem.



### Greedy Algorithms

1. A greedy approach means that at every step, we take the best(local optimal) option for us with current circumstances
2. How to tell if greedy is right approach:
    1. Try solving through brute force first or first solution that comes to head.
    2. Once you've solved the solution, try to go over your steps and think of ways you could have the done the question more efficiently with a huerisic/comparator.
    3. Can you come up with a conunterexample that doesn't give you the optimal solution to your greedy solution.
3. Common types of greedy problems:
    1. Minimum no of jumps
    2. Non overlapping intervals (Activity selection)
        - Given a list of actitivites denoted by theire start and end times, you want to maximize the no of activites you can do.
    3. Job sequencing/ task scheduler
        - given array of meeting time intervals consisting of start and end times, find minimum no of conference rooms required.
        - uses a min heap to store time specifically either end-time or beingnin time.
    4. Huffman encoding.
        - idea is to assign variable length codes to input characters where lengths of assigned codes are based on frequencies of corresponding characters. The most frequence character gets the smallest code and the least frequenct character gets the largest code.
        - 2 step process:
            1. build huffman tree from input characters:
                - uses min heap to construct huffman tree
                - extract 2 nodes with minimum frequency from mon heap. Create new internal node with frequency equal to sum of 2 nodes frequencoes. Make first extracted node as its left child and other extracted node as its right child. Add this node to min heap.R Repeat this till heap contians only one node. Reamining node is root node and tree is complete.
            2. traverse huffman tree and assign codes to characters
                - staring from root, traverse tree.
                - while moving to left child, write 0 to array. while moving to right child, write 1 to array.
                - pdrint the array when a leaf node is encountrered.
4. One of the most common approaches for approaching greedy problems is that you have to find some way to manipulat eht input to approach it with a greedy algorithm. Manu times you want to find some way to sort the input in a certain way to allow you to greeduly take inputs as you are iterating throuigh the list.
    - How do we sort our inputs:
        - Sort by start
        - Sort by end
        - Sort by duration.
4. Common greedy approaches:
    1. Sort eh inputs
    2. Use a priority queue
    3. Come up with a comparator that allows you to always choose the best option.


### Backtracking

1. Similar to DP in that it solves a problem by efficiently performing an exhustive search over entries et of possible options. Different in that it structures thse search to be able to efficiently eliminate large subsets of solutions that are no longer possible. Similar to DP in that we are exhuastievely searching a solution space guaranteeing that will touch all solutions that matter. Also similar to DP in that the difference between a highly performant algorithms and not is often how you strcutre your search. In case of backtracking , best solutions often model problem in some way that allows them to quickly prune state prefixes that can't lead to solutions.
2. Unlike DP, backracking not typically looking for one optimal solution but is instead looking for all that satisfy some criteria. So, strcuture of algorithm is much less about being efficient at throwing previous information that you don't need because it doesn;t lead you to optimal soliton and more about learning what oarts of the space you don't need to explore as you are collecting all solutions that qualify.
3. Breaks down a problem into solving for 4 components to the algorithm:
    1. GetCandidates - Given a current sub-solution state, what are all the candodates I can choose to move to a new possible sub-solution state.
    2. Search - Decide if all possible solutions derived from the current sub-solution state will be invalid.
    3. Backtrack - Efficiently backtrack from any current sub-solution state to a previous state.
    4. IsSolution - Is a particular sub-solution actually a valid solution
4. In backtracking, we are exhaustively searching through a solution space by applying local transformations and collecting solutions we find as we go.