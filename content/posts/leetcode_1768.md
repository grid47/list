
+++
authors = ["Crafted by Me"]
title = "Leetcode 1768: Merge Strings Alternately"
date = "2019-12-30"
description = "Solution to Leetcode 1768"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/merge-strings-alternately/description/)

---

{{< youtube oFuFTMu2Tgg >}}

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        string res = "";
        int i = 0, j = 0;
        while(i < w1.size() || j < w2.size()) {
            if(i < w1.size()) {
                res += w1[i];
                i++;
            }
            if(j < w2.size()) {
                res += w2[j];
                j++;
            }
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

