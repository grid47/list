
+++
authors = ["grid47"]
title = "Leetcode 1646: Get Maximum in Generated Array"
date = "2024-05-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1646: Get Maximum in Generated Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "dy15GcCBdOc"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/get-maximum-in-generated-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
    public int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        int[] nums = new int[n + 1];
        nums[0] = 0;
        nums[1] = 1;
        int max = 1;
        for(int i = 1; 2 * i + 1 < n + 1; i++) {
            nums[2 * i]     = nums[i];
            max = Math.max(nums[2 * i],     max);
            nums[2 * i + 1] = nums[i] + nums[i + 1];
            max = Math.max(nums[2 * i + 1], max);
        }
        return max;
    }
}
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1646.md" >}}
---
{{< youtube dy15GcCBdOc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1647: Minimum Deletions to Make Character Frequencies Unique](https://grid47.xyz/leetcode/solution-1647-minimum-deletions-to-make-character-frequencies-unique/) |
| --- |
