class Solution {
public:

    // bool isUgly(int n) {
    //     if(n<=0) return false;
    //     while(n!=1){
    //         if(n%2==0){
    //             n/=2;
    //         }else if(n%3==0){
    //             n/=3;    
    //         }else if(n%5==0){
    //             n/=5;
    //         }
    //         else return false;
    //     }return true;
    // }

    int nthUglyNumber(int n) {
    //     int c=0;
    //     int i=1;
    //     while(c<n){
    //         if(isUgly(i)){
    //             c++;
    //             i++;
    //         }
    //     }return i-1;
    // }
    vector<int>arr(n+1);
    int a2,a3,a5;
    a2=a3=a5=1;
    arr[1]=1;
    for(int i=2; i<=n ; i++){
        int ug2= 2*arr[a2];
        int ug3= 3*arr[a3];
        int ug5= 5*arr[a5];
        int minUg = min({ug2,ug3,ug5});
        arr[i]=minUg;
        if(minUg==ug2)a2++;
        if(minUg==ug3)a3++;
        if(minUg==ug5)a5++;
    }
    
    return arr[n];
    }
};
