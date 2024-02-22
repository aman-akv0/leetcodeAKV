class Solution {
public:
    int m , n;
    int dp[1001][1001];
    int solve(string s, string t, int i , int j){
        if(j>=n) return 1;
        if(i>=m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans=solve(s,t,i+1,j);
        if(s[i]==t[j]){
            ans+= solve(s,t,i+1,j+1);
        }return dp[i][j]=ans;
    }
    int numDistinct(string s, string t) {
        m=s.size();
        n=t.size();
        memset(dp,-1,sizeof(dp));
        return solve(s,t,0,0);
    }
};
