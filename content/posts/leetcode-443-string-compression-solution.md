
+++
authors = ["grid47"]
title = "Leetcode 443: String Compression"
date = "2024-09-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 443: String Compression in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/string-compression/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/443.webp" 
    alt="A string shrinking as characters are compressed, with each compression step softly glowing."
    caption="Solution to LeetCode 443: String Compression Problem"
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
    int compress(vector<char>& chars) {
        if(chars.size() < 2) return chars.size();
        int i = 0, j = 0;
        while(i < chars.size()) {
            chars[j] = chars[i];
            int cnt = 0;
            while(i < chars.size() && chars[i] == chars[j]) {
                cnt++;
                i++;
            }

            if(cnt == 1) {
                j++;
            } else {
                string cntt = to_string(cnt);
                for(auto ch: cntt) {
                    chars[++j] = ch;
                }
                j++;
            }
        }
        return j;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/443.md" >}}
---
{{< youtube JHTqvUTZzqM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #445: Add Two Numbers II](https://grid47.xyz/posts/leetcode-445-add-two-numbers-ii-solution/) |
| --- |
