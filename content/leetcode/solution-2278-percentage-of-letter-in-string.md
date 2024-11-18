
+++
authors = ["grid47"]
title = "Leetcode 2278: Percentage of Letter in String"
date = "2024-03-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2278: Percentage of Letter in String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "aVeeYs2bSzY"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/percentage-of-letter-in-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int percentageLetter(string s, char letter) {
        return 100 * count(begin(s), end(s), letter) / s.size();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2278.md" >}}
---
{{< youtube aVeeYs2bSzY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2279: Maximum Bags With Full Capacity of Rocks](https://grid47.xyz/leetcode/solution-2279-maximum-bags-with-full-capacity-of-rocks/) |
| --- |
