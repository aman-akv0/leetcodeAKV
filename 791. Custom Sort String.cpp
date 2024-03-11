
class Solution {
public:
    string customSortString(string order, string s) {
        string res = "";

        for (int i = 0; i < order.size(); i++) {
            for (int j = 0; j < s.size(); j++) {
                if (order[i] == s[j]) {
                    res += order[i];
                }
            }
        }
        for (int i = 0; i < s.size(); i++) {
            bool found = false;
            for (int j = 0; j < order.size(); j++) {
                if (s[i] == order[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                res += s[i];
            }
        }

        return res;
    }
};
