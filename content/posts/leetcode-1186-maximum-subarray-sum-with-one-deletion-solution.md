
+++
authors = ["grid47"]
title = "Leetcode 1186: Maximum Subarray Sum with One Deletion"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1186: Maximum Subarray Sum with One Deletion in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int res = 0, n = arr.size();
        int curr_mx = arr[0], overall_mx = arr[0];
        vector<int> f(n), b(n);
        f[0] = arr[0];
        for(int i = 1; i < n; i++) {
            curr_mx = max(arr[i], curr_mx + arr[i]);
            overall_mx = max(curr_mx, overall_mx);
            f[i] = curr_mx;
        }
        
        curr_mx = overall_mx = b[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; i--){
            curr_mx = max(arr[i], curr_mx + arr[i]);
            overall_mx = max(overall_mx, curr_mx);
            b[i] = curr_mx;
        }
        
        res = overall_mx;
        for(int i = 1; i < n-1; i++) {
            res = max(res, f[i-1]+b[i+1]);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1186.md" >}}
---
{{< youtube EWCdm1cKtrA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1187: Make Array Strictly Increasing](https://grid47.xyz/posts/leetcode-1187-make-array-strictly-increasing-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
