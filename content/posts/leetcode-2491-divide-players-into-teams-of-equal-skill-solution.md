
+++
authors = ["grid47"]
title = "Leetcode 2491: Divide Players Into Teams of Equal Skill"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2491: Divide Players Into Teams of Equal Skill in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2492: Minimum Score of a Path Between Two Cities](https://grid47.xyz/posts/leetcode-2492-minimum-score-of-a-path-between-two-cities-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}