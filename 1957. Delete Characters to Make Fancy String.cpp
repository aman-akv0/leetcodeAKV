class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        int c=0;
        string ans="";
        for(int i=0;i<n;i++){
            if(i!=0 && i!=n-1 && s[i-1]==s[i] && s[i]==s[i+1]){
                continue;
            }else{
                ans+=s[i];
            }
        }return ans;
        
    }
};
