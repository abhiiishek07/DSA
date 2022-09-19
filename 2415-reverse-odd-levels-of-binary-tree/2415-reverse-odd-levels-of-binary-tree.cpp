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
    void helper(TreeNode* &root1,TreeNode* &root2,int level){
        if(!root1 || !root2)
            return;
        if(level%2==0)
            swap(root1->val,root2->val);
        helper(root1->left,root2->right,level+1);
        helper(root1->right,root2->left,level+1);
        return;
    }
    TreeNode* reverseOddLevels(TreeNode* &root) {
        if(!root)
            return NULL;
         helper(root->left,root->right,2);
        return root;
    }
};