class Solution {
public:
    
    bool can(vector<int>& candies, long long kids, int per) {
        long long cnt = 0;
        for(int i = 0; i < candies.size(); i++) {
            if(candies[i] < per) continue;
            
            int tmp = candies[i];
            cnt+= tmp/per;
        }
        
        return cnt >= kids;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        
        long long sum = accumulate(candies.begin(), candies.end(), 0L);
        if(sum < k) return 0;
        
        int l = 1, r = *max_element(candies.begin(), candies.end());
        int ans = 0;
        
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            if(can(candies, k, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};