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
