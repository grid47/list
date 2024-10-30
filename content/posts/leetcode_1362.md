
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1362: Closest Divisors"
date = "2021-02-07"
description = "Solution to Leetcode 1362"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/closest-divisors/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> closestDivisors(int num) {
        
        for(int a = sqrt(num + 2); a > 0; a--) {
            if((num + 1) % a == 0) return vector<int>{a, (num + 1) / a};
            if((num + 2) % a == 0) return vector<int>{a, (num + 2) / a};            
        }
        return vector<int>{};
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

