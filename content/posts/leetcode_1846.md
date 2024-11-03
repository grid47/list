
+++
authors = ["Crafted by Me"]
title = "Leetcode 1846: Maximum Element After Decreasing and Rearranging"
date = "2019-10-14"
description = "In-depth solution and explanation for Leetcode 1846: Maximum Element After Decreasing and Rearranging in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        
        if(arr[0] != 1) arr[0] = 1;
        
        int n = arr.size();
        
        for(int i = 1; i < n; i++) {
            if(arr[i] - arr[i - 1] > 1) arr[i] = arr[i - 1] + 1;
        }
        return arr[n - 1];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1846.md" >}}
---
{{< youtube o_hVl8IXuIE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1847: Closest Room](https://grid47.xyz/posts/leetcode_1847) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

