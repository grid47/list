
+++
authors = ["Crafted by Me"]
title = "Leetcode 848: Shifting Letters"
date = "2022-07-08"
description = "In-depth solution and explanation for Leetcode 848: Shifting Letters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/shifting-letters/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {

        int n = shifts.size();
        for(int i = n - 2; i >= 0; i--)
        shifts[i] = (shifts[i] + shifts[i + 1] ) % 26;

        for(int i = 0; i < s.size(); i++)
        s[i] = 'a' + ((s[i] - 'a'+ shifts[i]) % 26);

        return s;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/848.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

