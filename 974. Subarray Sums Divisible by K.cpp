class Solution {
public:
    // int subarraysDivByK(vector<int>& nums, int k) {
    //    int n=nums.size();
    //    int c=0;
    //    for(int i=1;i<n;i++){
    //        nums[i]+=nums[i-1];
    //    } 
    //    for(int i=0; i<n;i++){
    //     //    int sum=0;
    //        for(int j=i; j<n; j++){
    //         //    int sum=0;
    //         //    if(i==0){
    //         //        sum=nums[j];
    //         //    }else {
    //         //        sum=nums[j]-nums[i-1];
    //         //    }
    //             long long sum=(i==0)? nums[j] : nums[j]-nums[i-1];
    //             if(sum%k==0) c++;
    //        }
    //    }return c;
    // }
    int subarraysDivByK(vector<int>& nums, int k) {
       int n=nums.size();
       unordered_map<int ,  int> mp;
       int sum=0;
       mp[0]=1;
       int result=0;
       for(int i=0; i<n ; i++){
           sum+=nums[i];
           int rem=sum%k;
           if(rem<0) rem+=k;
           if(mp.find(rem)!=mp.end()){
               result+=mp[rem];
               
           }mp[rem]++;
       }return result;
    }
};
