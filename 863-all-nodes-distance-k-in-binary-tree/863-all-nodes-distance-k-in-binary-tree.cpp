/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findPath(TreeNode* root,TreeNode* target,stack<TreeNode*>&st){
        if(!root)
            return false;;
        st.push(root);
        if(root->val==target->val)
            return true;
        if(findPath(root->left,target,st)||findPath(root->right,target,st))
            return true;
        st.pop();
        return false;
    }
    void findNodes(TreeNode* root,int k,vector<int>&ans){
        if(!root || k<0)
            return;
        if(k==0)
            ans.push_back(root->val);
        findNodes(root->left,k-1,ans);
        findNodes(root->right,k-1,ans);
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        stack<TreeNode*>st;
        bool x=findPath(root,target,st);
        vector<int>ans;
        int prev=-1;
        while(!st.empty() && k>0){
            TreeNode* curr=st.top();
            st.pop();
            if(curr->left && curr->left->val!=prev)
                findNodes(curr->left,k-1,ans);
            if(curr->right && curr->right->val!=prev)
                findNodes(curr->right,k-1,ans);
            k--;
            prev=curr->val;
        }
        if(!st.empty())
            ans.push_back(st.top()->val);
        return ans;
        
    }
};