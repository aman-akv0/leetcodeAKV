class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
    
        vector<int>map1(26,0);
        vector<int>map2(26,0);
        vector<int>map11(26,0);
        vector<int>map22(26,0);
        for(auto it:word1){
            map1[it-'a']++;
            map11[it-'a']=1;
        }
        
        for(auto it:word2){
            map2[it-'a']++;
            map22[it-'a']=1;
        }
        sort(map1.begin(),map1.end());
        sort(map2.begin(),map2.end());
        if ((map1==map2 && map11==map22)) return true;
        else return false;
    
       

    }
};
