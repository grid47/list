
+++
authors = ["grid47"]
title = "Leetcode 1668: Maximum Repeating Substring"
date = "2024-05-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1668: Maximum Repeating Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","String Matching"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "glQm_MZJywk"
youtube_upload_date="2020-11-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/glQm_MZJywk/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-repeating-substring/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int count=0;
        string temp=word;
        while(sequence.find(temp)!=string::npos)
        {
            count++;
            temp+=word;
        }
        return count;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1668.md" >}}
---
{{< youtube glQm_MZJywk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1669: Merge In Between Linked Lists](https://grid47.xyz/leetcode/solution-1669-merge-in-between-linked-lists/) |
| --- |
