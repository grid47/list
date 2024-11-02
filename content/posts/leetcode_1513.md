
+++
authors = ["Crafted by Me"]
title = "Leetcode 1513: Number of Substrings With Only 1s"
date = "2019-09-11"
description = "Solution to Leetcode 1513"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-substrings-with-only-1s/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numSub(string s) {
        long cnt = 0, mod = (int) 1e9 + 7;

        long tmp = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                tmp++;
            }
            
            if(s[i] == '0' || i == n - 1) {
                cnt = (cnt + tmp * (tmp + 1) / 2) % mod;
                tmp = 0;
            }
            
        }
        return cnt;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

