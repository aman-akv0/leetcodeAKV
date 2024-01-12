class Solution {
public:
    bool isVowel(char ch) {
        char lowerCh = tolower(ch);
        return (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u');
    }
    bool halvesAreAlike(string s) {
        int n=s.size();
        int c1=0;
        int c2=0;
        for(int i=0;i<n;i++){
            if((i<(n/2)) && isVowel(s[i])) c1++;
            else if((i>=(n/2)) && isVowel(s[i])) c2++;
        }
        return c1==c2;
        
    }
};
