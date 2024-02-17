class Solution {
public:
    string lastNonEmptyString(string s) {
        int n=s.size();
        string res="";
        unordered_map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        int max=INT_MIN;
        for(auto it : mp){
            if(max<it.second){
                max=it.second;
            }
        }
        unordered_map<char,int> mpp;
        for(auto it:s){
            mpp[it]++;
            if(mpp[it]==max){
                res+=it;
            }
        }return res;
        
    }
};
