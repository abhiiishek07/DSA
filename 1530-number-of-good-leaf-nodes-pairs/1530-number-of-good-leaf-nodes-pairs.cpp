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
    vector<int> solve(TreeNode* root,int k,int &cnt){
        if(!root)
            return {};
        if(!root->left && !root->right)
            return {1};
        vector<int>left= solve(root->left,k,cnt);
        vector<int>right=solve(root->right,k,cnt);
        
        vector<int>temp;
        for(int x:left) temp.push_back(x+1);
        for(int y:right) temp.push_back(y+1);
        
        for(int x:left){
            for(int y:right)
                cnt+= (x+y)<=k?1:0;
        }
        return temp;
    }
    int countPairs(TreeNode* root, int distance) {
        int cnt=0;
        vector<int>x=solve(root,distance,cnt);
        return cnt;
    }
};
/* Accepted 

    void findGoodPairs(TreeNode* root,int k,int &cnt){
        if(!root || k<0)
            return;
        if(!root->left && !root->right)
            cnt++;
        findGoodPairs(root->left,k-1,cnt);
        findGoodPairs(root->right,k-1,cnt);
        return;
    }
    
    void goodPairs(stack<TreeNode*>st,int k,TreeNode* prev,int &cnt){
        while(!st.empty() && k>0){
            TreeNode* curr=st.top();
            st.pop();
            if(curr->left && curr->left!=prev)
                findGoodPairs(curr->left,k-1,cnt);
            if(curr->right && curr->right!=prev)
                findGoodPairs(curr->right,k-1,cnt);
            k--;
            prev=curr;
        } 
        return;
    }
    void solve(TreeNode* root,int k,int &cnt,stack<TreeNode*>st){
        if(!root)
            return;
        if(!root->left && !root->right)
            goodPairs(st,k-1,root,cnt);
        st.push(root);
        solve(root->left,k,cnt,st);
        solve(root->right,k,cnt,st);
        st.pop();
        return;
    }
    int countPairs(TreeNode* root, int distance) {
        stack<TreeNode*>st;
        int cnt=0;
        solve(root,distance,cnt,st);
        return cnt/2;
    }
    */