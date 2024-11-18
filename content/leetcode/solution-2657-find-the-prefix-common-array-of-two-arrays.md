
+++
authors = ["grid47"]
title = "Leetcode 2657: Find the Prefix Common Array of Two Arrays"
date = "2024-02-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2657: Find the Prefix Common Array of Two Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        set<int> a, b, c;
        int n = A.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            if(a.count(B[i])) {
                c.insert(B[i]);
            } 
            if(b.count(A[i])) {
                c.insert(A[i]);                
            } 
            if(A[i] == B[i]) {
                c.insert(A[i]);                
            }
            a.insert(A[i]);
            b.insert(B[i]);
            ans[i] = c.size();
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2657.md" >}}
---
{{< youtube wpffRfDOBSU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2658: Maximum Number of Fish in a Grid](https://grid47.xyz/leetcode/solution-2658-maximum-number-of-fish-in-a-grid/) |
| --- |
