class Solution {
    int n;
public:
    int dp[501];
    int solve(vector<int>& arr, int k , int i){
        if(i>=n){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int curr=-1;
        int sum=0;
    
        for(int j=i ; j<min(n,i+k) ; j++){
            curr=max(curr,arr[j]);
            sum=max(sum,(curr*(j-i+1))+solve(arr,k,j+1));
        }
        return dp[i]=sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n=arr.size();
        memset(dp,-1,sizeof(dp));
        return solve(arr,k,0);
    }
};
