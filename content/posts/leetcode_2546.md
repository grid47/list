
+++
authors = ["Crafted by Me"]
title = "Leetcode 2546: Apply Bitwise Operations to Make Strings Equal"
date = "2016-11-12"
description = "Solution to Leetcode 2546"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        
        return (s.find('1') != string::npos) == (target.find('1') != string::npos);
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

