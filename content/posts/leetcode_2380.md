
+++
authors = ["Yasir"]
title = "Leetcode 2380: Time Needed to Rearrange a Binary String"
date = "2018-04-23"
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

{{< highlight html >}}
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

