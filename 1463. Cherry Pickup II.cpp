class Solution {
public:
    int dp[101][101][101];
    int m,n;
    int solve(vector<vector<int>>& grid,int row,int c1,int c2){
        if(row>=m) return 0;
        if(dp[row][c1][c2] != -1) return dp[row][c1][c2];
        int total=grid[row][c1];
        if(c1!=c2){
            total+=grid[row][c2];
        }
        int ans =0;
        for(int val1=-1;val1<=1;val1++){
            for(int val2=-1;val2<=1;val2++){
                int newrow= row+1;
                int newcol1=val1+c1;
                int newcol2=val2+c2;
                if(newcol1>=0 && newcol1<n && newcol2>=0 && newcol2<n)
                    ans=max(ans,solve(grid,newrow,newcol1,newcol2));
                
            }
        } return dp[row][c1][c2]=total+ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(grid,0,0,n-1);
    }
};
