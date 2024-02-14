#include <bits/stdc++.h>
using namespace std;
vector<int> res;
vector<bool> isPrime;
void primeSieve() {
    int n=1e8+1;
    isPrime.assign(n+1,true);
    
    isPrime[0]=false;
    isPrime[1]=false;
    for (int i = 2; i*i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i*i; j <= n; j += i) {
                isPrime[j] = false;
                // divisors[j]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(isPrime[i]) res.push_back(i);
    }
    
}

int main() {
    int akv;
    cin >> akv;
    primeSieve();
    while (akv--) {
        int numbering;
        cin >> numbering;

      
        vector<int> resulting;
        if(numbering%2==0){
            for (int i = 0; i < numbering/2; i++) {
                resulting.push_back(res[i]);
                resulting.push_back(res[i]);
            }
        }
        
        else{
            resulting.push_back(1);
            for (int i = 0; i < numbering/2; i++) {
                resulting.push_back(res[i]);
                resulting.push_back(res[i]);
            }
        }
        for (int i = 0; i < numbering; i++) {
            cout << resulting[i] << " ";
        }

        cout << endl;
    }

    return 0;
}
