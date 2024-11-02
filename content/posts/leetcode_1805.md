
+++
authors = ["Crafted by Me"]
title = "Leetcode 1805: Number of Different Integers in a String"
date = "2018-11-23"
description = "Solution to Leetcode 1805"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-different-integers-in-a-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numDifferentIntegers(string w) {
        unordered_set<string> s{""};    
        for (int i = 0, j = 0; j <= w.size(); ++j) {
            if (j < w.size() && isdigit(w[j]))
                i += i < j && w[i] == '0';
            else {
                s.insert(w.substr(i, j - i));
                i = j + 1;
            }
        }
        return s.size() - 1;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

