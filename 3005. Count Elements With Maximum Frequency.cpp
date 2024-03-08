class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto it : nums){
            mp[it]++;
        }
        int x=0;
        for(auto it:mp){
            if(it.second>x){
                x=it.second;              
            }
        }
        int y=0;
        for(auto it:mp){
            if(it.second==x){
                y+=it.second;
            }
        }return y;
        
    }
};
