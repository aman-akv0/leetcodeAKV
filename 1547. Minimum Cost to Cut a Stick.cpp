class Solution {
public:
    int dp[103][103];
    long long solve(int n, vector<int>& cuts,int l,int r){
        if(r-l<2) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        long long res=INT_MAX;
        for(int i=l+1;i<=r-1;i++){
            long long  cost=(cuts[r]-cuts[l])+ solve(n,cuts,l,i)+ solve(n,cuts,i,r);
            res=min(res,cost);
        }return dp[l][r]=res;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        memset(dp,-1,sizeof(dp));
        return solve(n,cuts,0,cuts.size()-1);
    }
};
