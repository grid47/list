
+++
authors = ["Crafted by Me"]
title = "Leetcode 1793: Maximum Score of a Good Subarray"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1793: Maximum Score of a Good Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Stack","Monotonic Stack"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-score-of-a-good-subarray/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i = k, j = k, mini = nums[k], res = nums[k];
        
        int n = nums.size();

        while(i > 0 || j < n - 1) {
            
                 if(i == 0)                    j++;
            else if(j == n - 1)                i--;
            else if(nums[i - 1] < nums[j + 1]) j++;
            else                               i--;
            
            mini = min(mini, min(nums[i], nums[j]));
            res  = max(res, mini * (j - i + 1));
   
        }

        return res;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1793.md" >}}
---
{{< youtube _K7oyQlAjv4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1794: Count Pairs of Equal Substrings With Minimum Difference](https://grid47.xyz/posts/leetcode_1794) |
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
