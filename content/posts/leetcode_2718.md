
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2718: Sum of Matrix After Queries"
date = "2017-05-22"
description = "Solution to Leetcode 2718"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-matrix-after-queries/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& q) {
        long long res = 0;

        int seen[2][10001] = {};
        int cnt[2] = {n, n};

        for(int i = q.size() - 1; i >= 0; i--) {
            
            int type = q[i][0], id = q[i][1], val = q[i][2];
            
            if(!seen[type][id]) {
                seen[type][id] = 1;
                res += val * cnt[!type];
                --cnt[type];
            }
            
        }

        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
