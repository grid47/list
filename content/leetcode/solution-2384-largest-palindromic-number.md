
+++
authors = ["grid47"]
title = "Leetcode 2384: Largest Palindromic Number"
date = "2024-03-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2384: Largest Palindromic Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Greedy","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "IMktz_WlNYo"
youtube_upload_date="2022-08-21"
youtube_thumbnail="https://i.ytimg.com/vi/IMktz_WlNYo/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/largest-palindromic-number/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string largestPalindromic(string num) {
        int cnt[10] = {}, mid = -1;
        string s;

        for(char c: num) cnt[c - '0']++;

        for(int i = 9; i > 0; i--) {
            if(cnt[i] == 0) continue;
            s.append(cnt[i]/2, i + '0');
            if(mid == -1 && (cnt[i]&1))
                    mid = i;
        }

        if(s.size() && cnt[0]) s.append(cnt[0]/2, '0');
        mid = mid == -1 && (cnt[0] & 1)? 0: mid;
        if(mid != -1) s.push_back(mid + '0');
        s.insert(s.end(), s.rbegin() + (mid == -1? 0:1), s.rend());

        return s != ""? s : "0";
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2384.md" >}}
---
{{< youtube IMktz_WlNYo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2385: Amount of Time for Binary Tree to Be Infected](https://grid47.xyz/leetcode/solution-2385-amount-of-time-for-binary-tree-to-be-infected/) |
| --- |
