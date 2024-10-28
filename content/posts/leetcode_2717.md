
+++
authors = ["Yasir"]
title = "Leetcode 2717: Semi-Ordered Permutation"
date = "2017-05-22"
description = "Solution to Leetcode 2717"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/semi-ordered-permutation/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int semiOrderedPermutation(vector<int>& A) {
        int n = A.size(), 
        i = find(A.begin(), A.end(), 1) - A.begin(), 
        j = find(A.begin(), A.end(), n) - A.begin();
        return i + n - 1 - j - (i > j);
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

