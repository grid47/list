
+++
authors = ["Yasir"]
title = "Leetcode 3: Longest Substring Without Repeating Characters"
date = "2024-10-24"
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

{{< highlight html >}}
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

