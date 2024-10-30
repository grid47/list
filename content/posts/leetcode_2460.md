
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2460: Apply Operations to an Array"
date = "2018-02-05"
description = "Solution to Leetcode 2460"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/apply-operations-to-an-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
vector<int> applyOperations(vector<int>& A) {
    for (int i = 0, j = 0; i < size(A); ++i){
        if (i + 1 < size(A) and A[i] == A[i + 1]){
            A[i] *= 2;
            A[i + 1] = 0;
        }
        if (A[i]) swap(A[j++], A[i]);
    }   
    return A;
}
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

