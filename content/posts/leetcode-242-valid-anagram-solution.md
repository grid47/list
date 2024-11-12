
+++
authors = ["grid47"]
title = "Leetcode 242: Valid Anagram"
date = "2024-10-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 242: Valid Anagram in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/valid-anagram/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/242.webp" 
    alt="Two strings gently transforming into each other, with letters rearranging to form valid anagrams."
    caption="Solution to LeetCode 242: Valid Anagram Problem"
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
    bool isAnagram(string s, string t) {
        vector<int> ch(26, 0);
        for(char x: s) ch[x - 'a']++;
        for(char x: t) ch[x - 'a']--;
        for(int x: ch) if(x != 0) return false;
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/242.md" >}}
---
{{< youtube QMXliZEU9dU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #258: Add Digits](https://grid47.xyz/posts/leetcode-258-add-digits-solution/) |
| --- |
