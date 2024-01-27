class Solution {
public:
    long long  t[1001][1001];
    long long  mod=1e9+7;
    int solve(long long  n , long long k){
        if(n==0) return 0;
        if(k==0) return 1;
        if(t[n][k] != -1) return t[n][k];
        long long  res=0;
        for(int inv=0; inv<=min (k, n-1) ; inv++){
            res+=solve(n-1,k-inv)%mod;
        }
        return t[n][k]=res%mod;
    }
    int kInversePairs(int n, int k) {
        memset(t,-1,sizeof(t));
        return solve(n,k);
    }
};
