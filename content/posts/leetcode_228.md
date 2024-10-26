
+++
authors = ["Yasir"]
title = "Leetcode 228: Summary Ranges"
date = "2024-03-13"
description = "Solution to Leetcode 228"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/summary-ranges/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        const int size_n = nums.size();
        vector<string> res;
        if ( 0 == size_n) return res;
        for (int i = 0; i < size_n;) {
            int start = i, end = i;
            while (end + 1 < size_n && nums[end+1] == nums[end] + 1) end++;
            if (end > start) res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            else res.push_back(to_string(nums[start]));
            i = end+1;
        }
        return res;
        
    }
};
{{< /highlight >}}

