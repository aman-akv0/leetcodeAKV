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
    int countNodes(TreeNode* root){
        if(!root) return 0;
        return 1+countNodes(root->left) + countNodes(root->right);
    }
    bool dfs(TreeNode * root,int i,int count){
        if(root==NULL) return true;
        if(count<i) return false;
        return dfs(root->left,2*i,count) && dfs(root->right,2*i+1,count);
    }
    bool isCompleteTree(TreeNode* root) {
        int count=countNodes(root);
        int i=1;
        return dfs(root,i,count);
        
    }
};
