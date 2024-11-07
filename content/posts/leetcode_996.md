
+++
authors = ["Crafted by Me"]
title = "Leetcode 996: Number of Squareful Arrays"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 996: Number of Squareful Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Dynamic Programming","Backtracking","Bit Manipulation","Bitmask"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-squareful-arrays/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        sort(A.begin(), A.end());
        int ans = 0;
        pmt(A, 0, ans);
        return ans;
    }
    void pmt(vector<int> &A, int idx, int& ans) {
        if (idx >= A.size()) {
            ++ans;
        }
        unordered_set<int> seen; 
        for (int i = idx; i < A.size(); ++i) {
            if (seen.find(A[i])!=seen.end()) continue;
            seen.insert(A[i]);
            swap(A[i], A[idx]);
            if ((idx == 0) || (idx > 0 && isSquare(A[idx] + A[idx - 1]))) {
                pmt(A, idx + 1, ans);
            }
            swap(A[i], A[idx]);            
        }
    }
    bool isSquare(int v) {
        int r = sqrt(v);
        return r * r == v;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/996.md" >}}
---
{{< youtube cCYbMg7TZbY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #997: Find the Town Judge](https://grid47.xyz/posts/leetcode_997) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
