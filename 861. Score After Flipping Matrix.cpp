class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        vector<uint8_t> col1(m, 0);
        int sum = 0;
        for (auto& row : grid) {
            int x = 0;
            bool one = 0;
            for (int i = 0; i < m; i++) {
                one = (row[0] == 0) ^ (row[i] == 1);
                x = (x << 1) + one;
                col1[i] += one;
            }
            sum += x;
        }
        for (int i = 0; i < m; i++) {
            if (col1[i] <= n / 2) 
                sum += (1 << (m - 1 - i)) * (n - 2 * col1[i]);
        }
        return sum;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
C++ 2nd approach interchanges the order row & column with memory O(1)||0ms Beats 100%
#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        const int r= grid.size(), c= grid[0].size();
        int sum = 0;
        for (int j=0; j<c; j++) {
            int col1= 0;
            int b=1<<(c-1-j);
            for (int i = 0; i < r; i++) {
                bool one = (grid[i][0] == 0) ^ (grid[i][j] == 1);
                col1+=one;
            }
            sum += max(r-col1, col1)*b;
        }
        return sum;
    }
};
