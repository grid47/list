class Solution {
public:
    vector<pair<int, int>> nums;
    int n;
    priority_queue<int, vector<int>, greater<int>> pq;

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        n = nums2.size(); 
        for(int i = 0; i < n; i++)
            nums.push_back({nums2[i], nums1[i]});
        
        sort(nums.rbegin(), nums.rend());
        
        long long score = 0, sum = 0;

        for(auto& [n2, n1]: nums) {
            
            pq.push(n1);
            sum += n1;
            
            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            
            if(pq.size() == k)
            score = max(score, sum * n2);
        }

        return score;
    }
};