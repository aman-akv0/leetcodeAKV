class Solution {
public:
    bool hasDuplicate(string &s1, string &s2){
        int arr[26]={0};
        for(char &ch : s1 ){
            if(arr[ch-'a']>0)
                return true;
            arr[ch-'a']++;
        } 
        for(char &ch : s2){
            if(arr[ch-'a']>0)return true;
        }return false;
        
    }
    int solve(int i,vector<string>& arr ,string temp,int n){
        if(i>=n)
            return temp.length();
        
        int ex=0;
        int in=0;
        if(hasDuplicate(arr[i],temp))
            ex=solve(i+1,arr,temp,n);
        else{
            ex=solve(i+1,arr,temp,n);
            in=solve(i+1,arr,temp+arr[i],n);
        }return max(ex,in);
       
    }
    int maxLength(vector<string>& arr) {
        string temp="";
        int n=arr.size();
        int i=0;
        return solve(0,arr,temp,n);
    }
};
