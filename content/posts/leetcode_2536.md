
+++
authors = ["Crafted by Me"]
title = "Leetcode 2536: Increment Submatrices by One"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2536: Increment Submatrices by One in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/increment-submatrices-by-one/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        for(int i = 0; i < q.size(); i++) {
            auto it = q[i];
            for(int j = q[i][0]; j <= q[i][2]; j++) {
                ans[j][q[i][1]] += 1;
                if(q[i][3] < n - 1)
                    ans[j][q[i][3] + 1] -=1;
            }
        }
        
        for(int i = 0; i < n; i++)
        for(int j = 1; j < n; j++)
            ans[i][j] += ans[i][j - 1];
        
        return ans;
        
    }
};
{{< /highlight >}}


---
{{< youtube K4SJb0I-_hw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2537: Count the Number of Good Subarrays](https://grid47.xyz/posts/leetcode_2537) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
