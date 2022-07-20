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
    TreeNode* lca(TreeNode* root,TreeNode* a,TreeNode* b){
        if(!root)
            return NULL;
        if(root->val==a->val || root->val==b->val)
            return root;
        TreeNode* left=lca(root->left,a,b);
        TreeNode* right=lca(root->right,a,b);
        if(left && right)
            return root;
        if(left)
            return left;
        else
            return right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root)
            return NULL;
        vector<TreeNode*>v;            //to store deepest leaves
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<TreeNode*>prev;
            while(sz--){
                TreeNode* curr=q.front();
                q.pop();
                prev.push_back(curr);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            v=prev;
        }
        if(v.size()==1)
            return v[0];
        return lca(root,v[0],v[v.size()-1]);
    }
};