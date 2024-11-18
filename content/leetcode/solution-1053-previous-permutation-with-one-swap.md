
+++
authors = ["grid47"]
title = "Leetcode 1053: Previous Permutation With One Swap"
date = "2024-07-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1053: Previous Permutation With One Swap in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "x_y3nIsbENM"
img_src = ""
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1054: Distant Barcodes](https://grid47.xyz/leetcode/solution-1054-distant-barcodes/) |
| --- |
