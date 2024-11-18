
+++
authors = ["grid47"]
title = "Leetcode 1043: Partition Array for Maximum Sum"
date = "2024-07-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1043: Partition Array for Maximum Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "kWhy4ZUBdOY"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/partition-array-for-maximum-sum/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> memo;
    vector<int> arr;
    int k;
    int dp(int i) {
        if(i == arr.size()) return 0;
        if(memo[i] != -1) return memo[i];
        int res = 0, mx = 0;
        for(int j = i; j < min((int)arr.size(), i + k); j++) {
            mx = max(mx, arr[j]);
            res = max(res, mx * (j - i + 1) + dp(j + 1));
        }
        return memo[i] = res;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        this->arr = arr;
        this->k = k;
        memo.resize(arr.size(), -1);
        return dp(0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1043.md" >}}
---
{{< youtube kWhy4ZUBdOY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1046: Last Stone Weight](https://grid47.xyz/leetcode/solution-1046-last-stone-weight/) |
| --- |
