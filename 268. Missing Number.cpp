// class Solution {
//  public:
//   int missingNumber(vector<int>& nums) {
//     int ans = nums.size();

//     for (int i = 0; i < nums.size(); ++i)
//       ans ^= i ^ nums[i];

//     return ans;
//   }
// };

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int Nsum= (n*(n+1))/2;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int missingNumber=Nsum-sum;
        return missingNumber;
    }
};

