// class Solution {
// public:
//     int timeRequiredToBuy(vector<int>& tic, int k) {
//         int n=tic.size();
//         queue<int> ticks;
//         for(int i=0;i<n;i++){
//             ticks.push(tic[i]);
//         }
//         int count=0;
        
//         while(!ticks.empty() && tic[k] > 0 && k){
//             if(ticks.front()-1 != 0)
//                 ticks.push(ticks.front()-1);
//             if(ticks.front()==tic[k])
//                 tic[k]=tic[k]-1;
//             ticks.pop();
//             count++;
            
//         }
//         return count;
//     }
// };

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0, i = 0;
        while (tickets[k]) {
            if (tickets[i] != 0) {
                ++ans;
                --tickets[i];
            }
            i = (i + 1) % tickets.size();
        }
        return ans;
    }
};
