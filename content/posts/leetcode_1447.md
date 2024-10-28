
+++
authors = ["Yasir"]
title = "Leetcode 1447: Simplified Fractions"
date = "2020-11-12"
description = "Solution to Leetcode 1447"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/simplified-fractions/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        if(n == 1) return {};
        vector<string> res;
        queue<tuple<int, int, int, int>> q;
        q.emplace(0, 1, 1, 1);
        while(!q.empty()) {
            auto [num1, den1, num2, den2] = q.front();
            q.pop();
            int num = num1 + num2;
            int den = den1 + den2;
            res.push_back(to_string(num) + "/" + to_string(den));
            if(den + den1 <= n) q.emplace(num1, den1, num, den);
            if(den + den2 <= n) q.emplace(num, den, num2, den2);
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

