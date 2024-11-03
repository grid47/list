
+++
authors = ["Crafted by Me"]
title = "Leetcode 2718: Sum of Matrix After Queries"
date = "2017-05-25"
description = "In-depth solution and explanation for Leetcode 2718: Sum of Matrix After Queries in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2719: Count of Integers](https://grid47.xyz/posts/leetcode_2719) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

