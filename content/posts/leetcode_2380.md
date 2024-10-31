
+++
authors = ["Crafted by Me"]
title = "Leetcode 2380: Time Needed to Rearrange a Binary String"
date = "2018-04-27"
description = "Solution to Leetcode 2380"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int seconds = 0;
        bool changed = true;
        while(changed) {
            changed = false;
            for(int i = 0; i < s.size() - 1; i++) {
                if(s[i] == '0' && s[i + 1] == '1') {
                    swap(s[i], s[i + 1]);
                    changed = true;
                    i++;
                }
            }
            seconds += changed;
        }
        return seconds;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

