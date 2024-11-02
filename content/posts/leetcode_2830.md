
+++
authors = ["Crafted by Me"]
title = "Leetcode 2830: Maximize the Profit as the Salesman"
date = "2016-02-02"
description = "Solution to Leetcode 2830"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximize-the-profit-as-the-salesman/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int n;
    vector<int> mem;
    vector<vector<int>> nums;
    
    int bs(int x) {
        int ans = n;
        int l = 0, r = n - 1;
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            if(nums[mid][0] > x) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    }
    
    int dp(int idx) {
        // cout << n;
        if(idx >= n) return 0;
        
        if(mem[idx] != -1) return mem[idx];
        
        int ans = dp(idx + 1);
        
        int nxt = bs(nums[idx][1]);
        // cout << nxt;

        ans = max(ans, dp(nxt) + nums[idx][2]);
        
        return mem[idx] = ans;
    }
    
    int maximizeTheProfit(int x, vector<vector<int>>& nums) {
        n = nums.size();
        mem.resize(n, -1);
        sort(nums.begin(), nums.end());
        this->nums = nums;
        return dp(0);
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

