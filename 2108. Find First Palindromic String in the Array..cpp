class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int n=words.size();
        string temp="";
        for(int i=0;i<n;i++){
            temp=words[i];
            reverse(temp.begin(),temp.end());
            if(words[i]==temp) return words[i] ;
        }return "";
    }
};
