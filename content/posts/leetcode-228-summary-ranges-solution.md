
+++
authors = ["grid47"]
title = "Leetcode 228: Summary Ranges"
date = "2024-10-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 228: Summary Ranges in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/summary-ranges/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/228.webp" 
    alt="A range of numbers with each segment gently highlighted, showing the summarized range."
    caption="Solution to LeetCode 228: Summary Ranges Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/228.md" >}}
---
{{< youtube ZHJDwbfqoa8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #229: Majority Element II](https://grid47.xyz/posts/leetcode-229-majority-element-ii-solution/) |
| --- |
