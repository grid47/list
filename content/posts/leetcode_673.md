
+++
authors = ["Crafted by Me"]
title = "Leetcode 673: Number of Longest Increasing Subsequence"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 673: Number of Longest Increasing Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int res = 0, n = nums.size(), max_len = 0;
        vector<int> len(n, 0), cnt(n, 0);
        
        for(int i = 0; i < n; i++) {
            cnt[i] = 1;
            len[i] = 1;
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    if(len[j] + 1 == len[i]) cnt[i] += cnt[j];
                    if(len[j] + 1 >  len[i]) {
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    }
                }   
            }
            if(max_len == len[i]) res += cnt[i];
            if(max_len < len[i]) {
                res = cnt[i];
                max_len = len[i];
            }
            
        }
        
        return res;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/673.md" >}}
---
{{< youtube Tuc-rjJbsXU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #674: Longest Continuous Increasing Subsequence](https://grid47.xyz/posts/leetcode_674) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

