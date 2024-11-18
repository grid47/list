
+++
authors = ["grid47"]
title = "Leetcode 809: Expressive Words"
date = "2024-08-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 809: Expressive Words in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/809.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



[`Problem Link`](https://leetcode.com/problems/expressive-words/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/809.webp" 
    alt="A string of words where expressive words glow softly, highlighting their expressive nature."
    caption="Solution to LeetCode 809: Expressive Words Problem"
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
    int expressiveWords(string s, vector<string>& words) {
        int res = 0;
        for(auto &w : words)
            if(check(s, w))
                res++;
        return res;
    }

    bool check(string s, string w) {
        int n = s.size(), m = w.size(), j = 0;
        for(int i = 0; i < n; i++)
            if(j < m && s[i] == w[j]) j++;
            else if (i > 1 && s[i - 2] == s[i - 1] && s[i - 1] == s[i]);
            else if (i > 0 && i < n - 1 && s[i -1] == s[i] && s[i] == s[i +1]);
            else return false;
        return j == m;
    }

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/809.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #811: Subdomain Visit Count](https://grid47.xyz/leetcode/solution-811-subdomain-visit-count/) |
| --- |
