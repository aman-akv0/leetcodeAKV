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
    bool isOnePresent (TreeNode * Node ){
        if(Node==NULL) return false;
        if(Node->val==1) return true;
        return (isOnePresent(Node->left) || isOnePresent(Node->right));
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL) return NULL;
        if(!isOnePresent(root->left)) root->left=NULL;
        if(!isOnePresent(root->right)) root->right=NULL;
        pruneTree(root->left);
        pruneTree(root->right);
        if(root->left==NULL && root->right==NULL && root->val==0){
            return NULL;
        }return root;
        
    }
};
