
+++
authors = ["grid47"]
title = "Leetcode 2490: Circular Sentence"
date = "2024-03-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2490: Circular Sentence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "9Ty_eRjoDNM"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/circular-sentence/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isCircularSentence(string s) {
        
        int n = s.size();
        if((s[0]) != (s[n - 1]))
            return false;
        for(int i = 1; i < s.size() - 1; i++) {
            if(s[i] == ' ') {
                if((s[i - 1]) != (s[i + 1]))
                    return false;                
            }
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2490.md" >}}
---
{{< youtube 9Ty_eRjoDNM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2491: Divide Players Into Teams of Equal Skill](https://grid47.xyz/leetcode/solution-2491-divide-players-into-teams-of-equal-skill/) |
| --- |
