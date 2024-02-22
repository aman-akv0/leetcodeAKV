// class Solution {
// public:
//     int findJudge(int n, vector<vector<int>>& trust) {
//         unordered_set<int>set;
//         unordered_set<int>set2;
//         for(auto &it:trust){
    
//             set.insert(it[0]);
//             set2.insert(it[1]);
//         }
//         if(trust.size()==0 && n==1 ) return 1;
//         if(set2.size()==2 && set.size()==2) return -1;
//         else{
//             for(auto it:set2){
//                 if(set.find(it)== set.end()) return it;
//             }return -1;
//         }
        
        
//     }
// };


// class Solution {
// public:
//     int findJudge(int n, vector<vector<int>>& trust) {
//         vector<int>indeg(n+1);
//         vector<int>outdeg(n+1);
//         for(auto &it : trust){
//             indeg[it[1]]++;
//             outdeg[it[0]]++;
//         }
//         for(int i=1;i<=n;i++){
//             if(indeg[i]==n-1 && outdeg[i]==0) return i;
//         }return -1;
        
//     }
// };


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>count(n+1);
        for(auto &it : trust){
            count[it[0]]--;
            count[it[1]]++;

        }
        for(int i=1;i<=n;i++){
            if(count[i]==n-1) return i;
        }return -1;
        
    }
};
