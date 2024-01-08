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
    void inOrder(TreeNode *root,vector<int> &v ){
        if(root==NULL){
            return ;
        }

        inOrder(root->left , v);
        v.push_back(root->val);
        inOrder(root->right,v);

    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int>ans;
        int sum=0;
        inOrder(root,ans);
        for(int i=0;i<ans.size();i++){
            if(ans[i]>=low && ans[i]<=high){
                sum+=ans[i];
            }
        }return sum;
    }

};
