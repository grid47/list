
+++
authors = ["grid47"]
title = "Leetcode 520: Detect Capital"
date = "2024-09-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 520: Detect Capital in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/detect-capital/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/520.webp" 
    alt="A word where the capital letters are detected, glowing softly as the word is analyzed."
    caption="Solution to LeetCode 520: Detect Capital Problem"
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
    bool detectCapitalUse(string word) {
        for(int i = 1; i < word.size(); i++) {
            if(isupper(word[1]) != isupper(word[i]) ||
              islower(word[0]) && isupper(word[i])) 
                return false;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/520.md" >}}
---
{{< youtube TIJRBKK1gXE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #522: Longest Uncommon Subsequence II](https://grid47.xyz/posts/leetcode-522-longest-uncommon-subsequence-ii-solution/) |
| --- |
