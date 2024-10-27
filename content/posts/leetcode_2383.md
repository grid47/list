
+++
authors = ["Yasir"]
title = "Leetcode 2383: Minimum Hours of Training to Win a Competition"
date = "2018-04-20"
description = "Solution to Leetcode 2383"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-hours-of-training-to-win-a-competition/description/)

---

**Code:**

{{< highlight html >}}
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

