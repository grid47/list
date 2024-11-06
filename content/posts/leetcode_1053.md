
+++
authors = ["Crafted by Me"]
title = "Leetcode 1053: Previous Permutation With One Swap"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1053: Previous Permutation With One Swap in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/previous-permutation-with-one-swap/description/)

---

**Code:**

{{< highlight cpp >}}

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int idx = -1, n = arr.size();
        for(int i = n - 1; i > 0; i--) {
            // cout<< arr[i] << " " << arr[i - 1] << '\n';
            if(arr[i] < arr[i - 1]) {
                idx = i - 1;
                break;
            }
        }
        // cout << idx;
        if(idx == -1) return arr;

        for(int i = n - 1; i > idx; i--) {
            if(arr[i] < arr[idx] && arr[i] != arr[i - 1]) {
                swap(arr[i], arr[idx]);
                break;
            }
        }
        return arr;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1053.md" >}}
---
{{< youtube x_y3nIsbENM >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1054: Distant Barcodes](https://grid47.xyz/posts/leetcode_1054) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

