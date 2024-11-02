
+++
authors = ["Crafted by Me"]
title = "Leetcode 553: Optimal Division"
date = "2023-04-29"
description = "Solution to Leetcode 553"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/optimal-division/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string s = "";
        if(nums.size() == 1) return to_string(nums[0]);
        if(nums.size() == 2) return to_string(nums[0]) + '/' + to_string(nums[1]);

        for(int i = 0; i < nums.size(); i++) {
            s += to_string(nums[i]) + "/";
            if(i == 0)
                s += "(";
        }
        s[s.size() -1] = ')';
        return s;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/553.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

