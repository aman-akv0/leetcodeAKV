class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> que;
        for(int i=1; i<=9;i++){
            que.push(i);
        }
        vector<int> res;
        while(!que.empty()){
            int temp=que.front();
            que.pop();
            if(temp>=low && temp<=high){
                res.push_back(temp);
            }
            int lastDigit=temp%10;
            if(lastDigit+1<=9){
                temp=temp*10+(lastDigit+1);
                que.push(temp);
            }
        }
        return res;
        
    }
};




or





   vector<int> sequentialDigits(int low, int high) {
        vector<int> allPossible = {12, 23, 34, 45, 56, 67, 78, 89,
                          123, 234, 345, 456, 567, 678, 789,
                          1234, 2345, 3456, 4567, 5678, 6789,
                          12345, 23456, 34567, 45678, 56789,
                          123456, 234567, 345678, 456789,
                          1234567, 2345678, 3456789,
                          12345678, 23456789,
                          123456789};
        
        vector<int> result;
        
        int n = allPossible.size();
        
        for (int i = 0; i < n; i++) {
            if (allPossible[i] < low) continue;
            
            if (allPossible[i] > high) break;
            
            result.push_back(allPossible[i]);
        }
        return result;
    }
