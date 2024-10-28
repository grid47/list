class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int bit) {
        int ui = 0;
        for(int x : nums)
            ui ^= x;
        int msk = (1 << bit) - 1;
        
        
        

        
        int res = ui ^ msk;
        vector<int> ans;
        ans.push_back(res);
        while(nums.size() > 1) {
            
            res ^= nums.back();
            nums.pop_back();
            ans.push_back(res);
            
        }
        return ans;
    }
};