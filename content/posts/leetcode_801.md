
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 801: Minimum Swaps To Make Sequences Increasing"
date = "2022-08-21"
description = "Solution to Leetcode 801"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int minSwap(vector<int>& n1, vector<int>& n2) {
        int n = n1.size();
        vector<vector<int>> res(n, vector<int>(2, 0));
        res[0][0] = 0;
        res[0][1] = 1;
        for(int i = 1; i < n; i++) {
            bool bothInc    = n1[i - 1] < n1[i] && n2[i - 1] < n2[i];
            bool crossInc   = n1[i - 1] < n2[i] && n2[i - 1] < n1[i];
            
            if(bothInc && crossInc) {
                res[i][0] = min(res[i - 1][0], res[i - 1][1]);
                res[i][1] = min(res[i - 1][0], res[i - 1][1]) + 1;                
            } else if(bothInc) {
                res[i][0] = res[i - 1][0];
                res[i][1] = res[i - 1][1] + 1;                                
            } else {
                res[i][0] = res[i - 1][1];
                res[i][1] = res[i - 1][0] + 1;                                                
            }
        }
        return min(res[n - 1][0], res[n - 1][1]);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/801.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

