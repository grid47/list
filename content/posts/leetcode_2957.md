
+++
authors = ["Crafted by Me"]
title = "Leetcode 2957: Remove Adjacent Almost-Equal Characters"
date = "2015-09-28"
description = "Solution to Leetcode 2957"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-adjacent-almost-equal-characters/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int removeAlmostEqualCharacters(string s) {
        int n = s.size();
        int i = 1, cnt = 0;
        while(i < n) {
            if(s[i] == s[i - 1] || abs(s[i] - s[i - 1]) == 1) cnt++, i += 2;
            else i++;
        }
        return cnt;        
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

