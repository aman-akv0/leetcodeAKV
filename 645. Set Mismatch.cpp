class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>v;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int c=0;
        int sum=(n*(n+1)/2);
        int miss=0;
        for(int i=0; i<n;i++){
            miss+=nums[i];
        }
        for(int i=0;i<n-1;i++){
            c=nums[i]^nums[i+1];
            if(c==0){
                v.push_back(nums[i]);
                miss=miss-nums[i];
                v.push_back(sum-miss);
                break;
            }
            
        }
        return v;     
    }
};
