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
  string res="~";
    void dfs(TreeNode* root, string str)
    {
        if(root==NULL)
            return;
        str+=(char)(root->val+'a');
        if(!root->left && !root->right)
        {
            reverse(str.begin(),str.end());
            res=min(res,str);
        }
        dfs(root->left,str);
        dfs(root->right,str);
        
        str.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string str="";
        dfs(root,str);
        return res;
    }
};