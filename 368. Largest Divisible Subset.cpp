// class Solution {
// public:
//     int n;
//     int dp[1001][1001];
//     void solve(vector<int>& nums,int i,vector<int>&ans,vector<int>&temp , int prev){
//         if(i>=n){
//             if(temp.size()>ans.size()){
//                 ans=temp;
//             }
//             return;
//         }
//         if(prev==-1 || nums[i]%nums[prev]==0){
//             temp.push_back(nums[i]);
//             solve(nums,i+1,ans,temp,i);
//             temp.pop_back();
//         }
//         solve(nums,i+1,ans, temp,prev);    
//     }
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         n= nums.size();
//         memset(dp,-1,sizeof(dp));
//         sort(nums.begin(),nums.end());
//         vector<int>ans;
//         vector<int>temp;
//         int prev=-1;
//         solve(nums,0,ans , temp , prev);
//         return ans;
//     }
// };



class Solution {
public:
    int n;
    int dp[1001][1001];
    void solve(vector<int>& nums,int i,vector<int>&ans,vector<int>&temp , int prev){
        if(i>=n){
            if(temp.size()>ans.size()){
                ans=temp;
            }
            return;
        }
        if(prev==-1 || nums[i]%nums[prev]==0){
            temp.push_back(nums[i]);
            solve(nums,i+1,ans,temp,i);
            temp.pop_back();
        }
        solve(nums,i+1,ans, temp,prev);    
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        n= nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>prev(n,-1);
        int lastindexfound=0;
        int maxi=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        prev[i]=j;
                    }
                }
            }if(dp[i]>maxi){
                 maxi=dp[i];
                 lastindexfound=i;
            }
        }
        vector<int>ans;
        while(lastindexfound >= 0){
            ans.push_back(nums[lastindexfound]);
            lastindexfound = prev[lastindexfound];
        }
        return ans;
    }
};
