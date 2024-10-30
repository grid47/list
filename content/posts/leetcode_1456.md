
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1456: Maximum Number of Vowels in a Substring of Given Length"
date = "2020-11-05"
description = "Solution to Leetcode 1456"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int vowels[26] = {  1,0,0,0,1, 0,0,0,1,0, 
                        0,0,0,0,1, 0,0,0,0,0, 
                        1,0,0,0,0, 0 };
    int maxVowels(string s, int k) {
        int mx = 0;
        for(int i = 0, cur = 0; i < s.size(); i++) {
            cur += vowels[s[i] - 'a'];
            if(i >= k) cur -= vowels[s[i-k] - 'a'];
            mx = max(cur, mx);
        }
        return mx;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

