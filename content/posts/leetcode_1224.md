
+++
authors = ["Crafted by Me"]
title = "Leetcode 1224: Maximum Equal Frequency"
date = "2021-06-27"
description = "In-depth solution and explanation for Leetcode 1224: Maximum Equal Frequency in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-equal-frequency/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        
        map<int, int> frq, cnt;
        int mx = 0, res = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            
            int f =  ++cnt[nums[i]];
            frq[f - 1]--;
            frq[f]++;
            
            mx = max(mx, cnt[nums[i]]);
            
            if((mx * frq[mx] == i) || ((mx - 1) * (frq[mx - 1] + 1) == i) || (mx == 1))
                res = i + 1;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1224.md" >}}
---


| Next : [LeetCode #1225: Report Contiguous Dates](grid47.xyz/leetcode_1225) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

