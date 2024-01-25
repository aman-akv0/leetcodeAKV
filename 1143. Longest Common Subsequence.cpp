class Solution {
public:
    int res[1001][1001];
    int solve(string &text1, string &text2,int i, int j){
    
        if(i>=text1.size() || j>=text2.size()){
            return 0;
        }
        // int ans=0;
        if(res[i][j]!=-1) {
            // ans=res[i][j];
            return res[i][j];
        }

        
        if(text1[i]==text2[j]){
            // ans=solve(text1,text2,i+1,j+1)+1;
            return res[i][j]=solve(text1,text2,i+1,j+1)+1;
        }
        // ans=max(solve(text1,text2,i+1,j),solve(text1,text2,i,j+1));
        
        return res[i][j]=max(solve(text1,text2,i+1,j),solve(text1,text2,i,j+1));
        // return res[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i=0;
        int j=0;
        memset(res,-1,sizeof(res));
        return solve(text1,text2,i,j);
        // return res;
        
    }
};
