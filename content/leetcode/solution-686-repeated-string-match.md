
+++
authors = ["grid47"]
title = "Leetcode 686: Repeated String Match"
date = "2024-08-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 686: Repeated String Match in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","String Matching"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = ""
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/686.webp"
+++



[`Problem Link`](https://leetcode.com/problems/repeated-string-match/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/686.webp" 
    alt="A string repeated multiple times, with the matching part glowing softly as it’s found."
    caption="Solution to LeetCode 686: Repeated String Match Problem"
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
    int repeatedStringMatch(string a, string b) {
        for(int i = 0, j = 0; i < a.size(); i++) {
            for(j = 0; j < b.size() && a[(i + j) % a.size()] == b[j]; j++);
            if(j == b.size())
                return (j + i - 1)/ a.size() + 1;
            
        }
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/686.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #687: Longest Univalue Path](https://grid47.xyz/leetcode/solution-687-longest-univalue-path/) |
| --- |
