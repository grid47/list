
+++
authors = ["grid47"]
title = "Leetcode 1760: Minimum Limit of Balls in a Bag"
date = "2024-05-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1760: Minimum Limit of Balls in a Bag in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumSize(vector<int>& nums, int mxOps) {
        
        int l = 1, r = *max_element(nums.begin(), nums.end());
        // int total_bags = n + 2 * mxOps - 1;
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            int cnt = 0;
            for(int a: nums)
                cnt += (a - 1) / mid;
            if(cnt <= mxOps)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1760.md" >}}
---
{{< youtube znZ4wT1L8Y0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1763: Longest Nice Substring](https://grid47.xyz/leetcode/solution-1763-longest-nice-substring/) |
| --- |
