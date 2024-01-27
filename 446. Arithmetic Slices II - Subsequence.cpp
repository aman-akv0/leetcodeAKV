class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long, long> mp[n];
        long long res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long diff = (long)nums[i] - nums[j];
                long long catj = 0;

                if (mp[j].find(diff) != mp[j].end()) {
                    catj = mp[j][diff];
                    res += catj; 
                }

                mp[i][diff] += catj + 1;
            }
        }

        return (int) res;  
    }
};
