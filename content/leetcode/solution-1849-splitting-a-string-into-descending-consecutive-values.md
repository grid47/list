
+++
authors = ["grid47"]
title = "Leetcode 1849: Splitting a String Into Descending Consecutive Values"
date = "2024-05-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1849: Splitting a String Into Descending Consecutive Values in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "eDtMmysldaw"
youtube_upload_date="2021-05-02"
youtube_thumbnail="https://i.ytimg.com/vi/eDtMmysldaw/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string s;
    bool splitString(string s) {
        this->s = s;
        double tmp = 0;
        for(int i = 0; i < s.size() - 1; i++) {
            tmp = tmp * 10 + (s[i] - '0');
            if(bt(i + 1, tmp)) return true;
        }
        return false;
    }
    
    bool bt(int idx, double prv) {

        if(idx == s.size()) return true;
        
        double tmp = 0;
        for(int i = idx; i < s.size(); i++) {
            tmp = tmp * 10 + (s[i] - '0');
            if(tmp - prv > -1) break;
            if(tmp - prv == -1) {
                if(bt(i + 1, tmp))
                    return true;
            }
        }
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1849.md" >}}
---
{{< youtube eDtMmysldaw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1850: Minimum Adjacent Swaps to Reach the Kth Smallest Number](https://grid47.xyz/leetcode/solution-1850-minimum-adjacent-swaps-to-reach-the-kth-smallest-number/) |
| --- |