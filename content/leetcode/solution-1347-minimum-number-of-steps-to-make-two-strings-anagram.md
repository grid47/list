
+++
authors = ["grid47"]
title = "Leetcode 1347: Minimum Number of Steps to Make Two Strings Anagram"
date = "2024-06-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1347: Minimum Number of Steps to Make Two Strings Anagram in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = ""
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> count(26, 0);
        for(int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        int step = 0;
        for(int num : count)
            if(num > 0) step += num;
        return step;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1347.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1348: Tweet Counts Per Frequency](https://grid47.xyz/leetcode/solution-1348-tweet-counts-per-frequency/) |
| --- |
