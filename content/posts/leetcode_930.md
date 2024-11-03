
+++
authors = ["Crafted by Me"]
title = "Leetcode 930: Binary Subarrays With Sum"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 930: Binary Subarrays With Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/binary-subarrays-with-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal -1);
    }
    
    int atmost(vector<int> &nums, int s) {
        if(s < 0) return 0;
        int res = 0, j = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            s -= nums[i];
            while(s < 0) s += nums[j++];
            res += (i - j + 1);
        }
        return res;
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/930.md" >}}
---
{{< youtube j4JDr4-jvo4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #931: Minimum Falling Path Sum](https://grid47.xyz/posts/leetcode_931) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

