#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> n >> m >> k ;
        int c1=0;
        int c2=0;
        vector<int> aman(n);
        vector<int> simmo(m);
        for(int i=0; i<n; i++){
            cin >> aman[i];
        }
        for(int i=0; i<m; i++){
            cin >> simmo[i];
        }
        // int div = k/2;
        
        unordered_set<int> set1;
        unordered_set<int> set2;
        for(int i=0; i<n; i++){
            if(aman[i] <= k) {
                set1.insert(aman[i]);
            }
        }
        for(int i=0; i<m; i++){
            if(simmo[i] <= k) {
                set2.insert(simmo[i]);
            }
        }
        int temp=set1.size();
        set1.insert(set2.begin(), set2.end()); 
        
        if(set1.size() < k || set2.size() < k/2 || temp < k/2){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}
