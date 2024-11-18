
+++
authors = ["grid47"]
title = "Leetcode 2710: Remove Trailing Zeros From a String"
date = "2024-02-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2710: Remove Trailing Zeros From a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "cY-wxEdhSAY"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/remove-trailing-zeros-from-a-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.size();
        int cnt = 0;
        int len;
        for( len = 1; len <= n; len++) {
            if(num[n - len] == '0') cnt++;
            else break;
        }
        return num.substr(0, n - cnt);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2710.md" >}}
---
{{< youtube cY-wxEdhSAY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2711: Difference of Number of Distinct Values on Diagonals](https://grid47.xyz/leetcode/solution-2711-difference-of-number-of-distinct-values-on-diagonals/) |
| --- |
