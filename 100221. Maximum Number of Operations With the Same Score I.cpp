class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int sum=nums[0]+nums[1];
        int c=1;
        if(n%2==0){
            for(int i=2;i<n;i+=2){
                if(nums[i]+nums[i+1] == sum){
                    c++;
                    // sum=nums[i]+nums[i+1];
                }else break;
            }return c;
        }else{
            for(int i=2;i<n-1;i+=2){
                if(nums[i]+nums[i+1] == sum){
                    c++;
                    // sum=nums[i]+nums[i+1];
                }else break;
            }return c;
        }
        
        return -1;
    }
};
