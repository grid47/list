class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& ap) {
        int n = ap.size() + 1;
        map<int, vector<int>> mp;
        for(auto e : ap) {
            int u = e[0], v = e[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<int> ans;
        for(auto it: mp) {
            if(it.second.size() == 1) {
                ans.push_back(it.first);
                ans.push_back(it.second[0]);
                break;
            }
        }

        while(ans.size() < n) {
            auto tail = ans.back(), prv = ans[ans.size() - 2];
            auto &next = mp[tail];
            if(next[0] != prv)
                ans.push_back(next[0]);
            else
                ans.push_back(next[1]);
        }

        return ans;
    }

};