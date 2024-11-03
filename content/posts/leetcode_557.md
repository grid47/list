
+++
authors = ["Crafted by Me"]
title = "Leetcode 557: Reverse Words in a String III"
date = "2023-04-25"
description = "In-depth solution and explanation for Leetcode 557: Reverse Words in a String III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reverse-words-in-a-string-iii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(), prv = 0;
        for(int i = 0; i < n; i++)
            if(s[i] == ' ')
                rev(s, prv, i - 1), prv = i + 1;
            else if(i == n - 1)
                rev(s, prv, i);        
        return s;
    }
    
    void rev(string &s, int i, int j) {
        while(i <= j)
            swap(s[i++], s[j--]);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/557.md" >}}
---
{{< youtube _I57bpDMWnY >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

