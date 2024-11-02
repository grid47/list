
+++
authors = ["Crafted by Me"]
title = "Leetcode 2390: Removing Stars From a String"
date = "2017-04-17"
description = "Solution to Leetcode 2390"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/removing-stars-from-a-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string removeStars(string s) {
        int j = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '*') s[j++] = s[i];
            else {
                j--;
            }
        }
        return s.substr(0, j);
    }
};
{{< /highlight >}}


---
{{< youtube Qln1aXh2kvQ >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

