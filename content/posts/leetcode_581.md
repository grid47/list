
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 581: Shortest Unsorted Continuous Subarray"
date = "2023-03-29"
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

