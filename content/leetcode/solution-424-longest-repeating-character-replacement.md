
+++
authors = ["grid47"]
title = "Leetcode 424: Longest Repeating Character Replacement"
date = "2024-09-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 424: Longest Repeating Character Replacement in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/424.webp"
youtube = "tkNWKvxI3mU"
youtube_upload_date="2024-03-09"
youtube_thumbnail="https://i.ytimg.com/vi/tkNWKvxI3mU/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/longest-repeating-character-replacement/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/424.webp" 
    alt="A string with a character being replaced to form the longest substring, glowing softly with each change."
    caption="Solution to LeetCode 424: Longest Repeating Character Replacement Problem"
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
    int characterReplacement(string s, int k) {
        map<char, int> ma;
        int res = 0, j = 0, mx = 0;
        for(int i =  0; i < s.size(); i++) {
            ma[s[i]]++;
            mx = max(mx, ma[s[i]]);
            if(i - j + 1 > mx + k) {
                ma[s[j]]--;
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/424.md" >}}
---
{{< youtube tkNWKvxI3mU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #427: Construct Quad Tree](https://grid47.xyz/leetcode/solution-427-construct-quad-tree/) |
| --- |
