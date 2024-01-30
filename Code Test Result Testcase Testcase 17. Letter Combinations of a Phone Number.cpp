class Solution {
public:
    vector<string> res;
    // unordered_map<char, string> mp;

    // Solution() {
    //     mp['2'] = "abc";
    //     mp['3'] = "def";
    //     mp['4'] = "ghi";
    //     mp['5'] = "jkl";
    //     mp['6'] = "mno";
    //     mp['7'] = "pqrs";
    //     mp['8'] = "tuv";
    //     mp['9'] = "wxyz";
    // }

    void solve(string &digits, int i, string temp) {
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        if(digits.size()==0)  return ;
        if (i >= digits.size()) {
            res.push_back(temp);
            return;
        }

        char ch = digits[i];
        string str = mp[ch];
        for (int j = 0; j < str.size(); j++) {
            temp.push_back(str[j]);
            solve(digits, i + 1, temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string temp = "";
        solve(digits, 0, temp);
        return res;
    }
};
