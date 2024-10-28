class Solution {
public:
    bool can(vector<int> nums, int mid, int k) {
        int cnt = 1, n = nums.size();
        int i = 1;
        int prv = nums[0];
        while(i < n) {
            if(nums[i] - prv >= mid) {
                cnt++;
                prv = nums[i];
            }
            if(cnt >= k) return true;
            i++;
        }
        return false;
    }
    
    int maximumTastiness(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int l = 0, r = nums[n - 1] - nums[0];
        int ans = r;
        
        while(l <= r) {
            
            int mid = l + (r - l + 1) / 2;
            // cout << mid << " " << can(nums, mid, k) << "\n";
            if(can(nums, mid, k)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
            
        }
        
        return ans;
    }
};