/*
-------------------------Question:

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

*/

/*
-------------------------My Approaches:

1. Divide and Conquer(Recursive approach)

This approach uses the divide and conquer approach to keep adding elements to the tree after
getting the center of each interval of the array. The best way to create a balanced tree is to 
divide the elements into two halfs which are of almost the same length in height. While we keep
adding the middle element, this continues for each interval of the array till all the elements 
are added to the tree.


Time complexity: O(n)
Space complexity: O(h) -> O(n)


2. Iterative approach[Worse overall when efficiently coded]

While I just wrote the iterative approach here to make sure I could implement the above approach
iteratively, the code provided here is not efficient.

[Current]
Time comlpexity: O(2n) -> O(n)
Space complexity: O(2n) + O(2n) -> O(n)


When this approach is coded efficiently, it will take the below conditions:

Time complexity: O(n) [All the nodes will be entered into the tree]
Space complexity: O(n) [The limitsQueue will only contain the limits of the element that will
contain elements that will be inserted]
*/

// My Approaches(1)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void createBalancedBST(TreeNode * & root, int beg, int end, vector<int> nums){
        if(beg > end)
            return;
        else{
            int mid = (beg + end)/2;
            TreeNode * object = new TreeNode(nums[mid]);
            
            if(!root)
                root = object;
            else{
                if(object->val > root->val)
                    root->right = object;
                else
                    root->left = object;
            }
            createBalancedBST(object, beg, mid-1, nums);
            createBalancedBST(object, mid+1, end, nums);
        }
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode * root = NULL;
        if(nums.size() != 0)
            createBalancedBST(root, 0, nums.size() - 1, nums);
        return root;
    }
};


// My approaches(2)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void createBST(vector<int> nums, TreeNode *& root, queue<TreeNode *> nodesQueue, queue<pair<int, int>> limitsQueue){
        while(!nodesQueue.empty()){
            TreeNode * element = nodesQueue.front();
            pair<int,int> limits = limitsQueue.front();  
            if(limits.first <= limits.second){
                int mid = (limits.first + limits.second) / 2 ;
                TreeNode * object = new TreeNode(nums[mid]);
                
                if(object->val > element->val)
                    element->right = object;
                else
                    element->left = object;
                
                nodesQueue.push(object);
                nodesQueue.push(object);
                limitsQueue.push(make_pair(limits.first, mid - 1));
                limitsQueue.push(make_pair(mid + 1, limits.second));
            }
            nodesQueue.pop();
            limitsQueue.pop();
        }
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode * root = NULL;
        if(nums.size() != 0){  
            queue<TreeNode *> nodesQueue;
            queue<pair<int,int>> limitsQueue;
            int mid = (nums.size() - 1) / 2;
            TreeNode * object = new TreeNode(nums[mid]);
            for(int i = 0; i < 2; i++)
                nodesQueue.push(object);
            limitsQueue.push(make_pair(0, mid - 1));
            limitsQueue.push(make_pair(mid + 1, nums.size() - 1));

            root = object;      
            createBST(nums, root, nodesQueue, limitsQueue);
        }
        
        return root;
            
        
    }
};