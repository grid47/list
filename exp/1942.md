class Solution {
public:
    int smallestChair(vector<vector<int>>& a, int t) {
        int tt = a[t][0];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> reserve;
        priority_queue<int, vector<int>, greater<int>> avail;
        sort(a.begin(), a.end());
        for(auto &t : a) {
            
            while(!reserve.empty() && reserve.top().first <= t[0]) {
                
                avail.push(reserve.top().second);
                reserve.pop();
                
            }
            
            if(t[0] == tt) break;
            if (!avail.empty()) {
                
                reserve.push({t[1], avail.top()});
                             
               avail.pop();
                
            } else {
                
                reserve.push({t[1], reserve.size()});
                
            }
            
        }
        
        return avail.empty()? reserve.size() : avail.top();
        
    }
};