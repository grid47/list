
+++
authors = ["Yasir"]
title = "Leetcode 967: Numbers With Same Consecutive Differences"
date = "2022-03-07"
description = "Solution to Leetcode 967"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/numbers-with-same-consecutive-differences/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> cur = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for(int i = 2; i <= n; i++) {
            vector<int> cur2;
            for(int x: cur) {
                int y = x % 10;
                if(y + k < 10)
                    cur2.push_back(x * 10 + y + k);
                if(k>0 && y - k >= 0)
                    cur2.push_back(x * 10 + y - k);
                
            }
            cur = cur2;
        }
        return cur;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

