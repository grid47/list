class Solution {
public:
    
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
        
        int n = r1.size();

        vector<vector<int>> ans;
        
        for(int i = 0; i < n; i++) {
            ans.push_back({r1[i] - r2[i], r1[i], r2[i]});
        }
        sort(ans.begin(), ans.end(), greater<vector<int>>());
        
        int res = 0, i = 0;
        while(k--) {
            res += ans[i++][1];
        }
        while(i < n) res += ans[i++][2];
        return res;
    }
};