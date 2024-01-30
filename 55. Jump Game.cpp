class Solution {
public:
    int n;
    int t[10001];
    bool solve(vector<int>& nums,int i){
        if(i>=n-1) return true;
        if(t[i] != -1) return t[i];
        for(int j=1; j<=nums[i] ; j++){
            
            if(solve(nums,i+j)) return t[i] = true;
        }
        return t[i] = false ;
    }

    bool canJump(vector<int>& nums) {
        n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(nums,0);
        
    }
};
