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
    TreeNode* solve(stack<int>&st,int mini,int maxi){
        if(st.empty() || st.top()<mini || st.top()>maxi)
            return NULL;
        int x=st.top();
        st.pop();
        TreeNode* root= new TreeNode(x);
        root->left=solve(st,mini,x);
        root->right=solve(st,x,maxi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<int>st;
        for(int i=preorder.size()-1;i>=0;i--)
            st.push(preorder[i]);
        int mini=INT_MIN,maxi=INT_MAX;
        return solve(st,mini,maxi);
    }
};