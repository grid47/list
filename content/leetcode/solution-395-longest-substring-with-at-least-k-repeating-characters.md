
+++
authors = ["grid47"]
title = "Leetcode 395: Longest Substring with At Least K Repeating Characters"
date = "2024-09-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 395: Longest Substring with At Least K Repeating Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Divide and Conquer","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "bHZkCAcj3dc"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/395.webp"
+++



[`Problem Link`](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/395.webp" 
    alt="A string with glowing characters highlighting the longest substring with at least K repeating characters."
    caption="Solution to LeetCode 395: Longest Substring with At Least K Repeating Characters Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/395.md" >}}
---
{{< youtube bHZkCAcj3dc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #396: Rotate Function](https://grid47.xyz/leetcode/solution-396-rotate-function/) |
| --- |
