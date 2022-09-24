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
    vector<vector<int>>ans;
    void solve(TreeNode* root,int sum,int target,vector<int>temp){
        if(!root)
            return;
        temp.push_back(root->val);
        sum+=root->val;
        if(!root->left && !root->right){
            if(sum==target)
                ans.push_back(temp);
            return;
        }
        solve(root->left,sum,target,temp);
        solve(root->right,sum,target,temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        solve(root,0,targetSum,temp);
        return ans;
    }
};