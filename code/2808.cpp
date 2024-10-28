class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        
        int n = nums.size();
        map<int, vector<int>> pos;
        
        for(int i = 0; i < n; i++)
            pos[nums[i]].push_back(i);
        
        int res = INT_MAX;
        
        for(auto [key, val]: pos) {
            int sec = 0;
            val.push_back(val[0] + n);
            
            for(int i = 1; i < val.size(); i++) {
                sec = max(sec, (val[i] - val[i - 1])/ 2);
            }
            
            res = min(res, sec);
        }
        return res;
    }
};