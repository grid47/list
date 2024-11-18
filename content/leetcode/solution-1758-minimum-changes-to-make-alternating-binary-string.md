
+++
authors = ["grid47"]
title = "Leetcode 1758: Minimum Changes To Make Alternating Binary String"
date = "2024-05-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1758: Minimum Changes To Make Alternating Binary String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "9vAQdmVU2ds"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minOperations(string s) {
        int zero = 0, one = 0, zf = false, of = false;
        for(int i = 0; i < s.size(); i++) {
            if(zf   && s[i] == '0') zero++;
            if(!zf  && s[i] == '1') zero++;
            if(!of   && s[i] == '0') one++;
            if(of  && s[i] == '1') one++;
            zf = !zf, of = !of;
        }
        return min(zero, one);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1758.md" >}}
---
{{< youtube 9vAQdmVU2ds >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1759: Count Number of Homogenous Substrings](https://grid47.xyz/leetcode/solution-1759-count-number-of-homogenous-substrings/) |
| --- |
