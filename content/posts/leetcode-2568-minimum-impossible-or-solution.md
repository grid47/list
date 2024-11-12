
+++
authors = ["grid47"]
title = "Leetcode 2568: Minimum Impossible OR"
date = "2024-02-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2568: Minimum Impossible OR in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation","Brainteaser"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-impossible-or/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        set<int> cnt;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            cnt.insert(nums[i]);
        }
        int ret = 1;
        while(cnt.count(ret)) {
            ret *= 2;
        }
        // to create all the numbers till a positive integer
        // presents of all the powers of 2s below it are mandatory.
        return ret;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2568.md" >}}
---
{{< youtube ofCTBFFzB2Q >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2570: Merge Two 2D Arrays by Summing Values](https://grid47.xyz/posts/leetcode-2570-merge-two-2d-arrays-by-summing-values-solution/) |
| --- |
