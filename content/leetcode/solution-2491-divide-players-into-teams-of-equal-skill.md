
+++
authors = ["grid47"]
title = "Leetcode 2491: Divide Players Into Teams of Equal Skill"
date = "2024-03-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2491: Divide Players Into Teams of Equal Skill in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "cueOpK5QMEA"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int l = 0, r = n - 1;
        
        int sum = skill[l] + skill[r];
        long long prod = skill[l] * skill[r];
        
        l++, r--;
        while(l < r) {
            if(sum != (skill[l] + skill[r])) return -1;
            prod += skill[l] * skill[r];
            l++;
            r--;
        }
        return prod;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2491.md" >}}
---
{{< youtube cueOpK5QMEA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2492: Minimum Score of a Path Between Two Cities](https://grid47.xyz/leetcode/solution-2492-minimum-score-of-a-path-between-two-cities/) |
| --- |
