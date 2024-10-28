
+++
authors = ["Yasir"]
title = "Leetcode 2938: Separate Black and White Balls"
date = "2016-10-13"
description = "Solution to Leetcode 2938"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/separate-black-and-white-balls/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0;
        for (int i = 0, cnt = 0; i < s.size(); ++i) {
            if (s[i] == '1')
                ++cnt;
            else
                res += cnt;
        }
        return res;        
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

