
+++
authors = ["grid47"]
title = "Leetcode 2541: Minimum Operations to Make Array Equal II"
date = "2024-02-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2541: Minimum Operations to Make Array Equal II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-make-array-equal-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k == 0) {
        for(int i = 0; i < nums1.size(); i++) {
            if(nums1[i] != nums2[i]) return -1;
        }
            return 0;
        }
        for(int i = 0; i < nums1.size(); i++) {
            nums1[i] -= nums2[i];
            if(nums1[i] % k != 0) return -1;
        }
        cout << "hi";
        long long res = 0, sum = 0;
        for(int i = 0; i < nums1.size(); i++) {
            cout << nums1[i] << " ";
            if(nums1[i] > 0) res += nums1[i] / k;
            sum += nums1[i];
        }
        if(sum != 0) return -1;
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2541.md" >}}
---
{{< youtube k9jEPl5tC0s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2542: Maximum Subsequence Score](https://grid47.xyz/posts/leetcode-2542-maximum-subsequence-score-solution/) |
| --- |
