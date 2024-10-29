
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1513: Number of Substrings With Only 1s"
date = "2020-09-08"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

