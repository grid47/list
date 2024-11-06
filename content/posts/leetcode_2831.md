
+++
authors = ["Crafted by Me"]
title = "Leetcode 2831: Find the Longest Equal Subarray"
date = "2024-11-01"
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


---
{{< youtube UFCF01O7Yxk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2832: Maximal Range That Each Element Is Maximum in It](https://grid47.xyz/posts/leetcode_2832) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
