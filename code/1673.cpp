class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {

        vector<int> stk;
        for(int i = 0; i < nums.size(); i++) {

            while (!stk.empty()          &&
                 stk.back() > nums[i] &&
                (stk.size() + nums.size() - (i + 1)) >= k )
                stk.pop_back();

            if(stk.size() < k)
                stk.push_back(nums[i]);

        }
        
        return stk;
        
    }
};