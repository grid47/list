
+++
authors = ["Yasir"]
title = "Leetcode 1812: Determine Color of a Chessboard Square"
date = "2019-11-12"
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

{{< highlight html >}}
class Solution {
public:
    bool squareIsWhite(string cord) {
        int x = cord[0] - 'a' + 1;
        x += cord[1] - '0';
        return x % 2;
    }
};
{{< /highlight >}}

