
+++
authors = ["Crafted by Me"]
title = "Leetcode 1694: Reformat Phone Number"
date = "2020-03-14"
description = "Solution to Leetcode 1694"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reformat-phone-number/description/)

---

**Code:**

{{< highlight cpp >}}
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string reformatNumber(string s) {
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) s[j++] = s[i];
        }
        s.resize(j);
        string ans;
        for (int i = 0, r = s.size(); i < s.size(); ) {
            for (int d = r == 2 || r == 4 ? 2 : 3; d > 0; --d, --r) {
                ans += s[i++];
            }
            if (r) ans += '-';
        }
        return ans;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

