class Solution {
public:
    int minDominoRotations(vector<int>& top, vector<int>& bottom) {
        map<int, int> mp;
        vector<int> tc(7, 0), uc(7, 0);
        int n = top.size();
        for(int i = 0; i < n; i++) {
            if(bottom[i] != top[i]) {
                mp[bottom[i]]++;
                mp[top[i]]++;
            } else mp[top[i]]++;

            uc[bottom[i]]++;
            tc[top[i]]++;
        }
        
        vector<int> opt;
        for(auto it: mp) {
            if(it.second == n)
                opt.push_back(it.first);
        }
        if(opt.empty()) return -1;
        
        int res = INT_MAX;
        for(int x: opt) {
            if(uc[x] == n || tc[x] == n) return 0;
            res = min(res, n - uc[x]);
            res = min(res, n - tc[x]);
        }
        return res;
    }
};