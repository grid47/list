
+++
authors = ["Yasir"]
title = "Leetcode 926: Flip String to Monotone Increasing"
date = "2022-04-15"
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

{{< highlight html >}}
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

