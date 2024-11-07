
+++
authors = ["Crafted by Me"]
title = "Leetcode 2657: Find the Prefix Common Array of Two Arrays"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2658: Maximum Number of Fish in a Grid](https://grid47.xyz/posts/leetcode_2658) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
