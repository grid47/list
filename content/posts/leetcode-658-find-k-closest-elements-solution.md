
+++
authors = ["grid47"]
title = "Leetcode 658: Find K Closest Elements"
date = "2024-09-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 658: Find K Closest Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sliding Window","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-k-closest-elements/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() -k;
        while(l < r) {
            int m = (l + r) / 2;
            if(x - arr[m] > arr[m + k] - x) {
                l = m + 1;
            } else r = m;
        }
        
        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/658.md" >}}
---
{{< youtube o-YDQzHoaKM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #659: Split Array into Consecutive Subsequences](https://grid47.xyz/posts/leetcode-659-split-array-into-consecutive-subsequences-solution/) |
| --- |
