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
    vector<vector<int>> path;
    
    void solve(TreeNode* root, int &targetSum , int sum,vector<int>temp){
        if(!root) return ;
        sum+=root->val;
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                path.push_back(temp);
            }return;
        }
        solve(root->left,targetSum,sum,temp);
        solve(root->right,targetSum,sum,temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // if(!root) return 0;
        int sum=0;
        vector<int>temp;
        solve(root,targetSum, sum,temp);
        return path;

    }
};
