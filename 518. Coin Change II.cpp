class Solution {
public:
    int n;
    int t[301][5001];
    int solve(int k, vector<int>& coins,int i){
        if(k==0) return 1;
        if(i == n || k < 0) return 0;
            
        if(t[i][k] != -1) return t[i][k];
        if(k<coins[i]) return t[i][k]=solve(k,coins,i+1);
        long long take=solve(k-coins[i],coins,i) ;
        long long skip=solve(k,coins,i+1) ;
        return t[i][k]=(take+skip);
    }
    int change(long long k, vector<int>& coins) {
        n=coins.size();
        memset(t,-1,sizeof(t));
        return solve(k,coins,0);
    }
};
