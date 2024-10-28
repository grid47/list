class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
            pq.push({nums[i], i});
        
        while(!pq.empty()) {
            while(!pq.empty() && mp.count(pq.top()[1])) pq.pop();
            if(!pq.empty()) {
                score += pq.top()[0];
                mp[pq.top()[1]] = true;
                mp[pq.top()[1] + 1] = true;
                mp[pq.top()[1] - 1] = true;                
                pq.pop();
            }
        }
        return score;
    }
};