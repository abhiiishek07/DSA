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
    unordered_map<int,int>mp;
    int solve(TreeNode* root){
        if(!root)
            return 0;
        int ls=solve(root->left);
        int rs=solve(root->right);
        mp[root->val+ls+rs]++;
        return root->val+ls+rs;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int x=solve(root);
        int maxi=INT_MIN;
        for(auto it:mp)
            maxi=max(maxi,it.second);
        vector<int>ans;
        for(auto it:mp){
            if(it.second==maxi)
                ans.push_back(it.first);
        }
        return ans;
    }
};