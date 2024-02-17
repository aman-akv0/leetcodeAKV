class Solution {
public:
    
    int help(int i,int j,vector<int>&nums,int pre,vector<vector<int>> &dp){
        
        if(i>=j)return 0;
        int ans=0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(nums[i]+nums[j]==pre)  ans=max(ans,1+help(i+1,j-1,nums,pre,dp));
        if(i+1<=j && nums[i]+nums[i+1]==pre) ans=max(ans,1+help(i+2,j,nums,pre,dp));
        if(j-1>=i && nums[j]+nums[j-1]==pre) ans=max(ans,1+help(i,j-2,nums,pre,dp));
        return dp[i][j]=ans;
        
    }
    int maxOperations(vector<int>& nums) {
        int n=nums.size()-1;
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        vector<vector<int>>dpp(n+2,vector<int>(n+2,-1));
        vector<vector<int>>pd(n+2,vector<int>(n+2,-1));
        
        int t=help(0,n,nums,nums[0]+nums[1],dp);
        if(t==(n+1)/2)return t;
        return max({t,help(0,n,nums,nums[0]+nums[n],dpp),
                    help(0,n,nums,nums[n]+nums[n-1],pd)});
    }
};
  3rd wala
