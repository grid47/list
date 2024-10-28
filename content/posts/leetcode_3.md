
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 3: Longest Substring Without Repeating Characters"
date = "2024-10-26"
description = "Solution to Leetcode 3"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int prv = -1, len = 0;
        map<char, int> mp;
        for(int i = 0; i < s.size(); i++) {
            if(mp.count(s[i]))
                prv = max(prv, mp[s[i]]);
            mp[s[i]] = i;
            len = max(len, i - prv);
        }
        return len;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

