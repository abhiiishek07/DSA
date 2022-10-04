/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findPath(TreeNode* root,int sum,int target){
        if(!root)
            return false;
        sum+=root->val;
        if(!root->left && !root->right && sum==target)
            return true;
        return findPath(root->left,sum,target) || findPath(root->right,sum,target);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return findPath(root,0,targetSum);
        
    }
};