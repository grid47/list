
+++
authors = ["Crafted by Me"]
title = "Leetcode 1529: Minimum Suffix Flips"
date = "2020-08-26"
description = "Solution to Leetcode 1529"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-suffix-flips/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minFlips(string target) {
        int flips = 0;
        char status = '0';
        for(int i = 0; i < target.size(); i++) {
            if(status != target[i]) {
                flips++;
                status = status == '0'? '1':'0';
            }
        }
        return flips;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

