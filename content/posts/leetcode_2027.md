
+++
authors = ["Yasir"]
title = "Leetcode 2027: Minimum Moves to Convert String"
date = "2019-04-12"
description = "Solution to Leetcode 2027"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-moves-to-convert-string/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minimumMoves(string s) {
        int i = 0, n = s.length(), count = 0;
        while (i < n) {
            if (s[i] == 'O')
                i++;
            else
                count++, i += 3;
        }
        return count;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

