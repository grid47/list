
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2272: Substring With Largest Variance"
date = "2018-08-12"
description = "Solution to Leetcode 2272"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/substring-with-largest-variance/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int largestVariance(string s) {
        
        int ans = 0;
        unordered_set<int> num(s.begin(), s.end());
        
        for(char a: num)
        for(char b: num) {
            int var = 0, first_b = 0, has_b = 0;
            for(char c: s) {
                
                var += c == a;
                
                if(c == b) {
                    has_b = true;
                    if(first_b && var >= 0)
                        first_b = false;
                    else if(--var < 0) {
                        var = -1;
                        first_b = true;
                    }
                }
                ans = max(ans, has_b? var: 0);                
            }

        }
        return ans;
        
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

