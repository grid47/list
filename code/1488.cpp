class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        set<int> dry;
        unordered_map<int, int> mp;
        
        int n = rains.size();
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            if(rains[i] == 0) {
                dry.insert(i);
                ans.push_back(1);
            } else {
                int lake = rains[i];
                
                if(mp.count(lake)) {
                    
                    auto it = dry.lower_bound(mp[lake]);
                    if(it == dry.end()) return {};
                    
                    ans[*it] = lake;
                    dry.erase(*it);
                }
                mp[lake] = i;
                ans.push_back(-1);
            }
        }

        return ans;
    }
};