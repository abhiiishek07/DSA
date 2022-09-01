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
    void solve(TreeNode* root,int maxi,int &cnt){
        if(!root)
            return;
        if(root->val>=maxi){
            cnt++;
            maxi=root->val;
        }
        solve(root->left,maxi,cnt);
        solve(root->right,maxi,cnt);
    }
    int goodNodes(TreeNode* root) {
      int maxi=INT_MIN;
        int cnt=0;
        solve(root,maxi,cnt);
        return cnt;
    }
};