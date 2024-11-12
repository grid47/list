
+++
authors = ["grid47"]
title = "Leetcode 2161: Partition Array According to Given Pivot"
date = "2024-04-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2161: Partition Array According to Given Pivot in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/partition-array-according-to-given-pivot/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int low = 0, same = 0, high;
        for(auto num: nums) {
            if(num < pivot) low++;
            else if(num == pivot) same++;
        }
        high = low + same;
        same = low;
        low = 0;
        vector<int> res(nums.size(), 0);
        for(auto num: nums) {
            if(num < pivot) res[low++] = num;
            else if(num == pivot) res[same++] = num;
            else res[high++] = num;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2161.md" >}}
---
{{< youtube Ie7eN2NAa6w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2164: Sort Even and Odd Indices Independently](https://grid47.xyz/posts/leetcode-2164-sort-even-and-odd-indices-independently-solution/) |
| --- |
