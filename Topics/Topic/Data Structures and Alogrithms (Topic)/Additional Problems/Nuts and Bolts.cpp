/*
-------------------------Question:

Given a set of n nuts of different sizes and n bolts of different sizes. There is a one-one mapping between nuts and bolts. Match nuts and bolts efficiently. 
Constraint: Comparison of a nut to another nut or a bolt to another bolt is not allowed. It means nut can only be compared with bolt and bolt can only be compared with nut to see which one is bigger/smaller.
Other way of asking this problem is, given a box with locks and keys where one lock can be opened by one key in the box. We need to match the pair.
*/

/*
-------------------------My Approaches:
1. Comparing each nuts against bolt and sorting it into its place

Since we are not allowed to compare nuts againnst each other and bolts against each other, we can compare each nut with
all the bolts and put the bolt into its place corresponding to the nut when we find it in bolt. We do this for all
nuts.

Time complexity: O(n^2)
Space complexity: O(1)
*/

/*
-------------------------Other approaches
1. Using quicksort appraoch

We can use the quicksort approach to mitigate the bottleneck we encountered in previous step. If we noticed in the approach,
we were comparing the nut against all bolts to find the place for the bolt to be inserted. We can do better here by using
the quicksort approach by sorting it progressively instead. We can sort the nuts based on the end index of bolts and
use that info to sort the same nut into its place in bolt. At this stage, both the nut and bolt are sorted into their
own positions with each having the same number of elements on left and right due to 1-1 mapping. We then continue to sort
the left and right halves as well.

Time complexity: O(nlogn)
Space complexity: O(1)
*/

