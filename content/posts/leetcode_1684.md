
+++
authors = ["Crafted by Me"]
title = "Leetcode 1684: Count the Number of Consistent Strings"
date = "2019-03-24"
description = "Solution to Leetcode 1684"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-the-number-of-consistent-strings/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = words.size();
        bool mp[26] = {};
        for (char c: allowed) mp[c - 'a'] = true;
        for (string word: words) {
            for (char c: word) if (!mp[c - 'a']) {
                res--;
                break;
            }
        }
        return res;        
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

