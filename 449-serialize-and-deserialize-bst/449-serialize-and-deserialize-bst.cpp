/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void serializeHelper(TreeNode* root,string &str){
        if(!root)
            return;
        str+=to_string(root->val)+",";
        serializeHelper(root->left,str);
        serializeHelper(root->right,str);
    }
    TreeNode* makeBST(TreeNode* root,int t){
        if(!root){
            TreeNode* n= new TreeNode(t);
            return n;
        }
        if(root->val<t)
            root->right= makeBST(root->right,t);
        else
            root->left= makeBST(root->left,t);
        return root;
    }
    TreeNode* getPreorder(string data,vector<int>&preorder){
        TreeNode* root=NULL;
        string temp="";
        for(char ch:data){
            if(ch==','){
                root=makeBST(root,stoi(temp));
                temp="";
            }
            else{
                temp+=ch;
            }
        }
        return root;
    }
    TreeNode* deserializeHelper(vector<int>&preorder,int mini,int maxi,int idx){
        if(idx>=preorder.size() || preorder[idx]<mini || preorder[idx]>maxi)
            return NULL;
        int val=preorder[idx];
        TreeNode* root=new TreeNode(val);
        idx++;
        root->left=deserializeHelper(preorder,mini,val,idx);
        root->right=deserializeHelper(preorder,val,maxi,idx);
        return root; 
    }
    string serialize(TreeNode* root) {
        string str;
        serializeHelper(root,str);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
            return NULL;
        vector<int>preorder;
        return getPreorder(data,preorder);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;