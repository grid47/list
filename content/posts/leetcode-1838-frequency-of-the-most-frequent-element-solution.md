
+++
authors = ["grid47"]
title = "Leetcode 1838: Frequency of the Most Frequent Element"
date = "2024-05-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1838: Frequency of the Most Frequent Element in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Greedy","Sliding Window","Sorting","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxFrequency(vector<int>& A, int t) {
        int i = 0, j;
        long k = t;
        sort(A.begin(), A.end());
        for (j = 0; j < A.size(); ++j) {
            k += A[j];
            if (k < (long)A[j] * (j - i + 1))
                k -= A[i++];
        }
        return j - i;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1838.md" >}}
---
{{< youtube vgBrQ0NM5vE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1839: Longest Substring Of All Vowels in Order](https://grid47.xyz/posts/leetcode-1839-longest-substring-of-all-vowels-in-order-solution/) |
| --- |
