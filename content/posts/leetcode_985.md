
+++
authors = ["Crafted by Me"]
title = "Leetcode 985: Sum of Even Numbers After Queries"
date = "2022-02-20"
description = "Solution to Leetcode 985"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-even-numbers-after-queries/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& qs) {
        vector<int> res = {};
        int sum = accumulate(begin(A), end(A), 0, [](int s, int a) {
            return s + (a % 2 == 0? a : 0);
        });
        for(auto &q: qs) {
            if(A[q[1]] %2 == 0) sum-=A[q[1]];
            A[q[1]] += q[0];
            if(A[q[1]]%2 == 0) sum+=A[q[1]];
            res.push_back(sum);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/985.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

