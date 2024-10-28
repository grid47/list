class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        long long ans = 0;
        while(k--) {
            int tmp = pq.top();
            cout << tmp << " ";
            ans += tmp;
            pq.pop();
            pq.push(ceil(tmp/3.0));
            
        }
        return ans;
    }
};