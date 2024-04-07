class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        stack <int> st , star;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }else if(s[i]=='*'){
                star.push(i);
            }else{
                if(!st.empty()) st.pop();
                else if (!star.empty()) star.pop();
                else return false;
            }
        }
        while(!st.empty()){
            if(star.empty()) return false;
            else if(st.top()<star.top()){
                st.pop();
                star.pop();
            } 
            else return false;
        } return true;
    }
};
