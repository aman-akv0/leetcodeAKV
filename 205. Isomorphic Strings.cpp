// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         int m=s.size();
//         int n=t.size();
//         if(m!=n) return false;
//         unordered_map<char,int> mp1;
//         unordered_map<char,int> mp2;
         
//         for(auto it : s){
//             mp1[it]++;
//         }

//         for(auto it : t){
//             mp2[it]++;
//         }
//         bool st=true;
//         for (int i = 0; i < m; i++) {
//             if (mp1[s[i]] != mp2[t[i]]) {
//                 st=false;
//             }
//         }
//         if(st) return true;
//         else return false;
//     }
// };

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (m != n) return false;
        
        unordered_map<char, char> s_to_t;
        unordered_map<char, char> t_to_s;
        
        for (int i = 0; i < m; i++) {
            char s_char = s[i];
            char t_char = t[i];
            
            if (s_to_t.find(s_char) == s_to_t.end() && t_to_s.find(t_char) == t_to_s.end()) {
                s_to_t[s_char] = t_char;
                t_to_s[t_char] = s_char;
            } else {
                if (s_to_t[s_char] != t_char || t_to_s[t_char] != s_char) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
