#include<bits/stdc++.h>
using namespace std;

int m, n;
int dp[3001][3001];

int solve(string &a, string &b, int i, int j) {
    if (i >= m || j >= n)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (a[i] == b[j])
        return dp[i][j] = solve(a, b, i + 1, j + 1) + 1;

    return dp[i][j] = max(solve(a, b, i + 1, j), solve(a, b, i, j + 1));
}

string getLCS(string &a, string &b) {
    int i = 0, j = 0;
    string lcs;

    while (i < m  && j < n) {
        if (a[i] == b[j]) {
            lcs += a[i];
            i++;
            j++;
        } else if (dp[i + 1][j] > dp[i][j + 1]) {
            i++;
        } else {
            j++;
        }
    }

    return lcs;
}

int main() {
    string a, b;
    cin >> a >> b;
    m = a.size();
    n = b.size();
    memset(dp, -1, sizeof(dp));
    solve(a,b,0,0);
    cout <<getLCS(a, b) << endl;

    return 0;
}
