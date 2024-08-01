class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (details[i].size() >= 13) {
                string st = details[i].substr(11, 2);
                int res = stoi(st);
                if (res > 60) c++;
            }
        }
        return c;
    }
};
