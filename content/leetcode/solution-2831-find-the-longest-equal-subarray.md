
+++
authors = ["grid47"]
title = "Leetcode 2831: Find the Longest Equal Subarray"
date = "2024-01-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2831: Find the Longest Equal Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-longest-equal-subarray/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2831.md" >}}
---
{{< youtube UFCF01O7Yxk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2833: Furthest Point From Origin](https://grid47.xyz/leetcode/solution-2833-furthest-point-from-origin/) |
| --- |
