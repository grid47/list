
+++
authors = ["Yasir"]
title = "Leetcode 2928: Distribute Candies Among Children I"
date = "2016-10-23"
description = "Solution to Leetcode 2928"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/distribute-candies-among-children-i/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int distributeCandies(int n, int limit) {
        int res = 0;
        for(int i = 0; i <= limit; ++i){
            for(int j = 0; j <= limit; ++j){
                for(int k = 0; k <= limit; ++k){
                    if(i + j + k == n) { res++; }
                }
            }
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

