class Solution {
public:
    int n;
    int dp[100001][2][3];

    int solve(vector<int>& price, int i, int buy, int k) {
        if (i == n || k == 0) return 0;
        int profit = 0;

        if (dp[i][buy][k] != -1) return dp[i][buy][k];

        if (buy) {
            int consider = solve(price, i + 1, false, k) - price[i];
            int notConsider = solve(price, i + 1, true, k);
            profit = max(consider, notConsider);
        } else {
            int consider = solve(price, i + 1, true, k - 1) + price[i];
            int notConsider = solve(price, i + 1, false, k);
            profit = max(consider, notConsider);
        }
        return dp[i][buy][k] = profit;
    }

    int maxProfit(vector<int>& price) {
        memset(dp, -1, sizeof(dp));
        n = price.size();
        int k = 2;  
        return solve(price, 0, true, k);
    }
};
