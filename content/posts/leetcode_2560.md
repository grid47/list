
+++
authors = ["Crafted by Me"]
title = "Leetcode 2560: House Robber IV"
date = "2017-10-30"
description = "In-depth solution and explanation for Leetcode 2560: House Robber IV in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/house-robber-iv/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int n;
    vector<int> nums;
    vector<vector<vector<map<int, int>>>> memo;
    
    int dp(int idx, int k, bool prv, int mx) {
        if(idx == n) return (k > 0)? INT_MAX: mx;
        
        if(memo[idx][k][prv].count(mx)) return memo[idx][k][prv][mx];
        
        int ans = dp(idx + 1, k, false, mx);
        
        if(!prv) {
            int tmp = dp(idx + 1, k - 1 < 1? 0: k-1, true, mx == 0? nums[idx]: (mx > nums[idx]) ? mx: nums[idx]);
            ans = min(ans, tmp);            
        }

        return memo[idx][k][prv][mx] = ans;
    }
    
    int minCap(vector<int>& nums, int k) {
        this->nums = nums;
        n = nums.size();
        memo.resize(n, vector<vector<map<int, int>>>(n + 1, vector<map<int,int>>(2)));
        return dp(0, k, false, 0);
    }
    
    bool can(vector<int> &nums, int k, int mid) {
        int n = nums.size();
        int cnt = 0, take = true;
        for(int i = 0; i < n; i += 1) {
            if(nums[i] <= mid && take) {
                take = false;
                cnt++;
            } else if(!take) {
                take = true;
            }
            if(cnt >= k) return true;
        }
        cnt = 0, take = true;
        for(int i = 1; i < n; i += 2) {
            if(nums[i] <= mid && take) {
                take = false;
                cnt++;
            } else if(!take) {
                take = true;
            }
            if(cnt >= k) return true;
        }        
        return false;
    }
    
    int minCapability(vector<int>& nums, int k) {
        
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        int l = mn, r = mx, ans = mx;
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            // cout << mid << " " << can(nums, k, mid) << "\n";
            if(can(nums, k, mid)) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    }
};
{{< /highlight >}}


---


"| 2561: Rearranging Fruits |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

