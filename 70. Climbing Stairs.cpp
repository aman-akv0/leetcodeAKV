class Solution {
 public:
  int climbStairs(int n) {
    vector<int> akv(n + 1);
    akv[0] = 1;
    akv[1] = 1;

    for (int i = 2; i <= n; ++i)
      akv[i] = akv[i - 1] + akv[i - 2];

    return akv[n];
  }
};
