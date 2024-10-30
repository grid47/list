
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2207: Maximize Number of Subsequences in a String"
date = "2018-10-16"
description = "Solution to Leetcode 2207"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        
        long long cnt1 = 0, cnt2 = 0, res = 0, n = text.length();
        
        for(int i = 0; i < n; i++) {
            if(text[i] == pattern[1]) {
                cnt2++;
                res += cnt1;
            }
            if(text[i] == pattern[0]) cnt1++;
        }

        res += max(cnt1, cnt2);
        
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

