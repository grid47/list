
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1759: Count Number of Homogenous Substrings"
date = "2020-01-06"
description = "Solution to Leetcode 1759"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-number-of-homogenous-substrings/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countHomogenous(string s) {
        long long j = 0, cnt = 0, n = s.size();
        int mod = (int) 1e9 + 7;
        
        for(int i = 0; i < n; i++) {
            if(s[j] == s[i]) continue;
            else {
                long long len = i - j;
                cnt += len * (len + 1) / 2;
                j = i;                
            }
        }
        long long len = n - j;
        cnt += len * (len + 1) / 2; 
        return cnt % mod;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

