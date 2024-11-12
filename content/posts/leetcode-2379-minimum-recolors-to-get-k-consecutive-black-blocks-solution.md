
+++
authors = ["grid47"]
title = "Leetcode 2379: Minimum Recolors to Get K Consecutive Black Blocks"
date = "2024-03-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2379: Minimum Recolors to Get K Consecutive Black Blocks in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sliding Window"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
int minimumRecolors(string blocks, int k) {
    int b = 0, mb = 0;
    for (int i = 0; i < blocks.size(); ++i) {
        b += blocks[i] == 'B';
        if (i >= k)
            b -= blocks[i - k] == 'B';
        mb = max(b, mb);
    }
    return k - mb;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2379.md" >}}
---
{{< youtube RRmSKRsT9tg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2380: Time Needed to Rearrange a Binary String](https://grid47.xyz/posts/leetcode-2380-time-needed-to-rearrange-a-binary-string-solution/) |
| --- |
