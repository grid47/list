
+++
authors = ["Crafted by Me"]
title = "Leetcode 2126: Destroying Asteroids"
date = "2019-01-06"
description = "Solution to Leetcode 2126"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/destroying-asteroids/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        sort(ast.begin(), ast.end());
        int n = ast.size();
        long long mss = mass;
        for(int i = 0;i < n; i++) {
            if(mss >= ast[i])
                mss += ast[i];
            else return false;
        }
        return true;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

