// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         int count = 0;
//         int candidate = 0; 
        
//         for (int i = 0; i < n; i++) {
//             if (count == 0) {
//                 candidate = nums[i];
//                 count = 1;
//             } else {
//                 if (nums[i] == candidate) {
//                     count++;
//                 } else {
//                     count--;
//                 }
//             }
//         }
        
             
//         return candidate;
//     }
// };


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int , int>mp;
        for(auto it:nums) mp[it]++;
        for(auto i : mp){
            if(i.second>(n/2)) return i.first;
        }return 0;
    }
};



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return nums[n/2];
    }
};
