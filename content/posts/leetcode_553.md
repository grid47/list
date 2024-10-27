
+++
authors = ["Yasir"]
title = "Leetcode 553: Optimal Division"
date = "2023-04-24"
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

{{< highlight html >}}
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

