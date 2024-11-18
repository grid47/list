
+++
authors = ["grid47"]
title = "Leetcode 3: Longest Substring Without Repeating Characters"
date = "2024-11-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3: Longest Substring Without Repeating Characters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/3.webp"
youtube = "wiGpQwVHdE0"
youtube_upload_date="2020-06-27"
youtube_thumbnail="https://i.ytimg.com/vi/wiGpQwVHdE0/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/3.webp" 
    alt="A flowing ribbon with distinct, colorful segments, twisting and avoiding repetition."
    caption="Solution to LeetCode 3: Longest Substring Without Repeating Characters Problem"
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
    int lengthOfLongestSubstring(string s) {
        int prv = -1, len = 0;
        map<char, int> mp;
        for(int i = 0; i < s.size(); i++) {
            if(mp.count(s[i]))
                prv = max(prv, mp[s[i]]);
            mp[s[i]] = i;
            len = max(len, i - prv);
        }
        return len;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3.md" >}}
---
{{< youtube wiGpQwVHdE0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #5: Longest Palindromic Substring](https://grid47.xyz/leetcode/solution-5-longest-palindromic-substring/) |
| --- |
