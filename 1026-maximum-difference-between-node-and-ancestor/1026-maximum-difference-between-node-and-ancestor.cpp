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
    int ans;
    void solve(TreeNode* root,int mini,int maxi){
        if(!root)
            return;
        int res=max(abs(root->val-mini),abs(root->val-maxi));
        ans=max(ans,res);
        maxi=max(maxi,root->val);
        mini=min(mini,root->val);
        solve(root->left,mini,maxi);
        solve(root->right,mini,maxi);
    }
    int maxAncestorDiff(TreeNode* root) {
        ans=0;
        solve(root,root->val,root->val);
        return ans;
    }
};