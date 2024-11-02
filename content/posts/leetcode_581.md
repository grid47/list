
+++
authors = ["Crafted by Me"]
title = "Leetcode 581: Shortest Unsorted Continuous Subarray"
date = "2022-03-31"
description = "Solution to Leetcode 581"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int mn = 0, mx = 0, n = nums.size();
        
        
        vector<pair<int, int>> tmp(n);
        
        for(int i = 0; i < n; i++)
        tmp[i] = make_pair(nums[i], i);
        
        sort(tmp.begin(), tmp.end());
        
        int start = -1, end = -1;
        
        for(int i = 0; i < n; i++) {
            if(i != tmp[i].second)
                if (start == -1) start = i;
                else               end = i;
        }
        
        if(start == -1) return 0;
        return end - (start - 1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/581.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

