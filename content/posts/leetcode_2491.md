
+++
authors = ["Yasir"]
title = "Leetcode 2491: Divide Players Into Teams of Equal Skill"
date = "2018-01-03"
description = "Solution to Leetcode 2491"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/)

---

**Code:**

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

