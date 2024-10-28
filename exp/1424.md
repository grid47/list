class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size(), n = nums[0].size(), mx = 0;
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < nums.size(); i++)
        for(int j = 0; j < nums[i].size(); j++) {
            mp[i + j].push_back(nums[i][j]);
            mx = max(mx, i + j);
        }

        vector<int> ans;
        for(int i = 0; i <= mx; i++) {
            for(auto x = mp[i].rbegin(); x != mp[i].rend(); x++)
            ans.push_back(*x);
        }
        return ans;
    }
};

/*
    Primary attempt can redirect to two pointer simulation
    But right attempt is, queueing over a map which shares same diagonals
*/