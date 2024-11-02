
+++
authors = ["Crafted by Me"]
title = "Leetcode 1234: Replace the Substring for Balanced String"
date = "2021-06-17"
description = "Solution to Leetcode 1234"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/replace-the-substring-for-balanced-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int balancedString(string s) {
        map<char, int> ma;
        for(int i = 0; i < s.size(); i++) {
            ma[s[i]]++;
        }
        int k = s.size() / 4, j = 0, res = s.size();
        for(int i = 0; i < s.size(); i++) {
            ma[s[i]]--;
        while(j < s.size() && ma['Q'] <= k && ma['W'] <= k && ma['E'] <= k && ma['R'] <= k) {
                ma[s[j]]++;
                res = min(res, i - j + 1);
                j++;
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

