
+++
authors = ["Crafted by Me"]
title = "Leetcode 1790: Check if One String Swap Can Make Strings Equal"
date = "2019-12-08"
description = "Solution to Leetcode 1790"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int chg = 0, cnt = 0;
        vector<int> frq1(26, 0), frq2(26, 0);
        for(int i = 0; i < s1.size(); i++) {
            frq1[s1[i] - 'a']++;
            frq2[s2[i] - 'a']++;
            if(s1[i] != s2[i]) cnt++;
        }

        return frq1 == frq2 && (cnt == 2 || cnt == 0);
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

