class Solution {
public:
    int sumdig(int num) {
        int temp = 0, res = 0;
        while (num != 0) {
            temp = num % 10;
            res = res + temp;
            num = num / 10;
        }
        return res;
    }

    int addDigits(int num) {
        while (sumdig(num) >= 10) {
            num = sumdig(num);
        }
        return sumdig(num);
    }
};
// class Solution {
// public:
//     int addDigits(int num) {
//       int sum=0;
//         while(num)
//         {
//             sum+=(num%10);
//             num/=10;
//         }
//         if(sum<10)
//             return sum;
//         else
//             return addDigits(sum);
//     }
// };
