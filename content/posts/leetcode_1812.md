
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1812: Determine Color of a Chessboard Square"
date = "2019-11-13"
description = "Solution to Leetcode 1812"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/determine-color-of-a-chessboard-square/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool squareIsWhite(string cord) {
        int x = cord[0] - 'a' + 1;
        x += cord[1] - '0';
        return x % 2;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

