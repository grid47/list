
+++
authors = ["grid47"]
title = "Leetcode 2678: Number of Senior Citizens"
date = "2024-02-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2678: Number of Senior Citizens in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-senior-citizens/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(auto i : details) {
            if(i[11] - '0' > 6) count++;
            else if (i[11] - '0' == 6 && i[12] - '0' > 0) count++;
        }
        return count;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2678.md" >}}
---
{{< youtube l6_wwKzFmVo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2679: Sum in a Matrix](https://grid47.xyz/posts/leetcode-2679-sum-in-a-matrix-solution/) |
| --- |
