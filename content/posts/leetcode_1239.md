
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1239: Maximum Length of a Concatenated String with Unique Characters"
date = "2021-06-10"
description = "Solution to Leetcode 1239"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> dp = {bitset<26>()};
        int res = 0;
        for(auto &s: arr) {
            bitset<26> a;
            for(char x: s)
                a.set(x-'a');
            int n = a.count();
            if(n < s.size()) continue;
            for(int i = dp.size() -1; i >= 0; i--) {
                bitset c = dp[i];
                if ((c&a).any()) continue;
                dp.push_back(c|a);
                res = max(res, (int) c.count()+n);
                
            }
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

