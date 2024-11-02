
+++
authors = ["Crafted by Me"]
title = "Leetcode 2129: Capitalize the Title"
date = "2019-01-04"
description = "Solution to Leetcode 2129"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/capitalize-the-title/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string capitalizeTitle(string s) {
        for (int i = 0, j = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                if (i - j > 2)
                    s[j] = toupper(s[j]);
                j = i + 1;
            }
            else
                s[i] = tolower(s[i]);
        }
        return s;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

