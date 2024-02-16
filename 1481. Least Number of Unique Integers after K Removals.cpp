class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(auto it : arr){
            mp[it]++;
        }
        vector<pair<int,int>>v;
        for(auto it:mp){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end());
        
        for(int i=0;i<v.size();i++){
            if(v[i].first>k) return v.size()-i;
            k=k-v[i].first;
            // v.size()--;
        }return 0;
    }
};
