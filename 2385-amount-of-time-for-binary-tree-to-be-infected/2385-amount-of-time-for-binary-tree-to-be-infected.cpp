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
    bool path(TreeNode* root,int start,stack<TreeNode*>&st){
        if(!root)
            return false;
        st.push(root);
        if(root->val==start)
            return true;
        if( path(root->left,start,st) || path(root->right,start,st))
            return true;
       
        st.pop();
        return false;
    }
    int amountOfTime(TreeNode* root, int start) {
        stack<TreeNode*>st;
        bool x=path(root,start,st);
        queue<TreeNode*>q;
        q.push(st.top());
        st.pop();
        int ans=0;
        unordered_set<int>seen;
        while(!q.empty()){
            int size=q.size();
            while(size--){
            TreeNode* curr=q.front();
            q.pop();
            seen.insert(curr->val);
            if(curr->left && seen.find(curr->left->val)==seen.end())
                q.push(curr->left);
            if(curr->right && seen.find(curr->right->val)==seen.end())
                q.push(curr->right);
            
            }
            if(!st.empty()){
                q.push(st.top());
                st.pop();
            }
           if(!q.empty())
           ans++;
        }
        return ans;
      
    }
};