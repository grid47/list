
+++
authors = ["grid47"]
title = "Leetcode 2866: Beautiful Towers II"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2866: Beautiful Towers II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/beautiful-towers-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& A) {
        int n = A.size();
        vector<long long> left(n), stack = {-1};
        long long res = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            while (stack.size() > 1 && A[stack.back()] > A[i]) {
                int j = stack.back();
                stack.pop_back();
                cur -= 1L * (j - stack.back()) * A[j];
            }
            cur += 1L * (i - stack.back()) * A[i];
            stack.push_back(i);
            left[i] = cur;
        }

        stack = {n};
        cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (stack.size() > 1 && A[stack.back()] > A[i]) {
                int j = stack.back();
                stack.pop_back();
                cur -= 1L * -(j - stack.back()) * A[j];
            }
            cur += 1L * -(i - stack.back()) * A[i];
            stack.push_back(i);
            res = max(res, left[i] + cur - A[i]);
        }

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2866.md" >}}
---
{{< youtube HZVMmKR0jZw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2869: Minimum Operations to Collect Elements](https://grid47.xyz/posts/leetcode-2869-minimum-operations-to-collect-elements-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}