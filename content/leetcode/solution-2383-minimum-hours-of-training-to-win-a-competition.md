
+++
authors = ["grid47"]
title = "Leetcode 2383: Minimum Hours of Training to Win a Competition"
date = "2024-03-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2383: Minimum Hours of Training to Win a Competition in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "ueU_i8H3-9g"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/minimum-hours-of-training-to-win-a-competition/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minNumberOfHours(int ie, int ig, vector<int>& energy, vector<int>& experience) 
    {
        int hours = 0;
        for (int i = 0; i < energy.size(); i++)
        {
            if (energy[i] >= ie)
            {
                hours += energy[i] - ie + 1;
                ie += energy[i] - ie + 1;
            }
            if (experience[i] >= ig)
            {
                hours += experience[i] - ig + 1;
                ig += experience[i] - ig + 1;
            }
			// At the end increase the experience by experience[i] and decrease the energy by energy[i].
            ie -= energy[i];
            ig += experience[i];
        }
        return hours;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2383.md" >}}
---
{{< youtube ueU_i8H3-9g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2384: Largest Palindromic Number](https://grid47.xyz/leetcode/solution-2384-largest-palindromic-number/) |
| --- |
