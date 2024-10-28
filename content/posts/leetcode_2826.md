
+++
authors = ["Yasir"]
title = "Leetcode 2826: Sorting Three Groups"
date = "2017-02-02"
description = "Solution to Leetcode 2826"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sorting-three-groups/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minimumOperations(vector<int>& A) {
        int a = 0, b = 0, c = 0;
        for (int x: A) {
            a += x != 1;
            b = min(a, b + (x != 2));
            c = min(b, c + (x != 3));
        }
        return c;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

