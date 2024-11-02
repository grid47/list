
+++
authors = ["Crafted by Me"]
title = "Leetcode 1624: Largest Substring Between Two Equal Characters"
date = "2019-05-23"
description = "Solution to Leetcode 1624"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-substring-between-two-equal-characters/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        map<char, int> mp;
        int ans = -1;
        for(int i = 0; i < n; i++) {
            if(mp.count(s[i])) {
                ans = max(ans, i - mp[s[i]] - 1);
            }
            if(!mp.count(s[i])) {
                mp[s[i]] = i;
            }
        }
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube rfjeFs3JuYM >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

