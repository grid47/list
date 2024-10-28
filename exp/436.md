class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& iv) {
        map<int, int> mk;
        
        int n = iv.size();
        for(int i = 0; i < n; i++)
            mk[iv[i][0]] = i;
        
        vector<int> ans(n, -1);
        for(int j = 0; j < n; j++) {
            auto i= iv[j];
            if(mk.lower_bound(i[1]) != end(mk))
                ans[j] = mk.lower_bound(i[1])->second;
        }
        
        return ans;
    }
};