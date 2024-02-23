class Solution {
public:
    int n,k;
    int dp[100001][2];

    int solve(vector<int>& price, int i, int buy) {
        if (i == n ) return 0;
        int profit = 0;

        if (dp[i][buy] != -1) return dp[i][buy];

        if (buy) {
            int consider = solve(price, i + 1, false) - price[i];
            int notConsider = solve(price, i + 1, true);
            profit = max(consider, notConsider);
        } else {
            int consider = solve(price, i + 1, true) + price[i]-k;
            int notConsider = solve(price, i + 1, false);
            profit = max(consider, notConsider);
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& price, int fee) {
       
        n = price.size();
        k = fee;  
        memset(dp, -1, sizeof(dp));
        return solve(price, 0, true);
    }
};
