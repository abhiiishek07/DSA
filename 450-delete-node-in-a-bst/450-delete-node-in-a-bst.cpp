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
    TreeNode* getSucc(TreeNode* root){
        TreeNode* curr=root->right;
        while(curr && curr->left)
            curr=curr->left;
        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return NULL;
        if(root->val>key)
            root->left=deleteNode(root->left,key);
        else if(root->val<key)
            root->right=deleteNode(root->right,key);
        else{
            if(!root->left){
                return root->right;

            }
            else if(!root->right){
                return root->left;
               
            }
            else{
                TreeNode* succ=getSucc(root);
                root->val=succ->val;
                root->right= deleteNode(root->right,succ->val);
            }
            
        }
        return root;
        
    }
};