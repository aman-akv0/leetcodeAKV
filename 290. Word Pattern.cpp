class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string token;
        int count=0;
        while(getline(ss,token, ' ')) {
            words.push_back(token);
            count++;
        }

        unordered_map<string , char> mp;
        unordered_set<char> used;
        
        if(pattern.size()!=count) return false;
        for(int i=0;i<pattern.size();i++){
            string word=words[i];
            char ch = pattern[i];
            if(mp.find(word) == mp.end() && used.find(ch) == used.end()){
                mp[word]=ch;
                used.insert(ch);

            }else if(mp[word] != ch) return false;
        }return true;
    }
};
