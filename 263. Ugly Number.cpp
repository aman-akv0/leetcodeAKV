#include <vector>

class Solution {
public:
    vector<int> lpf(int n) {
        vector<int> v;
        while (n % 2 == 0) {
            v.push_back(2);
            n /= 2;
        }
        for (int i = 3; i <= sqrt(n); i += 2) {
            while (n % i == 0) {
                v.push_back(i);
                n /= i;
            }
        }
        if (n > 2) v.push_back(n);
        return v;
    }

    bool isUgly(int n) {
        if (n <= 0) {
            return false; 
        }

        vector<int> v = lpf(n);

        for (int i = 0; i < v.size(); i++) {
            if (v[i] != 2 && v[i] != 3 && v[i] != 5) {
                return false;
            }
        }
        return true;
    }
};



or


bool isUgly(int n) {
        if(n<=0) return false;
        while(n!=1){
            if(n%2==0){
                n/=2;
            }else if(n%3==0){
                n/=3;    
            }else if(n%5==0){
                n/=5;
            }
            else return false;
        }return true;
    }
