    vector<int> dp(10001,-1);
class Solution {
public:
    int numSquares(int n) {
        // memset(dp,-1,sizeof(dp)); ..wrong..
        if(n<=0) return 0;
        if(dp[n] != -1) return dp[n];
        int c=0;
        int mini=INT_MAX;
        for(int i=1;i*i<=n;i++){
            int sq=i*i;
            c=1+numSquares(n-sq);
            mini=min(mini,c);
        }return dp[n]=mini;
    }
};
