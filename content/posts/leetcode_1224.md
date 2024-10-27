
+++
authors = ["Yasir"]
title = "Leetcode 1224: Maximum Equal Frequency"
date = "2021-06-22"
description = "Solution to Leetcode 1224"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-equal-frequency/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        
        map<int, int> frq, cnt;
        int mx = 0, res = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            
            int f =  ++cnt[nums[i]];
            frq[f - 1]--;
            frq[f]++;
            
            mx = max(mx, cnt[nums[i]]);
            
            if((mx * frq[mx] == i) || ((mx - 1) * (frq[mx - 1] + 1) == i) || (mx == 1))
                res = i + 1;
        }
        return res;
    }
};
{{< /highlight >}}

