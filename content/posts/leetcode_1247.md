
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1247: Minimum Swaps to Make Strings Equal"
date = "2021-06-02"
description = "Solution to Leetcode 1247"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0, yx = 0;
        for(int i = 0; i < s1.size(); i++) {
                 if(s1[i] == 'x' && s2[i] == 'y') xy++;
            else if(s1[i] == 'y' && s2[i] == 'x') yx++;
        }

        if(xy % 2 != yx % 2) return -1;
        return xy/2 + yx/2 + (xy%2) * 2;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

