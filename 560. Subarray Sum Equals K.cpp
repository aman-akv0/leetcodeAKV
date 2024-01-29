class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        mp[0]=1;
        int n=nums.size();
        int res=0;
        int pre=0;
        for(int i=0; i<n;i++){
            pre+=nums[i];
            int neww=pre-k;
            if(mp.find(neww)==mp.end()){
                mp[pre]++;
            }
            else{
                res+=mp[neww];
                mp[pre]++;
            }
            
            

        }return res;
    }
};
