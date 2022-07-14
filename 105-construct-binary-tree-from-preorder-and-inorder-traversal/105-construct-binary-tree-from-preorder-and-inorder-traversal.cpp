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
    unordered_map<int,int>mp;         // to store inorder index
    
    TreeNode* solve(vector<int>& pre,vector<int>& in,int l,int r,int &idx){
        if(l>r)
            return NULL;
        int k=mp[pre[idx]];
        TreeNode* root= new TreeNode(pre[idx++]);
        root->left= solve(pre,in,l,k-1,idx);
        root->right= solve(pre,in,k+1,r,idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        int l=0,r=preorder.size()-1,idx=0;
        return solve(preorder,inorder,l,r,idx);
    }
};