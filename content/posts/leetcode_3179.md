
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 3179: Find the N-th Value After K Seconds"
date = "2016-02-16"
description = "Solution to Leetcode 3179"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-n-th-value-after-k-seconds/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    int valueAfterKSeconds(int n, int k) {
        vector<vector<long>> mtx(k + 1, vector<long>(n, 1));
        for(int i = 1; i <= k; i++) {
            for(int j = 1; j < n; j++) {
                mtx[i][j] = (mtx[i - 1][j] + mtx[i][j - 1]) % mod;   
            }
        }
        return mtx[k][n - 1];
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

