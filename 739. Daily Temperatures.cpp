// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& t) {
//         int n = t.size();
//         vector<int> v(n, 0);  
//         for (int i = 0; i < n - 1; i++) {
//             int c = 0;
//             if (t[i] < t[i + 1]) {
//                 c++;
//                 v[i] = c;
//             } else {
//                 int j = i + 1;
//                 while (j < n && t[i] >= t[j]) {
//                     j++;
//                     c++;
//                 }
//                 if (j < n) {
//                     c = j - i;
//                     v[i] = c;
//                 }
                
//             }
//         }
//         return v;
//     }
// };

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> input;
        int n = t.size();
        vector<int>v(n,0);
        int c=0;
        input.push(0);
        for(int i=1; i<n;i++){
            while(!input.empty()&&t[i]>t[input.top()]){
                v[input.top()]=i-input.top();
                input.pop();
            }
                input.push(i);
        }return v;
    }
};
