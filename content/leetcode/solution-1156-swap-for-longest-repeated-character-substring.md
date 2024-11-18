
+++
authors = ["grid47"]
title = "Leetcode 1156: Swap For Longest Repeated Character Substring"
date = "2024-07-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1156: Swap For Longest Repeated Character Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "0kfkOm4b-8I"
youtube_upload_date="2023-01-10"
youtube_thumbnail="https://i.ytimg.com/vi_webp/0kfkOm4b-8I/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/swap-for-longest-repeated-character-substring/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxRepOpt1(string text, int res = 1) {
        vector<vector<int>> idx(26);
        for(int i = 0; i < text.size(); i++)
            idx[text[i] - 'a'].push_back(i);

        for(int n = 0; n < 26; n++) {
            auto cnt = 1, cnt1 = 0, mx = 0;
            for(auto i = 1; i < idx[n].size(); i++) {
                if(idx[n][i] == idx[n][i - 1]+ 1) ++cnt;
                else {
                    cnt1 = idx[n][i] == idx[n][i-1] + 2? cnt:0;
                    cnt = 1;
                }
                mx = max(mx, cnt + cnt1);
            }
            res = max(res, mx + ( idx[n].size() > mx ? 1 : 0) );
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1156.md" >}}
---
{{< youtube 0kfkOm4b-8I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1160: Find Words That Can Be Formed by Characters](https://grid47.xyz/leetcode/solution-1160-find-words-that-can-be-formed-by-characters/) |
| --- |
