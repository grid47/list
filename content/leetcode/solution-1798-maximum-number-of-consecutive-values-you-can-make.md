
+++
authors = ["grid47"]
title = "Leetcode 1798: Maximum Number of Consecutive Values You Can Make"
date = "2024-05-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1798: Maximum Number of Consecutive Values You Can Make in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "3ONSGo28_Z0"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());

        int res = 1;
        for(int a: coins) {
            if(a > res) break;
            // with all the coins I have I can 
            // create upto res - 1,
            // with this a, I can make upto res + a - 1
            // so next target is res += a
            res += a;
        }

        return res;
    }

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1798.md" >}}
---
{{< youtube 3ONSGo28_Z0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1800: Maximum Ascending Subarray Sum](https://grid47.xyz/leetcode/solution-1800-maximum-ascending-subarray-sum/) |
| --- |
