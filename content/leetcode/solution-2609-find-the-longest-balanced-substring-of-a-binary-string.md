
+++
authors = ["grid47"]
title = "Leetcode 2609: Find the Longest Balanced Substring of a Binary String"
date = "2024-02-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2609: Find the Longest Balanced Substring of a Binary String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "_nyH2TA95yY"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int zr = 0, ans = 0;
        int cnt[2] = {};
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') {
                if(cnt[1]) {
                    cnt[0] = 0;
                    cnt[1] = 0;                    
                }
                cnt[0]++;
            } else {
                if(cnt[1] < cnt[0]) cnt[1]++;
                else {
                    cnt[0] = 0;
                    cnt[1] = 0;
                }
                ans = max(cnt[1] * 2, ans);
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2609.md" >}}
---
{{< youtube _nyH2TA95yY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2610: Convert an Array Into a 2D Array With Conditions](https://grid47.xyz/leetcode/solution-2610-convert-an-array-into-a-2d-array-with-conditions/) |
| --- |
