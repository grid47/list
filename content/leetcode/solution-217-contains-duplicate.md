
+++
authors = ["grid47"]
title = "Leetcode 217: Contains Duplicate"
date = "2024-10-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 217: Contains Duplicate in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/contains-duplicate/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/217.webp" 
    alt="A set of numbers gently rearranging, with duplicates softly fading out and unique ones glowing."
    caption="Solution to LeetCode 217: Contains Duplicate Problem"
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
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> ma;
        for(int x: nums)
            if(ma.count(x)) return true;
        else ma[x] = 1;
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/217.md" >}}
---
{{< youtube SFMCxqSeM94 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #225: Implement Stack using Queues](https://grid47.xyz/leetcode/solution-225-implement-stack-using-queues/) |
| --- |
