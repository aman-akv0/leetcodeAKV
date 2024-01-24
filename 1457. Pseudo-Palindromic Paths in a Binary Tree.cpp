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
    int res=0;
    void solve(TreeNode* root,vector<int>&ans){
        if(root==NULL) return;
        ans[root->val]++;
        if(root->left==NULL && root->right==NULL){
            int odd=0;
            for(int i=1;i<=9;i++){
                if(ans[i]%2 != 0){
                    odd++;
                }
            }
            if(odd<=1){
                res+=1;
            }
        }
        solve(root->left,ans);
        solve(root->right,ans);
        ans[root->val]--;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>ans(10,0);
        solve(root,ans);
        return res;
        
    }
};
