
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2536: Increment Submatrices by One"
date = "2017-11-19"
description = "Solution to Leetcode 2536"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

