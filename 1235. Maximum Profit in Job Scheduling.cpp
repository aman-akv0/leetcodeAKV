class Solution {
public:
    int n;
    int t[50001];
    int getNext(vector<vector<int>>&arr , int l , int end){
        int r = n-1;
        int result=n+1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid][0] >= end) { 
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return result;
    }
        
        
    
    int solve(vector<vector<int>> &arr , int i){
        if(i>=n) return 0;
        int ans=0;
        if(t[i] != -1) return t[i];
        int next= getNext(arr,i+1,arr[i][1]);
        int taken=arr[i][2]+solve(arr,next);
        int skip= solve(arr,i+1);
        return t[i]=max(taken,skip);
    }
    int jobScheduling(vector<int>& st, vector<int>& et , vector<int>& pro) {
        n=st.size();
        memset(t,-1,sizeof(t));
        vector<vector<int>>arr(n,vector<int>(3,0));
        for(int i=0;i<n;i++){
            arr[i][0]=st[i];
            arr[i][1]=et[i];
            arr[i][2]=pro[i];
        }
        sort(arr.begin() , arr.end());
        return solve(arr,0);
    }
};
