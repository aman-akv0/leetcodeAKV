class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int , int> mapi;
        int pref=0;
        mapi[0]=-1;
        int res=0;
        for(int i=0;i<n;i++){
            pref+=(nums[i]==1)? 1:-1;
            if(mapi.find(pref)!=mapi.end()){
                res=max(res,i-mapi[pref]);
            }else{
                mapi[pref]=i;
            }
        }return res;
        
    }
};
