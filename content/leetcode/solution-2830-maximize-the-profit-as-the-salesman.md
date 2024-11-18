
+++
authors = ["grid47"]
title = "Leetcode 2830: Maximize the Profit as the Salesman"
date = "2024-01-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2830: Maximize the Profit as the Salesman in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Dynamic Programming","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "lrZM1nLXcmc"
img_src = ""
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2830.md" >}}
---
{{< youtube lrZM1nLXcmc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2831: Find the Longest Equal Subarray](https://grid47.xyz/leetcode/solution-2831-find-the-longest-equal-subarray/) |
| --- |
