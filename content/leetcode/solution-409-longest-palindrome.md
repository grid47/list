
+++
authors = ["grid47"]
title = "Leetcode 409: Longest Palindrome"
date = "2024-09-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 409: Longest Palindrome in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/409.webp"
youtube = "_g9jrLuAphs"
youtube_upload_date="2024-06-04"
youtube_thumbnail="https://i.ytimg.com/vi/_g9jrLuAphs/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/longest-palindrome/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/409.webp" 
    alt="A string where the longest palindrome is highlighted, with characters mirroring in a soft glow."
    caption="Solution to LeetCode 409: Longest Palindrome Problem"
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
    int longestPalindrome(string s) {
        map<char, int> mp;
        for(char x: s)
            mp[x]++;
        bool odd = false;
        int res = 0;
        for(auto [key, val]: mp) {
            if(val % 2) odd = true;
            res += (val/2) * 2;
        }
        return odd? res + 1: res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/409.md" >}}
---
{{< youtube _g9jrLuAphs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #415: Add Strings](https://grid47.xyz/leetcode/solution-415-add-strings/) |
| --- |
