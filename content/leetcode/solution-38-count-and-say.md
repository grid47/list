
+++
authors = ["grid47"]
title = "Leetcode 38: Count and Say"
date = "2024-11-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 38: Count and Say in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/38.webp"
youtube = "4PFCdoSOsiA"
youtube_upload_date="2023-12-25"
youtube_thumbnail="https://i.ytimg.com/vi_webp/4PFCdoSOsiA/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/count-and-say/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/38.webp" 
    alt="A series of glowing numbers transforming into words, forming a pattern of calm repetition."
    caption="Solution to LeetCode 38: Count and Say Problem"
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
    string countAndSay(int n) {
        if (n == 1) return "1";

        string tmp = countAndSay(n-1);
        string ans = "";

        for(int i = 0; i < tmp.size(); ) {

            char ch = tmp[i];
            int cnt = 0;

            while(tmp[i] == ch && i < tmp.size()) {
                cnt++;
                i++;
            }

            ans.push_back(cnt+'0');
            ans.push_back(tmp[i-1]);
        }

        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/38.md" >}}
---
{{< youtube 4PFCdoSOsiA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #39: Combination Sum](https://grid47.xyz/leetcode/solution-39-combination-sum/) |
| --- |
