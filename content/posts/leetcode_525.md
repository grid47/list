
+++
authors = ["Crafted by Me"]
title = "Leetcode 525: Contiguous Array"
date = "2022-05-26"
description = "Solution to Leetcode 525"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/contiguous-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int n = nums.size();
        int score = 0, res = 0;
        map<int, int> mp;

        for(int i = 0; i < n; i++) {
            score += nums[i]? 1: -1;

            if(score == 0) res = i + 1;
            else {

                if(mp.count(score))
                res = max(res, i - mp[score]);

                if(!mp.count(score)) mp[score] = i;
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/525.md" >}}
---
{{< youtube 3dRoRxipjhY >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

