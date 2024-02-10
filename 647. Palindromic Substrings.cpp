// class Solution {
// public:
//     int countSubstrings(string s) {
//         int n= s.size();
//         int count = 0;
        
//         for(int i=0;i<n;i++){
//             string s1="";
//             for(int j=i;j<n;j++){
//                 s1+=s[j];
//                 string rev=s1;
//                 reverse(rev.begin(),rev.end());
//                 if(rev==s1) count++;

//             }
//         }return count;
//     }
// };


// class Solution {
// public:
//     int t[1001][1001];
//     bool check(string &s, int i, int j) {
//         if(i >= j) {
//             return true;
//         }

//         if(t[i][j] != -1) {
//             return t[i][j]; //1 : True, 0 : False
//         }

//         if(s[i] == s[j]) {
//             return t[i][j] = check(s, i+1, j-1);
//         }

//         return t[i][j] = false;

//     }

//     int countSubstrings(string s) {
//         int n = s.length();
//         memset(t, -1, sizeof(t));
//         int count = 0;
//         for(int i = 0; i < n; i++) {
//             for(int j = i; j < n; j++) {
//                 if(check(s, i, j)) {
//                     count++;
//                 }
//             }
//         }

//         return count;
//     }
// };


class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n, false));
        //t[i][j] = true : s[i:j] is a substring where i and j are inclusive indices

        int count = 0;

        for(int L = 1; L <= n; L++) {
            for(int i = 0; i+L <= n; i++) {
                int j = i + L - 1;

                if(i == j) {
                    t[i][i] = true; //Single characters are palindrome
                } else if(i+1 == j) {
                    t[i][j] = (s[i] == s[j]); //Strings of 2 Length
                } else {
                    t[i][j] = ((s[i] == s[j]) && t[i+1][j-1] == true);
                }

                count += t[i][j];
            }
        }

        return count;
    }
};
