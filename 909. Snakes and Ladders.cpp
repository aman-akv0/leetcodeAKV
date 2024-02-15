class Solution {
public:
    int n;
    pair<int,int>getcor(int val){
        int ru=(val-1)/n;
        int rl=(n-1) - ru;
        int cl=(val-1)%n;
        if((n%2==1 && rl==1) || (n%2==0 && rl==0)){
            cl = (n-1) - cl;
        }return make_pair(rl,cl);
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        n=board.size();
        queue<int>que;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        visited[n-1][0]=true;
        que.push(1);
        int steps=0;
        while(!que.empty()){
            int p= que.size();
            while(p--){
                int x=que.front();
                que.pop();
                if(x==n*n) return steps;
                for(int k=1;k<=6;k++){
                    int val=x+k;
                    if(val>n*n) break;
                    pair<int,int>coord=getcor(val);
                    int r=coord.first;
                    int c=coord.second;
                    if(visited[r][c]==true) continue;
                    visited[r][c]=true;
                    if(board[r][c]==-1) que.push(val);
                    else que.push(board[r][c]);
                }
            }steps++;
        }return -1;
    }
};


// class Solution {
// public:
//     int n;
    
//     pair<int, int> getCoord(int s) {
//         int row = n-1-(s-1)/n;
        
//         int col = (s-1)%n;
        
//         if((n%2==1 && row%2==1)||(n%2==0 && row%2==0))
//             col = n-1-col;
        
//         return make_pair(row, col);
//     }
    
//     int snakesAndLadders(vector<vector<int>>& board) {
//         n = board.size();
        
//         int steps = 0;
//         queue<int> que;
        
//         vector<vector<bool>> visited(n, vector<bool>(n, false));
//         visited[n-1][0] = true;
        
//         que.push(1);
//         vector<bool> seen(n*n+1,false);
        
        
//         while(!que.empty()) {
            
//             int N = que.size();
//             while(N--) {
            
//                 int x = que.front();
//                 que.pop();

//                 if(x == n*n)
//                     return steps;

//                 for(int k = 1; k<=6; k++) {
//                     if(x+k > n*n)
//                         break;

//                     pair<int, int> coord = getCoord(x+k);
//                     int r = coord.first;
//                     int c = coord.second;
//                     if(visited[r][c] == true)
//                         continue;

//                     visited[r][c] = true;
//                     if(board[r][c] == -1)
//                         que.push(k+x);
//                     else {
//                         que.push(board[r][c]);
//                     }
//                 }
//             }
//             steps++;
//         }
        
//         return -1;
//     }
// };
