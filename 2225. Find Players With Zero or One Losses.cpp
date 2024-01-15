#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> mat;
        set<int> winners, exactLosers;
        for (auto it : matches) {
            //mat[it[0]]++;
            winners.insert(it[0]);
            exactLosers.insert(it[1]);
            mat[it[1]]++;
        }

        vector<int> v1,v2;
        vector<vector<int>>ans;
        for (auto it : winners) {
            if(mat.find(it)==mat.end()){
                v1.push_back(it);
            }
            
        }
        for (auto it : exactLosers) {
            if(mat[it]==1){
                v2.push_back(it);
            }
            
        }
        ans.push_back(v1);
        ans.push_back(v2);

        return ans;
    }
};
