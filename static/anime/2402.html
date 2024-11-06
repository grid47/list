
bool cmp(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meets) {
        sort(meets.begin(), meets.end(), cmp);
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> rvd;
        
        priority_queue<int, vector<int>, greater<int>> free;
 
        vector<int> frq(n, 0);
        for(int i = 0; i < n; i++)
            free.push(i);
        
        for(auto &t : meets) {
            
            int s = t[0], e = t[1];
            
            while(!rvd.empty() && rvd.top().first <= s) {
                free.push(rvd.top().second);
                rvd.pop();
            }
            
            if(free.size() > 0) {
                int room = free.top();
                free.pop();
                rvd.push({e, room});
                frq[room]++;
            } else {
                
                long long newHalt = rvd.top().first + (e - s);
                
                int room = rvd.top().second;
                rvd.pop();
                rvd.push({newHalt, room});
                frq[room]++;
            }
            
        }

        int mxi = 0;
        for(int i = 0; i < n; i++) {
            if(frq[i] > frq[mxi])
                mxi = i;
        }
        return mxi;
    }
};