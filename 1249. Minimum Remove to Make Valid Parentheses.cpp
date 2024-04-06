class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack <int> st;
        string res="";
        vector<bool> remove(s.size(), false);

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }else if(s[i]==')' && st.empty()){
                remove[i] = true;
            }else if(s[i]==')' && !st.empty()){
                st.pop();
            }
        }
        while (!st.empty()) {
            remove[st.top()] = true;
            st.pop();
        }
        for (int i = 0; i < s.size(); i++) {
            if (!remove[i]) {
                res += s[i];
            }
        }

        return res;
        
    }
};
