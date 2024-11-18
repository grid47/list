
+++
authors = ["grid47"]
title = "Leetcode 1752: Check if Array Is Sorted and Rotated"
date = "2024-05-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1752: Check if Array Is Sorted and Rotated in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                cnt++;
            }
        }
        if(nums[n-1]>nums[0]){
            cnt++;
        }
        return cnt<=1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1752.md" >}}
---
{{< youtube uoEJ3FXr56w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1753: Maximum Score From Removing Stones](https://grid47.xyz/leetcode/solution-1753-maximum-score-from-removing-stones/) |
| --- |
