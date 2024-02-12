class Solution {
public:
    int n;
    int solve(vector<vector<int>>& matrix,int row,int col,vector<vector<int>>&dp){
        if(row==n-1){
            return matrix[row][col];
        }
        if(dp[row][col]!=-101)return dp[row][col];
        int sum=matrix[row][col];
        int minSum=INT_MAX;
        if( col-1>=0)
            minSum=min(minSum,solve(matrix,row+1,col-1,dp));
        // if(row+1<n)
            minSum=min(minSum,solve(matrix,row+1,col,dp));
        if(col+1<n)
            minSum=min(minSum,solve(matrix,row+1,col+1,dp));
        return dp[row][col]=minSum+sum;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n=matrix.size();
        int row=0;
        int res=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,-101));
        for(int col=0;col<n;col++){
            res=min(res,solve(matrix,row,col,dp));

        }return res;
        
        
    }
};
