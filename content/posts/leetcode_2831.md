
+++
authors = ["Yasir"]
title = "Leetcode 2831: Find the Longest Equal Subarray"
date = "2017-01-27"
description = "Solution to Leetcode 2831"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-longest-equal-subarray/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<vector<int>> grid(n + 1);

        int ans = 0;
        for(int i = 0; i < n; i++) {
            grid[nums[i]].push_back(i);
        }
                
        for(int e = 1; e <= n; e++) {
            
            if(grid[e].size() == 0) continue;
            
            int left = 0, right = 1, rm = 0;
            
            while(left < grid[e].size() && right < grid[e].size()) {
                rm += (grid[e][right] - grid[e][right - 1] - 1);
                if (rm <= k) {
                    ans = max(ans, 1 + (right - left));
                    right++;
                } else {
                    right++;
                    left++;
                    if(left < grid[e].size())
                    rm -= (grid[e][left] - grid[e][left - 1] - 1);
                }
            }
        }
        
        return max(ans, 1);
    }
};
{{< /highlight >}}

