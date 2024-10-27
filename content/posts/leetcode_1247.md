
+++
authors = ["Yasir"]
title = "Leetcode 1247: Minimum Swaps to Make Strings Equal"
date = "2021-05-30"
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

**Code:**

{{< highlight html >}}
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

