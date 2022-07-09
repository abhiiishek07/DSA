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
    int solve(TreeNode* root,unordered_map<TreeNode*,int>&mp){
        if(!root)
            return 0;
        if(mp.find(root)!=mp.end())
            return mp[root];
        int pick= root->val;
        if(root->left)
            pick+= solve(root->left->left,mp)+solve(root->left->right,mp);
        if(root->right)
            pick+= solve(root->right->left,mp)+solve(root->right->right,mp);
        
        int not_pick= solve(root->left,mp)+solve(root->right,mp);
        return mp[root]=max(pick,not_pick);
        
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>mp;
        return solve(root,mp);
    }
};