
+++
authors = ["grid47"]
title = "Leetcode 1748: Sum of Unique Elements"
date = "2024-05-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1748: Sum of Unique Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-unique-elements/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int sum= 0;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
        }
        for(int i=0; i<nums.size(); i++){
            if(mpp[nums[i]] <= 1)
                sum+= nums[i];
        }
        return sum;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1748.md" >}}
---
{{< youtube MXQyGU493vE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1749: Maximum Absolute Sum of Any Subarray](https://grid47.xyz/leetcode/solution-1749-maximum-absolute-sum-of-any-subarray/) |
| --- |
