
+++
authors = ["grid47"]
title = "Leetcode 1850: Minimum Adjacent Swaps to Reach the Kth Smallest Number"
date = "2024-05-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1850: Minimum Adjacent Swaps to Reach the Kth Smallest Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int getMinSwaps(string num, int k) {
        string og = num;
        while(k--) {
            next_permutation(num.begin(), num.end());
        }
        return steps(og, num);
    }

    int steps(string s1, string s2) {
        int sz = s1.size();
        int i = 0, j = 0;
        int res = 0;

        while(i < sz) {
            j = i;
            while(s1[i] != s2[j]) j++;
            while(i < j) {
                swap(s2[j], s2[j - 1]);
                j--;
                res++;
            }
            i++;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1850.md" >}}
---
{{< youtube _83XSvgd_is >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1854: Maximum Population Year](https://grid47.xyz/posts/leetcode-1854-maximum-population-year-solution/) |
| --- |
