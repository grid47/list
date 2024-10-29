
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 926: Flip String to Monotone Increasing"
date = "2022-04-18"
description = "Solution to Leetcode 926"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/flip-string-to-monotone-increasing/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cnt_one = 0, cnt_flip = 0;
        for(char c: s) {
            if(c == '1') cnt_one++;
            else         cnt_flip++;
            cnt_flip = min(cnt_one, cnt_flip);
        }
        return cnt_flip;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

