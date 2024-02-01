class Solution {
public:
    int n;
    int minFlipsMonoIncr(string s) {
        n=s.size();
        // return solve(s,-1,-1)
        int cof1=0;
        int flip=0;
        for(char &ch : s){
            if(ch=='1') cof1++;
            else{
                flip=min(flip+1,cof1);
            }
        }return flip;
    }
};
