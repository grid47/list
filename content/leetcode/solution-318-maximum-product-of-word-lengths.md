
+++
authors = ["grid47"]
title = "Leetcode 318: Maximum Product of Word Lengths"
date = "2024-10-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 318: Maximum Product of Word Lengths in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/318.webp"
youtube = "dE88fgc73jQ"
youtube_upload_date="2021-05-27"
youtube_thumbnail="https://i.ytimg.com/vi/dE88fgc73jQ/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-product-of-word-lengths/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/318.webp" 
    alt="A set of words with glowing lengths, each word’s length highlighted to show the maximum product of word lengths."
    caption="Solution to LeetCode 318: Maximum Product of Word Lengths Problem"
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
    int maxProduct(vector<string>& words) {

        int len = words.size();
        vector<int> mask(len, 0);

        int res = 0;
        for(int i = 0; i < len; i++) {
            string word = words[i];
            int sz = word.size();
            for(int j = 0; j < sz; j++)
            mask[i] |= (1 << (word[j] - 'a'));

            for(int j = 0; j < i; j++) {
                if((mask[i] & mask[j]) == 0)
                res = max(res, int (words[i].size() * words[j].size() ));
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/318.md" >}}
---
{{< youtube dE88fgc73jQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #319: Bulb Switcher](https://grid47.xyz/leetcode/solution-319-bulb-switcher/) |
| --- |