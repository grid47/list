
+++
authors = ["grid47"]
title = "Leetcode 1593: Split a String Into the Max Number of Unique Substrings"
date = "2024-05-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1593: Split a String Into the Max Number of Unique Substrings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "fLjeVALxzjg"
youtube_upload_date="2024-10-21"
youtube_thumbnail="https://i.ytimg.com/vi/fLjeVALxzjg/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mx = 1, n;
    string s;
    
    int maxUniqueSplit(string s) {
        set<string> cnt;
        string tmp = "";
        n = s.size();
        this->s = s;
        bt(0, tmp, cnt);
        
        return mx;
    }
    
    void bt(int idx, string tmp, set<string> cnt) {
        if(idx == n) {
            mx = max(mx, (int)cnt.size());
            return;
        }
        
        for(int i = idx; i < n; i++) {
            tmp += s[i];
            if(!cnt.count(tmp)) {
                cnt.insert(tmp);
                bt(i + 1, "", cnt);
                cnt.erase(tmp);
            }
        }
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1593.md" >}}
---
{{< youtube fLjeVALxzjg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1594: Maximum Non Negative Product in a Matrix](https://grid47.xyz/leetcode/solution-1594-maximum-non-negative-product-in-a-matrix/) |
| --- |
