/*
-------------------------Question:
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.  (Recall that a node is a leaf if and only if it has 0 children.)
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node.  It is guaranteed this sum fits into a 32-bit integer.

 

Example 1:

Input: arr = [6,2,4]
Output: 32
Explanation:
There are two possible trees.  The first has non-leaf node sum 36, and the second has non-leaf node sum 32.

    24            24
   /  \          /  \
  12   4        6    8
 /  \               / \
6    2             2   4
 

Constraints:

2 <= arr.length <= 40
1 <= arr[i] <= 15
It is guaranteed that the answer fits into a 32-bit signed integer (ie. it is less than 2^31).
*/

/*
-------------------------My Approaches:

*/

/*
-------------------------Other approaches
1. Recursive approach

In the problem, we are given that the the leaf nodes are given in inorder traversal. If we recollect, inorder is 
[Left, Root, Right]. Since the constraints of the problem mentions that the each node can have 2 or 0 children, we know that
the root can't hold a leaf node. As a result, the nodes in our inorder traversal are manages in a left and right order. We
need to find the right combinations of the left and right nodes in order to minimize the cost of building th eleaf ndoes.
As a result, as we apply this technique to every non-leaf node, this problem has a recrusive structure to it where we are 
optimizing the cost of the non-leaf nodes.

Time complexity: O(2^n)
Space complexity: O(n)


2. Top-down approach

If we notice the previous approach, there are several calculations that we are repeatedly doing. For example, if we find
the min combination for [2|3], we wll not need to repeat that calculaiton again as we have already performed it. As a result,
we can store our results as we are going along and if we already have the value preset  in the dpTable, we return it insteafd
of performing the clculatuions

Time complexity: O(n^3)
Space complexity: O(n^2)


3. Bottom-up approach

In the previous approach, if we notice the base conditions, they are of size 1 and 2. If we are at size 1, then we are at a
leaf, which means the left and right for it are 0. If we are of size 2, then we are at a level 1 above the root. in that
case pur result comes directly from dividding the nodes equally between the left and the right. Every other level has a 
different set of combinations that can exist so we will need to perform calculations accordingly as we mov eup the tree from
the base conditions.

Time complexity: O(n^3)
Space complexity: O(n^2)
*/

// Other Approaches(1)
class Solution {
public:
    vector<int> arrCopy;
    
    void getCopyArray(vector<int> arr){
        for(int i = 0; i < arr.size(); i++)
            arrCopy.push_back(arr[i]);
    }
    
    void printArray(vector<int> arr){
        for(int i = 0; i < arr.size(); i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    
    int getValue(int beg, int end){
        if(beg == end)
            return 0;
        else{
            int result = INT_MAX;
            for(int i = beg; i < end; i++){
                // cout<<"i: "<<i<<" beg: "<<beg<<" end: "<<end<<endl;
                int left = getValue(beg, i);
                int right = getValue(i+1, end);
                
                int maxLeft = 0, maxRight = 0;
                for(int k = beg; k <=i; k++)
                    maxLeft = max(maxLeft, arrCopy[k]);
                for(int k = i+1; k<=end; k++)
                    maxRight = max(maxRight, arrCopy[k]);
                
                int currNode = maxLeft * maxRight;
                result = min(result, currNode + left + right);
            }
            return result;
        }
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        getCopyArray(arr);
        return getValue(0, arr.size()-1);
    }
};


// Other Approaches(2)
class Solution {
public:
    vector<int> arrCopy;
    vector<vector<int>> dpTable;
    
    void constructDpTable(int size){
        for(int i = 0; i < size; i++){
            vector<int> list;
            for(int j=0; j<size; j++)
                list.push_back(0);
            dpTable.push_back(list);
        }
    }
    
    void getCopyArray(vector<int> arr){
        for(int i = 0; i < arr.size(); i++)
            arrCopy.push_back(arr[i]);
    }
    
    int getValue(int beg, int end){
        if(beg == end)
            return 0;
        else if(dpTable[beg][end] != 0)
            return dpTable[beg][end];
        else{
            int result = INT_MAX;
            for(int i = beg; i < end; i++){
                // cout<<"i: "<<i<<" beg: "<<beg<<" end: "<<end<<endl;
                int left = getValue(beg, i);
                int right = getValue(i+1, end);
                
                int maxLeft = 0, maxRight = 0;
                for(int k = beg; k <=i; k++)
                    maxLeft = max(maxLeft, arrCopy[k]);
                for(int k = i+1; k<=end; k++)
                    maxRight = max(maxRight, arrCopy[k]);
                
                int currNode = maxLeft * maxRight;
                result = min(result, currNode + left + right);
            }
            dpTable[beg][end] = result;
            return result;
        }
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        getCopyArray(arr);
        constructDpTable(arr.size());
        return getValue(0, arr.size()-1);
    }
};


// Other Approaches(3)
class Solution {
public:
    vector<vector<int>> dpTable;
    
    void constructDpTable(int size){
        for(int i = 0; i < size; i++){
            vector<int> list;
            for(int j=0; j<size; j++)
                list.push_back(0);
            dpTable.push_back(list);
        }
    }
    
    int getValue(int beg, int end, vector<int> arr){
        for(int i = arr.size()-1; i>=0; i--){
            for(int j = i+1; j < arr.size(); j++){
                int result = INT_MAX;
                for(int k = i; k < j; k++){
                    int minSumFromLeft = dpTable[i][k];
                    int minSumFromRight = dpTable[k+1][j];
                    
                    int maxLeft = 0, maxRight = 0;
                    for(int index=i; index<=k; index++)
                        maxLeft = max(maxLeft, arr[index]);
                    
                    for(int index=k+1; index<=j; index++)
                        maxRight = max(maxRight, arr[index]);
                    
                    result = min(result,minSumFromLeft + minSumFromRight + maxLeft * maxRight);
                }
                dpTable[i][j] = result;
            }
        }
        return dpTable[0][arr.size()-1];
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        constructDpTable(arr.size());
        return getValue(0, arr.size()-1, arr);
    }
};
