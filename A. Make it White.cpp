#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string str;
        cin >> n >> str;
        int a=0,b=0;
        for(int i=0; i<n;i++){
            if(str[i]=='B'){
                a=i;
                break;
            }
        }
        for(int i=n; i>=0;i--){
            if(str[i]=='B'){
                b=i;
                break;
            }
        }
        cout<<(b-a)+1<<endl;
    }
    
}
