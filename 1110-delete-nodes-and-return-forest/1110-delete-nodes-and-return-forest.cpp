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
    TreeNode* solve(TreeNode* &root,unordered_set<int>st,vector<TreeNode*>&ans){
        if(!root)
            return NULL;
        root->left=solve(root->left,st,ans);
        root->right=solve(root->right,st,ans);
        if(st.find(root->val)!=st.end()){
            if(root->left)
                ans.push_back(root->left);
            if(root->right)
                ans.push_back(root->right);
            return NULL;
        }
        return root;
        
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        unordered_set<int>st(to_delete.begin(),to_delete.end());
        if(st.find(root->val)==st.end())
            ans.push_back(root);
        solve(root,st,ans);
        return ans;
    }
};