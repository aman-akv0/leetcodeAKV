#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n ;
        vector<int>aman(n);
        for(int i=0; i<n; i++){
            cin >> aman[i];
        }
        string res="";
        string str="abcdefghijklmnopqrstuvwxyz";
        unordered_map<int, int>mp;
        for(int i:aman){
            mp[i]++;
            res+=str[mp[i]-1];
        }
        cout << res << endl;
    }
    
}
