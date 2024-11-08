class Solution {
public:
    int n;
    vector<vector<vector<int>>> mem;
    vector<int> nums;
    
    int dp(int idx, int fst, int cnt) {

        if(cnt == 0) return 0;
        if(idx >= n) return INT_MIN;
        if(mem[idx][cnt][fst + 1] != -1) return mem[idx][cnt][fst + 1];
        
        int ans = dp(idx + 1, fst, cnt);
        if((idx + 1)% n != fst) {
            ans = max(ans, dp(idx + 2, fst, cnt - 1) + nums[idx]);
        }

        return mem[idx][cnt][fst + 1] = ans;
    }
    
    int maxSizeSlices(vector<int>& nums) {
        this->n = nums.size();
        mem.resize(n, vector<vector<int>>(n/3 + 1, vector<int>(n + 1, -1)));
        this->nums = nums;
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
            res = max(res, dp(i + 2, i, n/3 - 1) + nums[i]);
        return res;
    }
};