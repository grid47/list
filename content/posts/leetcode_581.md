
+++
authors = ["Yasir"]
title = "Leetcode 581: Shortest Unsorted Continuous Subarray"
date = "2023-03-26"
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

{{< highlight html >}}
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

