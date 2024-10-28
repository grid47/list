
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2643: Row With Maximum Ones"
date = "2017-08-04"
description = "Solution to Leetcode 2643"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/row-with-maximum-ones/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int mx = 0, idx = 0;
        for(int i = 0; i < m; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++)
                if(mat[i][j]) cnt++;
            if(cnt > mx) {
                idx = i;
                mx = cnt;
            }
        }
        return vector<int>{idx, mx};
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

