
+++
authors = ["Yasir"]
title = "Leetcode 525: Contiguous Array"
date = "2023-05-22"
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

{{< highlight html >}}
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

