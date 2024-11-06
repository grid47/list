class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        vector<pair<int, int>> arr;
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums[i].size(); j++) {
                arr.push_back({nums[i][j], i});
            }
        }
        int k = nums.size();
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        int cnt = 0;
        int j = 0;
        int n = arr.size();
        vector<int> ans = {-100000, 100000};
        for(int i = 0; i < n; i++) {
            mp[arr[i].second]++;
            if(mp[arr[i].second] == 1) cnt++;
            if(cnt == k) {
                while(mp[arr[j].second] > 1) {
                    mp[arr[j].second]--;
                    j++;
                }                
                if(arr[i].first - arr[j].first < ans[1] - ans[0]) {
                    ans = {arr[j].first, arr[i].first};
                }
            }
        }
        return ans;
    }
};