class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m= meetings.size();
        sort(meetings.begin(),meetings.end());
        vector<long long>lastAvailableAt(n,0);
        vector<int>roomUsed(n,0);
        
        
        for(vector<int> &meet : meetings){
            int start=meet[0];
            int end=meet[1];
            bool st=false;
            long long earlyTime=LLONG_MAX;
            int earlyroom=0;
            int duration=end-start;
            for(int room=0;room<n;room++){
                if(lastAvailableAt[room]<=start){
                    lastAvailableAt[room]=end;
                    roomUsed[room]++;
                    st=true;
                    break;
                }
                if(lastAvailableAt[room]<earlyTime){
                    earlyTime=lastAvailableAt[room];
                    earlyroom=room;
                }
            }if(!st){
                lastAvailableAt[earlyroom]+=duration;
                roomUsed[earlyroom]++;
            }
        }
        int res=-1;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(roomUsed[i]>maxi){
                maxi=roomUsed[i];
                res=i;
            }
        }return res;
    }
};
