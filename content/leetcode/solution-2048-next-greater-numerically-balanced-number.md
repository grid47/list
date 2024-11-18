
+++
authors = ["grid47"]
title = "Leetcode 2048: Next Greater Numerically Balanced Number"
date = "2024-04-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2048: Next Greater Numerically Balanced Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Backtracking","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "VLLBGEWCHqs"
youtube_upload_date="2021-10-24"
youtube_thumbnail="https://i.ytimg.com/vi/VLLBGEWCHqs/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/next-greater-numerically-balanced-number/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> base = {1, 22, 122, 333, 1333, 4444, 14444, 22333, 55555, 122333, 155555, 224444, 666666 };
    int nextBeautifulNumber(int n) {
        int res = 1224444;
        
        string s = to_string(n);
        for(auto it: base) {
            string ss = to_string(it);
            if(ss.size() < s.size()) continue;
            if(ss.size() > s.size()) res = min(res, it);
            else {
                do {
                    if(ss > s) {
                        res = min(res, stoi(ss));
                    }
                } while(next_permutation(ss.begin(), ss.end()));
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2048.md" >}}
---
{{< youtube VLLBGEWCHqs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2049: Count Nodes With the Highest Score](https://grid47.xyz/leetcode/solution-2049-count-nodes-with-the-highest-score/) |
| --- |
