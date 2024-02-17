// class Solution {
// public:
//     int n;
//     int solve(vector<int>& h, int b, int l,int i){
//         if(i==n-1) return 0;
//         int ans=0;
        
//         if(h[i+1]<=h[i]) return 1+solve(h,b,l,i+1);
//         else{
//             int bricks=0;
//             int ladders=0;
//             int diff=h[i+1]-h[i];
//             if(b >= diff){
                
//                 bricks= 1+solve(h,b-diff,l,i+1);
//             }
//             if(l>0){
//                 ladders=1+solve(h,b,l-1,i+1);
//             }
//             return max(bricks,ladders);
//         }return -1;
        
//     }
//     int furthestBuilding(vector<int>& h, int b, int l) {
//         n = h.size();
//         int i=0;
//         return solve(h,b,l,i);
//     }
// };


class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        int n = h.size();
        priority_queue<int>que;
        int i=0;
        for( ; i<n-1;i++){
            int diff=h[i+1]-h[i];
            if(h[i]>=h[i+1]) continue;

            if(b>=diff){
                b-=diff;
                que.push(diff);

            }else if(l>0){
                if(!que.empty()){
                    int maxreq = que.top();
                    if(maxreq > diff){
                        b+=maxreq;
                        que.pop();
                        b-=diff;
                        que.push(diff);
                        l--;
                    }else l--;
                }else l--;
            }else{
                break;
            }
        }return i;
    }
};
