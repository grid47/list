
+++
authors = ["Crafted by Me"]
title = "Leetcode 520: Detect Capital"
date = "2022-05-31"
description = "Solution to Leetcode 520"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/detect-capital/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool detectCapitalUse(string word) {
        for(int i = 1; i < word.size(); i++) {
            if(isupper(word[1]) != isupper(word[i]) ||
              islower(word[0]) && isupper(word[i])) 
                return false;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/520.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

