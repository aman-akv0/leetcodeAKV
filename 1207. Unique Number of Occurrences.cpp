class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        bool res=false;
        for(int i:arr){
            mp[i]++;
        }
        unordered_set<int>s;
        for(auto it : mp){
            if(s.find(it.second)!=s.end()){
                res=false;
                break;
            }
            s.insert(it.second);
            res=true;
        }if(res) return true;
        else return false;

    }
};
