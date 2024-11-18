
+++
authors = ["grid47"]
title = "Leetcode 567: Permutation in String"
date = "2024-09-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 567: Permutation in String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Two Pointers","String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/permutation-in-string/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/567.webp" 
    alt="A string where permutations are checked, each valid permutation softly glowing as it is found."
    caption="Solution to LeetCode 567: Permutation in String Problem"
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
    bool checkInclusion(string s1, string s2) {
        vector<int> p1(26, 0), p2(26, 0);
        for(char x: s1) p1[x-'a']++;
        for(int i = 0; i < s2.size(); i++) {
            if(i >= s1.size()) p2[s2[i - s1.size()] - 'a']--;
            p2[s2[i] - 'a']++;
            if(p1 == p2) return true;
        }
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/567.md" >}}
---
{{< youtube quSfR-uwkZU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #572: Subtree of Another Tree](https://grid47.xyz/leetcode/solution-572-subtree-of-another-tree/) |
| --- |
