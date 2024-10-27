
+++
authors = ["Yasir"]
title = "Leetcode 395: Longest Substring with At Least K Repeating Characters"
date = "2023-09-29"
description = "Solution to Leetcode 395"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size() == 0 || k > s.size()) return 0;
        if(k == 0) return s.size();

        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }

        int idx = 0;
        while(idx < s.size() && mp[s[idx]] >= k) idx++;
        if(idx == s.size()) return s.size();

        int left = longestSubstring(s.substr(0, idx), k);
        int right = longestSubstring(s.substr(idx + 1), k);

        return max(left, right);
    }
};
{{< /highlight >}}

