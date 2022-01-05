/*
-------------------------Question:

Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.
*/

/*
*/

/*
-------------------------My Approaches:

1. DFS

The first approach uses DFS to calculate the average of the elements in the binary tree.

Time complexity: O(n)
Space complexity: O(n)

Even though this appraoch uses O(n) space, you can use a pair instead of storing the array in the
hastable. This way the space will only depend on the number of elements in the map which is of 
height O(h) giving us:

Time complexity: O(n)
Space comeplxity: O(h)




2. BFS

The second approach uses BFS instead. As a reuslt, we use a queue to store the results.

Time complexity: O(n)
Spce complexity: O(n)
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
class Solution {
public:    
    void fillMap(unordered_map<int, vector<int>> & elements, TreeNode * root, int level){
        if(root){
            auto it = elements.find(level);
            if(it == elements.end()){
                vector<int> list;
                list.push_back(root->val);
                elements[level] = list;
            }
            else
                elements[it->first].push_back(root->val);
            
            fillMap(elements, root->left, level+1);
            fillMap(elements, root->right, level+1);
        }
    }
    
    vector<double> calculateAverage(unordered_map<int, vector<int>> elements){
        int size = elements.size();
        vector<double> result(size, 0);
        for( auto it = elements.begin(); it!=elements.end(); it++){
            double sum = 0;
            for(int i = 0; i < (it->second).size(); i++)
                sum += (it->second)[i]; 
            result[it->first] = sum / (it->second).size();;
        }
        return result;
    }
    
    void printMap(unordered_map<int, vector<int>> elements){
        for( auto it = elements.begin(); it!=elements.end(); it++){
            cout<<"Current level: "<<it->first;
            cout<<" Elements: ";
            for(int i = 0; i < (it->second).size(); i++)
                cout<<(it->second)[i]<<" ";
            cout<<endl;
        }
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        unordered_map<int,vector<int>> elements;
        fillMap(elements, root, 0);
        //printMap(elements);
        return calculateAverage(elements);
    }
};



// My Approaches(2)
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
    vector<double> calculateAverage(queue<pair<int, TreeNode *>> & elements){
        double sum = 0;
        int count = 0, level = 0;
        vector<double> result;
        
        while(!elements.empty()){
            pair<int, TreeNode *> sumLevel = elements.front();
            cout<<"First: "<<sumLevel.first<<" Second: "<<sumLevel.second->val<<endl;
            if(sumLevel.first == level){
                sum += (sumLevel.second)->val;
                ++count;
            }
            else{
                cout<<"Average: "<<sum/count<<endl;
                result.push_back(sum/count);
                sum = (sumLevel.second)->val; 
                count = 1;
                level = sumLevel.first;
            }
            
            if((sumLevel.second)->left)
                elements.push(make_pair(level+1, (sumLevel.second)->left));
            if((sumLevel.second)->right)
                elements.push(make_pair(level+1, (sumLevel.second)->right));
            elements.pop();
        }
        result.push_back(sum/count);
        printVector(result);
        return result;
    }
    
    void printVector(vector<double> result){
        cout<<"Printing vector"<<endl;
        for(int i=0; i < result.size(); i++)
            cout<<result[i]<<" ";
    }
    
    
    vector<double> averageOfLevels(TreeNode* root) {
        queue<pair<int,TreeNode *>> elements;
        elements.push(make_pair(0, root));
        return calculateAverage(elements);
    }
    
    
};