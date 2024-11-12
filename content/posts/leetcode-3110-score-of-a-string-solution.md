
+++
authors = ["grid47"]
title = "Leetcode 3110: Score of a String"
date = "2024-01-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3110: Score of a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/score-of-a-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int scoreOfString(string s) {
        int sum=0;
        for(int i=0;i<s.size()-1;i++){
            sum+=abs(s[i]-s[i+1]);
        }
        return sum;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3110.md" >}}
---
{{< youtube imbrLFL20tQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #3120: Count the Number of Special Characters I](https://grid47.xyz/posts/leetcode-3120-count-the-number-of-special-characters-i-solution/) |
| --- |
