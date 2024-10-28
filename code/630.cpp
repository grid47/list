class Solution {
public:
    int scheduleCourse(vector<vector<int>>& nums) {
        
        priority_queue<int> pq;
        
        sort(nums.begin(), nums.end(), [&](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
        
        int sum = 0;
        for(auto it: nums) {
            sum += it[0];
            pq.push(it[0]);
            if(sum > it[1]) {
                sum -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};