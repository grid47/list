
+++
authors = ["grid47"]
title = "Leetcode 2529: Maximum Count of Positive Integer and Negative Integer"
date = "2024-02-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2529: Maximum Count of Positive Integer and Negative Integer in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "4uhvXmOp5Do"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] > 0) pos++;
            else if(nums[i] < 0) neg++;
        return max(pos, neg);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2529.md" >}}
---
{{< youtube 4uhvXmOp5Do >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2530: Maximal Score After Applying K Operations](https://grid47.xyz/leetcode/solution-2530-maximal-score-after-applying-k-operations/) |
| --- |
