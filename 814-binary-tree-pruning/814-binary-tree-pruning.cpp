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
    bool solve(TreeNode* &root){
        if(!root)
            return false;
        bool left=solve(root->left);
        bool right= solve(root->right);
        if(!left)
            root->left=NULL;
        if(!right)
            root->right=NULL;
        if(root->val || left || right)
            return true;
        return false;
        
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool flag= solve(root);
        if(!flag)
            return NULL;
        return root;
    }
};