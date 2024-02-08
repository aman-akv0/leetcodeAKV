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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root == p || root== q ) return root;
        TreeNode* lefty=lowestCommonAncestor(root->left,p,q);
        TreeNode* righty=lowestCommonAncestor(root->right,p,q);
        if(lefty!=NULL && righty!=NULL) return root;
        if(lefty!=NULL) return lefty;
        return righty;
    }
};
