
+++
authors = ["grid47"]
title = "Leetcode 2255: Count Prefixes of a Given String"
date = "2024-03-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2255: Count Prefixes of a Given String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "ctp3MD4jiGg"
youtube_upload_date="2022-04-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ctp3MD4jiGg/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/count-prefixes-of-a-given-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt = 0;
        for(string x: words) {
            if(x.size() > s.size()) continue;
            bool flag = true;
            for(int i = 0; i < x.size(); i++) {
                if(x[i] != s[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2255.md" >}}
---
{{< youtube ctp3MD4jiGg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2256: Minimum Average Difference](https://grid47.xyz/leetcode/solution-2256-minimum-average-difference/) |
| --- |
