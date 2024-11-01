
+++
authors = ["Crafted by Me"]
title = "Leetcode 1016: Binary String With Substrings Representing 1 To N"
date = "2022-01-21"
description = "Solution to Leetcode 1016"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool queryString(string s, int n) {
        for(int i = n; i > n / 2; i--) {
            string b = bitset<32>(i).to_string();
            if(s.find(b.substr(b.find('1'))) == string::npos)
                return false;
        }
        return true;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

