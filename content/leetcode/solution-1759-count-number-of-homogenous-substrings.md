
+++
authors = ["grid47"]
title = "Leetcode 1759: Count Number of Homogenous Substrings"
date = "2024-05-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1759: Count Number of Homogenous Substrings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "I3BzhnS9MwA"
youtube_upload_date="2021-02-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/I3BzhnS9MwA/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/count-number-of-homogenous-substrings/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countHomogenous(string s) {
        long long j = 0, cnt = 0, n = s.size();
        int mod = (int) 1e9 + 7;
        
        for(int i = 0; i < n; i++) {
            if(s[j] == s[i]) continue;
            else {
                long long len = i - j;
                cnt += len * (len + 1) / 2;
                j = i;                
            }
        }
        long long len = n - j;
        cnt += len * (len + 1) / 2; 
        return cnt % mod;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1759.md" >}}
---
{{< youtube I3BzhnS9MwA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1760: Minimum Limit of Balls in a Bag](https://grid47.xyz/leetcode/solution-1760-minimum-limit-of-balls-in-a-bag/) |
| --- |