class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        bool flag=false;
        for(int i=0;i<n-2;i++){
            if(arr[i]%2!=0 && arr[i+1]%2!=0 && arr[i+2]%2!=0) flag = true;
            
        }
        if(flag) return true;
        else return false;
        
    }
};
