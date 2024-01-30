// class Solution {
// public:
//     int operate(int a, int b,string token ){
//         if(token=="+") return a+b;
//         if(token=="*") return a*b;
//         if(token=="/") return a/b;
//         if(token=="-") return a-b;
//         return 0;
//     }
//     int evalRPN(vector<string>& tokens) {
//         stack<int>input;
//         int res=0;
//         for(string &token : tokens){
//             if (token=="+" || token == "-" || token =="*" || token =="/"){
//                 int b=input.top();
//                 input.pop();
//                 int a=input.top();
//                 input.pop();
//                 res=operate(a,b,token);
//                 input.push(res);
//             }else{
//                 input.push(stoi(token));
//             }
//         }return input.top();
        
//     }
// };


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int result = 0;
        
        unordered_map<string, function<int (int, int)> > mp = {
            {"+", [](int a, int b) {return a + b; } },
            {"-", [](int a, int b) {return a - b; } },
            {"*", [](int a, int b) {return (long)a * (long)b; } },
            {"/", [](int a, int b) {return a / b; } },
        };
        
        for(const string& s:tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                result = mp[s](a, b);
                st.push(result);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
