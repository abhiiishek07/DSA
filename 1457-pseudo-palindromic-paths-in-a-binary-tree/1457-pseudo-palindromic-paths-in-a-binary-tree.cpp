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
    bool checkPalindrome(unordered_map<int,int>m){
        int count=0;
        for(auto it:m){
            if(it.second%2!=0)
                count++;
        }
        return count<=1;
    }
    void solve(TreeNode* root,unordered_map<int,int>&mp,int &ans){
        if(!root)
            return;
        mp[root->val]++;
        if(!root->left && !root->right){
            if(checkPalindrome(mp)){
                ans++;
            }
            mp[root->val]--;
            return;
        }
        solve(root->left,mp,ans);
        solve(root->right,mp,ans);
        mp[root->val]--;
        return;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans=0;
        unordered_map<int,int>mp;
        solve(root,mp,ans);
        return ans;
    }
};