class Solution {
public:
    string makeGood(string s) {
        string result="";
        int n=s.size();
        for(int i=0;i<n;i++){
            if(result.size()!=0 && (result.back()-32==s[i] || result.back()+32==s[i])){
                result.pop_back();
            }else result.push_back(s[i]);
        }return result;  
    }
};
