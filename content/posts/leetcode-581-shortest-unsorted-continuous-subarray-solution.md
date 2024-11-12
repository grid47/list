
+++
authors = ["grid47"]
title = "Leetcode 581: Shortest Unsorted Continuous Subarray"
date = "2024-09-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 581: Shortest Unsorted Continuous Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Stack","Greedy","Sorting","Monotonic Stack"]
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
{{< youtube NzVaNmqPaSo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #583: Delete Operation for Two Strings](https://grid47.xyz/posts/leetcode-583-delete-operation-for-two-strings-solution/) |
| --- |
