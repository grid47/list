
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 970: Powerful Integers"
date = "2022-03-04"
description = "Solution to Leetcode 970"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/powerful-integers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        for(int i = 1; i <= bound; i *= x) {
            for(int j = 1; i + j <= bound; j *= y) {
                s.insert(i + j);
                if(y == 1) break;
            }
            if(x == 1) break;
        }
        return vector<int>(s.begin(), s.end());
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

