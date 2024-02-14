// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         vector<int>v(n);
//         for(int i=0;i<((n/2)-1);i++){
//             v[2*i+1]=nums[i];
//         }
//         for(int i=(n/2);i<n;i++){
//             // if(i%2==0){
//             //     v[i/2]=nums[i];
//             // }else{
//             //     v[(i/2)-1]=nums[i];
//             // }
//             v[2*i-n]=nums[i];
            
//         }return v;
//     }
// };

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positiveElements;
        vector<int> negativeElements;

        for (int num : nums) {
            if (num > 0) {
                positiveElements.push_back(num);
            } else {
                negativeElements.push_back(num);
            }
        }

        int i = 0;
        for (int num : positiveElements) {
            nums[i] = num;
            i += 2;
        }
        i = 1;
        for (int num : negativeElements) {
            nums[i] = num;
            i += 2;
        }return nums;
    }
};
